#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Krawedz_wejscie
{
    int w1;
    int w2;
    int cena;
    bool operator < (const Krawedz_wejscie &krawedz_wejscie) const
    {
        return cena < krawedz_wejscie.cena;
    }
};

int n = 0, m = 0, k = 0, a = 0, b = 0, c = 0;
ll wyn = 0;
vector<Krawedz_wejscie> krawedzie_wejscie;
vector<bool> czy_jest_ciezarowka;
vector<bool> czy_jest_miasto;
vector<int> rep;
vector<int> ile_ciezarowek;
vector<int> ile_miast;

inline int findd(int x)
{
    int res = 0, parent = 0, v = x;
    while(true)
    {
        if (rep[v] == v)
        {
            res = v;
            break;
        }
        v = rep[v];
    }
    v = x;
    while(true)
    {
        if (rep[v] == v)
            break;
        int parent = rep[v];
        rep[v] = res;
        v = parent;
    }
    return res;
}

inline void unionn(int x, int y)
{
    int w1 = findd(x), w2 = findd(y);
    rep[w2] = w1;
    ile_miast[w1] += ile_miast[w2];
    ile_ciezarowek[w1] += ile_ciezarowek[w2];
}

int main()
{
    // O(N lg N), find and union.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    czy_jest_ciezarowka.assign(n+1,false);
    czy_jest_miasto.assign(n+1,false);

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        krawedzie_wejscie.push_back({a,b,c});
    }
    sort(krawedzie_wejscie.begin(), krawedzie_wejscie.end());

    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> a;
        czy_jest_ciezarowka[a] = true;
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> a;
        czy_jest_miasto[a] = true;
    }

    for (int i = 0; i <= n; ++i)
    {
        rep.push_back(i);
        if (czy_jest_ciezarowka[i] == true)
            ile_ciezarowek.push_back(1);
        else
            ile_ciezarowek.push_back(0);
        if (czy_jest_miasto[i] == true)
            ile_miast.push_back(1);
        else
            ile_miast.push_back(0);
    }

    for (int i = 0; i < m; ++i)
    {
        int wierz1 = krawedzie_wejscie[i].w1, wierz2 = krawedzie_wejscie[i].w2, ile_ciezarowek_w_spojnej = 0, ile_miast_w_spojnej = 0, ile_dajemy = 0;
        if (findd(wierz1) != findd(wierz2))
        {
            unionn(wierz1, wierz2);
            ile_ciezarowek_w_spojnej = ile_ciezarowek[findd(wierz1)];
            ile_miast_w_spojnej = ile_miast[findd(wierz1)];
            ile_dajemy = min(ile_ciezarowek_w_spojnej, ile_miast_w_spojnej);
            ile_ciezarowek[findd(wierz1)] -= ile_dajemy;
            ile_miast[findd(wierz1)] -= ile_dajemy;
            wyn += (ll)ile_dajemy * (ll)krawedzie_wejscie[i].cena;
        }
    }

    cout << wyn << '\n';

    return 0;
}