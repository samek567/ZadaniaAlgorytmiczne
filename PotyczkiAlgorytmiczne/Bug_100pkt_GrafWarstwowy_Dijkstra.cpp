#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Element_seta
{
    int wartosc;
    int wierzcholek;
    bool czy_parzysta;
    bool operator < (const Element_seta &element_seta) const
    {
        if (wartosc == element_seta.wartosc)
        {
            if (wierzcholek == element_seta.wierzcholek)
                return czy_parzysta < element_seta.czy_parzysta;
            return wierzcholek < element_seta.wierzcholek;
        }
        return wartosc < element_seta.wartosc;
    }
};

struct Krawedz
{
    int wierzcholek;
    int wartosc;
};

int n = 0, m = 0, a = 0, b = 0, c = 0, INF = 1e9+20;
vector<vector<Krawedz>> krawedzie;
set<Element_seta> S;
vector<int> dp_parzyste;
vector<int> dp_nieparzyste;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    krawedzie.assign(n+1,{});
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        krawedzie[a].push_back({b,c});
        krawedzie[b].push_back({a,c});
    }

    dp_parzyste.assign(n+1,INF);
    dp_nieparzyste.assign(n+1,INF);

    dp_parzyste[1] = 0;
    S.insert({0,1,true});
    while(!S.empty())
    {
        Element_seta spr = *S.begin();
        S.erase(spr);
        if (spr.wierzcholek == n and spr.czy_parzysta == false)
        {
            cout << spr.wartosc << '\n';
            return 0;
        }
        for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
        {
            int wierz = krawedzie[spr.wierzcholek][i].wierzcholek, sum = spr.wartosc + krawedzie[spr.wierzcholek][i].wartosc;
            if (sum % 2 == 0)
            {
                if (sum < dp_parzyste[wierz])
                {
                    auto it = S.find({dp_parzyste[wierz],wierz,true});
                    if (it != S.end())
                        S.erase(*it);
                    dp_parzyste[wierz] = sum;
                    S.insert({sum,wierz,true});
                }
            }
            else
            {
                if (sum < dp_nieparzyste[wierz])
                {
                    auto it = S.find({dp_nieparzyste[wierz],wierz,false});
                    if (it != S.end())
                        S.erase(*it);
                    dp_nieparzyste[wierz] = sum;
                    S.insert({sum,wierz,false});
                }
            }
        }
    }

    cout << "0" << '\n';

    return 0;
}