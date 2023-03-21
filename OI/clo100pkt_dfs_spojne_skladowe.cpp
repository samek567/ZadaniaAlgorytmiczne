#include <iostream>
#include <vector>

using namespace std;

struct Krawedz_wejscie
{
    int a;
    int b;
    bool czy_usuwamy;
};

struct Krawedz
{
    int wierzcholek;
    int numer_krawedzi;
};

int n = 0, m = 0, a = 0, b = 0, korzen = -1, krawedz_dodatkowa = 0, ile_spojnych = 0;
vector<vector<Krawedz>> krawedzie;
vector<Krawedz_wejscie> krawedzie_wejscie;
vector<bool> czy_bylismy;
vector<int> wyn_vect;
vector<int> jaki_wierzcholek_w_spojnej;
vector<int> wyniki_korzen;
vector<int> wyniki_krawedz_dodatkowa;

void DFS(int v, int parent)
{
    czy_bylismy[v] = true;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i].wierzcholek;
        if (wierz == parent)
            continue;
        if (czy_bylismy[wierz] == true)
        {
            krawedzie_wejscie[krawedzie[v][i].numer_krawedzi].czy_usuwamy = true;
            korzen = wierz;
            krawedz_dodatkowa = krawedzie[v][i].numer_krawedzi;
        }
        else
            DFS(wierz,v);
    }
}

void DFS_odtwarzanie(int v)
{
    czy_bylismy[v] = true;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i].wierzcholek;
        if (czy_bylismy[wierz] == true)
            continue;
        if (krawedzie_wejscie[krawedzie[v][i].numer_krawedzi].czy_usuwamy == true)
            continue;
        wyn_vect[wierz] = v;
        DFS_odtwarzanie(wierz);
    }
}

void DFS_spojne(int v)
{
    czy_bylismy[v] = true;
    jaki_wierzcholek_w_spojnej[ile_spojnych] = v;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i].wierzcholek;
        if (czy_bylismy[wierz] == false)
            DFS_spojne(wierz);
    }
}

int main()
{
    // O(N+M), spojne skladowe + DFS(mozna oczywiscie BFS zamiast DFS)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    krawedzie.assign(n+1,{});
    krawedzie_wejscie.assign(m,{-1,-1,false});
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        krawedzie_wejscie[i] = {a,b,false};
        krawedzie[a].push_back({b,i});
        krawedzie[b].push_back({a,i});
    }

    czy_bylismy.assign(n+1,false);
    for (int i = 1; i <= n; ++i)
    {
        if (czy_bylismy[i] == false)
        {
            jaki_wierzcholek_w_spojnej.push_back(-1);
            DFS_spojne(i);
            ++ile_spojnych;
        }
    }

    fill(czy_bylismy.begin(),czy_bylismy.end(),false);
    for (int i = 0; i < ile_spojnych; ++i)
    {
        korzen = -1;
        DFS(jaki_wierzcholek_w_spojnej[i],-1);
        if (korzen == -1)
        {
            cout << "NIE" << '\n';
            return 0;
        }
        wyniki_korzen.push_back(korzen);
        wyniki_krawedz_dodatkowa.push_back(krawedz_dodatkowa);
    }

    cout << "TAK" << '\n';
    fill(czy_bylismy.begin(),czy_bylismy.end(),false);
    wyn_vect.assign(n+1,-1);

    for (int i = 0; i < ile_spojnych; ++i)
    {
        korzen = wyniki_korzen[i], krawedz_dodatkowa = wyniki_krawedz_dodatkowa[i];
        if (krawedzie_wejscie[krawedz_dodatkowa].a == korzen)
            wyn_vect[korzen] = krawedzie_wejscie[krawedz_dodatkowa].b;
        else
            wyn_vect[korzen] = krawedzie_wejscie[krawedz_dodatkowa].a;
        DFS_odtwarzanie(korzen);
    }

    for (int i = 1; i <= n; ++i)
        cout << wyn_vect[i] << ' ';

    return 0;
}
