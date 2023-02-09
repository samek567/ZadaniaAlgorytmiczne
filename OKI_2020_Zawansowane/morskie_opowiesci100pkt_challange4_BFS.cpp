#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Element_kolejki
{
    int v;
    bool czy_parzyste;
};

struct Zapytanie
{
    int poczatek;
    int koniec;
    int d;
    int idx;
    bool operator < (const Zapytanie &zapytanie) const
    {
        return poczatek < zapytanie.poczatek;
    }
};

int n = 0, m = 0, k = 0, a_i = 0, b_i = 0, c_i, wartosc_sprawdzona = 0;
Element_kolejki spr = {-1,true};
vector<vector<int>> krawedzie;
vector<int> dystans_parzyste; // Dystans z wierzcholka wartosc_sprawdzona do kazdego(o idxie 1,2,3,4...)
vector<int> dystans_nie_parzyste; // Dystans z wierzcholka wartosc_sprawdzona do kazdego(o idxie 1,2,3,4...)
vector<Zapytanie> zapytania;
vector<bool> wyniki_zapytan;
queue<Element_kolejki> Q;

int main()
{
    // O(N^2 + M^2 + K lg K)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    wyniki_zapytan.assign(k,false);
    dystans_parzyste.assign(n+1,-1);
    dystans_nie_parzyste.assign(n+1,-1);
    krawedzie.assign(n+1,{});
    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        krawedzie[a_i].push_back(b_i);
        krawedzie[b_i].push_back(a_i);
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> a_i >> b_i >> c_i;
        zapytania.push_back({a_i,b_i,c_i, i});
    }
    sort(zapytania.begin(),zapytania.end());

    for (int i = 0; i < k; ++i)
    {
        if (zapytania[i].poczatek != wartosc_sprawdzona)
        {
            dystans_parzyste.assign(n+1,-1);
            dystans_nie_parzyste.assign(n+1,-1);
            wartosc_sprawdzona = zapytania[i].poczatek;
            while(!Q.empty())
                Q.pop();
            Q.push({zapytania[i].poczatek,true});
            while(!Q.empty())
            {
                spr = Q.front();
                for (int j = 0; j < krawedzie[spr.v].size(); ++j)
                {
                    if (spr.czy_parzyste == true)
                    {
                        if (dystans_nie_parzyste[krawedzie[spr.v][j]] == -1)
                        {
                            dystans_nie_parzyste[krawedzie[spr.v][j]] = dystans_parzyste[spr.v] + 1;
                            Q.push({krawedzie[spr.v][j],false});
                        }
                    }
                    else
                    {
                        if (dystans_parzyste[krawedzie[spr.v][j]] == -1)
                        {
                            dystans_parzyste[krawedzie[spr.v][j]] = dystans_nie_parzyste[spr.v] + 1;
                            Q.push({krawedzie[spr.v][j],true});
                        }
                    }
                }
                Q.pop();
            }
        }
        if (zapytania[i].d % 2 == 0)
        {
            if (dystans_parzyste[zapytania[i].koniec] != -1 && zapytania[i].d >= dystans_parzyste[zapytania[i].koniec])
                wyniki_zapytan[zapytania[i].idx] = true;
        }
        else
        {
            if (dystans_nie_parzyste[zapytania[i].koniec] != -1 && zapytania[i].d >= dystans_nie_parzyste[zapytania[i].koniec])
                wyniki_zapytan[zapytania[i].idx] = true;
        }
    }

    for (int i = 0; i < k; ++i)
    {
        if (wyniki_zapytan[i] == true)
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }

    return 0;
}