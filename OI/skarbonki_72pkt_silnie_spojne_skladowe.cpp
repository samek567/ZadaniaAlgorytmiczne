#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n = 0, wczytana_liczba = 0;
vector<bool> czy_odwiedzony;
vector<int> krawedzie;
vector<int> kolejnosc_post_order;
vector<vector<int>> odwrocone_krawedzie;
vector<int> do_jakiej_SCC_nalezy;
vector<vector<int>> SCC;
vector<unordered_set<int>> SCC_krawedzie;

void DFS(int x)
{
    czy_odwiedzony[x] = true;
    if (czy_odwiedzony[krawedzie[x]] == false)
        DFS(krawedzie[x]);
    kolejnosc_post_order.push_back(x);
}

void SCC_podzial(int x)
{
    czy_odwiedzony[x] = true;
    do_jakiej_SCC_nalezy[x] = SCC.size();
    SCC[SCC.size()-1].push_back(x);
    for (int i = 0; i < odwrocone_krawedzie[x].size(); ++i)
    {
        if (czy_odwiedzony[odwrocone_krawedzie[x][i]] == false)
            SCC_podzial(odwrocone_krawedzie[x][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    krawedzie.assign(n+1, false);
    czy_odwiedzony.assign(n+1, false);
    do_jakiej_SCC_nalezy.assign(n+1,-1);
    odwrocone_krawedzie.assign(n+1,{});
    SCC_krawedzie.assign(n+1,{});

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        krawedzie[i+1] = wczytana_liczba;
        odwrocone_krawedzie[wczytana_liczba].push_back(i+1);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (czy_odwiedzony[i] == false)
            DFS(i);
    }

    fill(czy_odwiedzony.begin(),czy_odwiedzony.end(),false);
    for (int i = n-1; i >= 0; --i)
    {
        if (czy_odwiedzony[kolejnosc_post_order[i]] == false)
        {
            SCC.push_back({});
            SCC_podzial(kolejnosc_post_order[i]);
        }
    }

    for (int i = 0; i < SCC.size(); ++i)
    {
        for (int j = 0; j < SCC[i].size(); ++j)
        {
            if (do_jakiej_SCC_nalezy[SCC[i][j]] != do_jakiej_SCC_nalezy[krawedzie[SCC[i][j]]])
                SCC_krawedzie[i].insert(krawedzie[SCC[i][j]]);
        }
    }

    int sum = 0;
    for (int i = 0; i < SCC_krawedzie.size(); ++i)
    {
        sum += SCC_krawedzie[i].size();
    }
    printf("%d",SCC.size()-sum);

    return 0;
}