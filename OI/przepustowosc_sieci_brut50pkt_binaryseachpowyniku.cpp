#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Krawedz
{
    int a;
    int b;
    int cena;
    bool operator < (const Krawedz &krawedz) const
    {
        return cena > krawedz.cena;
    }
};

int n = 0, q = 0, ile = 0, p1 = 0, p2 = 0, c1 = 0, poczatek = 0, koniec = 0, srodek = 0;
vector<Krawedz> krawedzie;
vector<vector<int>> kraw;
vector<bool> czy_bylismy;
queue<int> Q;

inline bool czy_pasuje(int x)
{
    kraw.assign(n+1,{});
    czy_bylismy.assign(n+1,false);
    while(!Q.empty())
        Q.pop();
    for (int i = 0; i <= x; ++i)
        kraw[krawedzie[i].a].push_back(krawedzie[i].b);
    if (p1 == p2)
        return true;
    czy_bylismy[p1] = true;
    Q.push(p1);
    while(!Q.empty())
    {
        int spr = Q.front();
        Q.pop();
        for (int i = 0; i < kraw[spr].size(); ++i)
        {
            int wierz = kraw[spr][i];
            if (wierz == p2)
                return true;
            if (czy_bylismy[wierz] == false)
            {
                czy_bylismy[wierz] = true;
                Q.push(wierz);
            }
        }
    }
    return false;
}

int main()
{
    // 50pkt, binary search po wyniku dla kazdej pary.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> ile;
        while (ile--)
        {
            cin >> p1 >> c1;
            krawedzie.push_back({i,p1,c1});
        }
    }

    sort(krawedzie.begin(), krawedzie.end());

    cin >> q;
    while(q--)
    {
        cin >> p1 >> p2;
        poczatek = -1, koniec = krawedzie.size()+1;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (czy_pasuje(srodek) == true)
                koniec = srodek;
            else
                poczatek = srodek;
        }
        if (koniec == krawedzie.size()+1)
            cout << "0" << '\n';
        else
            cout << krawedzie[koniec].cena << '\n';
    }

    return 0;
}
