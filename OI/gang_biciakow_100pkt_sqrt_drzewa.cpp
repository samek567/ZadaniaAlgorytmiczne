#include <iostream>
#include <vector>

using namespace std;

struct Krawedz
{
    int wierzcholek;
    int idx_krawedzi;
};

struct Zapytanie
{
    int a;
    int b;
    int jaki_kolor;
};

int n = 0, m = 0, q = 0, a = 0, b = 0, c = 0, cnt = 0, k = 317;
char wczytany_znak;
vector<Zapytanie> zapytania;
vector<vector<Krawedz>> krawedzie;
vector<int> parent;
vector<int> ile_w_poddrzewie;
vector<int> najdluzsza_sciezka_w_podddrzewie;
vector<bool> czy_ciezki;
vector<vector<int>> jakie_biciaki;
vector<int> ile_biciakow;
vector<int> glebokosc;
vector<int> jaki_nr_post_order;
vector<int> idx_zapytania_parent;
vector<int> numery_wierzchokow_ciezkich;

inline void DFS (int v, int par, int gleb)
{
    parent[v] = par;
    glebokosc[v] = gleb;
    jaki_nr_post_order[v] = ++cnt;
    najdluzsza_sciezka_w_podddrzewie[v] = 1;
    ile_w_poddrzewie[v] = 1;
    int najdluzsza_sciezka = 0;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i].wierzcholek;
        if (wierz == par)
            continue;
        DFS(wierz,v,gleb+1);
        idx_zapytania_parent[wierz] = krawedzie[v][i].idx_krawedzi;
        ile_w_poddrzewie[v] += ile_w_poddrzewie[wierz];
    }
    najdluzsza_sciezka_w_podddrzewie[v] += najdluzsza_sciezka;
}

inline void napelniaj_ciezkie()
{
    for (int i = 1; i <= n; ++i)
    {
        if (czy_ciezki[i] == true)
        {
            jakie_biciaki[i].assign(m+1,0);
            int v = i;
            while(v > 1)
            {
                int kolor = zapytania[idx_zapytania_parent[v]].jaki_kolor;
                jakie_biciaki[i][kolor]++;
                if (jakie_biciaki[i][kolor] == 1)
                    ile_biciakow[i]++;
                v = parent[v];
            }
        }
    }
}

inline void update()
{
    int idx_krawedzi, numer_nowego_biciaka, akt_kolor = -1, ojciec = -1, syn = -1;
    cin >> idx_krawedzi >> numer_nowego_biciaka;
    idx_krawedzi--;
    ojciec = zapytania[idx_krawedzi].a, syn = zapytania[idx_krawedzi].b, akt_kolor = zapytania[idx_krawedzi].jaki_kolor;
    if (jaki_nr_post_order[ojciec] > jaki_nr_post_order[syn])
        swap(ojciec,syn);
    for (int i = 0; i < numery_wierzchokow_ciezkich.size(); ++i)
    {
        int v = numery_wierzchokow_ciezkich[i];
        if (jaki_nr_post_order[v] >= jaki_nr_post_order[syn] and jaki_nr_post_order[v] <= jaki_nr_post_order[syn] + ile_w_poddrzewie[syn] - 1) // Czy w poddrzewie, gdzie zmieni update na sciezce
        {
            jakie_biciaki[v][akt_kolor]--;
            if (jakie_biciaki[v][akt_kolor] == 0)
                ile_biciakow[v]--;
            jakie_biciaki[v][numer_nowego_biciaka]++;
            if (jakie_biciaki[v][numer_nowego_biciaka] == 1)
                ile_biciakow[v]++;
        }
    }
    zapytania[idx_krawedzi].jaki_kolor = numer_nowego_biciaka;
}

inline int query()
{
    int v = 0, res = 0;
    vector<int> kolory_na_trasie;
    cin >> v;
    while (czy_ciezki[v] == false)
    {
        kolory_na_trasie.push_back(zapytania[idx_zapytania_parent[v]].jaki_kolor);
        v = parent[v];
    }
    res = ile_biciakow[v];
    for (int i = 0; i < kolory_na_trasie.size(); ++i)
    {
        int kol = kolory_na_trasie[i];
        jakie_biciaki[v][kol]++;
        if (jakie_biciaki[v][kol] == 1)
            res++;
    }
    for (int i = 0; i < kolory_na_trasie.size(); ++i)
    {
        int kol = kolory_na_trasie[i];
        jakie_biciaki[v][kol]--;

    }
    return res;
}

int main()
{
    /* Nazwijmy wierzchołek ciężkim, gdy jego głębokość jest podzielna przez K,
       K = sqrt oraz, w którym najdłuższa ścieżka w pod drzewie ukorzenionym w tym wierzchołku zaczynająca się w nim >= K.
       Dla każdego wierzchołka trzymamy tablice jakie kolory mamy na ścieżce od niego do jedynki.
       I napełniamy ją w czasie O(N * K) na początku.
       Potem jak dostajemy query, to idziemy do góry aż natkniemy sie na pierwszy ciężki wierzchołek.
       A jak robimy updata, to przechodzimy się po wszystkich wierzchołkach ciężkich i sprawdzamy,
       czy podana krawędź jest na drodze pomiędzy danym wierzchołkiem a jedynka, jak jest to aktualizujemy. O(N*K + Q*K).
    */
    /* Mozna tez algorytm Mo z updatami, ale on jest o wiele trudniejszy niz to*/
    /* https://forum.pasja-informatyki.pl/578295/gang-biciakow-oi?show=578295#q578295 */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;

    krawedzie.assign(n+1,{});
    zapytania.assign(n-1,{});
    parent.assign(n+1,-1);
    ile_w_poddrzewie.assign(n+1,-1);
    najdluzsza_sciezka_w_podddrzewie.assign(n+1,-1);
    czy_ciezki.assign(n+1,false);
    jakie_biciaki.assign(n+1,{});
    ile_biciakow.assign(n+1,0);
    jaki_nr_post_order.assign(n+1,-1);
    glebokosc.assign(n+1,-1);
    idx_zapytania_parent.assign(n+1,-1);

    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b >> c;
        zapytania[i] = {a,b,c};
        krawedzie[a].push_back({b,i});
        krawedzie[b].push_back({a,i});
    }

    DFS(1,0,0);

    czy_ciezki[1] = true;
    for (int i = 2; i <= n; ++i)
        if (glebokosc[i] % k == 0 and ile_w_poddrzewie[i] >= k)
            czy_ciezki[i] = true;

    for (int i = 1; i <= n; ++i)
        if (czy_ciezki[i] == true)
            numery_wierzchokow_ciezkich.push_back(i);

    napelniaj_ciezkie();

    while(q--)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'Z')
            cout << query() << '\n';
        else
            update();
    }

    return 0;
}
