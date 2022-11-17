#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Element
{
    vector<int> stat;
    int idx;
    long long iloczyn;
    int ile_dzielnikow;
};

struct Element_vectora
{
    long long wartosc;
    long long ile_dzielnikow;

    bool operator < (const Element_vectora &element_vectora) const
    {
        return wartosc < element_vectora.wartosc;
    }
};

long long n = 0, max_n = 2 * 1e9 + 5, iloczyn_pocz = 1, max_dzielnik = 0;
queue<Element> Q;
vector<Element_vectora> kandydaci;
vector<long long> liczby_antypierwsze {1};
vector<long long> p {2,3,5,7,11,13,17,19,23};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector<int> wyst;
    for (int i = 0; i < p.size(); ++i)
    {
        wyst.push_back(0);
    }

    for(int i = 1; iloczyn_pocz < max_n; ++i)
    {
        iloczyn_pocz *= p[0];
        wyst[0] = i;
        Q.push({wyst,1,iloczyn_pocz,i+1});
        kandydaci.push_back({iloczyn_pocz,i+1});
    }

    while (!Q.empty())
    {
        Element spr = Q.front();
        if (spr.idx != p.size())
        {
            for (int i = 1; i <= spr.stat[spr.idx-1]; ++i)
            {
                long long il = spr.iloczyn * pow(p[spr.idx],i);
                if (il < max_n)
                {
                    Q.push({spr.stat,spr.idx+1,il,spr.ile_dzielnikow * (i+1)});
                    Q.back().stat[spr.idx] = i;
                    kandydaci.push_back({il,spr.ile_dzielnikow * (i+1)});
                }
                else
                {
                    break;
                }
            }
        }

        Q.pop();
    }

    sort(kandydaci.begin(),kandydaci.end());

    for (auto i : kandydaci)
    {
        if (i.ile_dzielnikow > max_dzielnik)
        {
            liczby_antypierwsze.push_back(i.wartosc);
            max_dzielnik = i.ile_dzielnikow;
        }
    }

    for (int i = liczby_antypierwsze.size()-1; i >= 0; --i)
    {
        if (liczby_antypierwsze[i] <= n)
        {
            cout << liczby_antypierwsze[i];
            return 0;
        }
    }

    return 0;
}
