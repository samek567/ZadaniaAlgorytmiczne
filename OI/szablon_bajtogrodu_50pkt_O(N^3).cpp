#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

int n = 0, a = 0, b = 0;
char wczytany_znak;
vector<vector<pair<int,char>>> krawedzie;
unordered_map<string,set<pair<int,int>>> stat;
vector<bool> czy_bylismy;
vector<string> wyn;

void DFS(int v, string napis, vector<int> wierzcholki)
{
    czy_bylismy[v] = true;
    wierzcholki.push_back(v);
    if (!napis.empty())
    {
        if (auto it = stat.find(napis) == stat.end())
            stat.insert({napis,{}});
        for (int i = 1; i < wierzcholki.size(); ++i)
        {
            stat[napis].insert({wierzcholki[i],wierzcholki[i-1]});
            stat[napis].insert({wierzcholki[i-1],wierzcholki[i]});
        }
    }
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        if (czy_bylismy[krawedzie[v][i].first] == false)
        {
            string spr = napis;
            spr.push_back(krawedzie[v][i].second);
            DFS(krawedzie[v][i].first, spr, wierzcholki);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    krawedzie.assign(n+1,{});
    czy_bylismy.assign(n+1,false);

    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b >> wczytany_znak;
        krawedzie[a].push_back({b,wczytany_znak});
        krawedzie[b].push_back({a,wczytany_znak});
    }

    for (int i = 1; i <= n; ++i)
    {
        fill(czy_bylismy.begin(),czy_bylismy.end(),false);
        DFS(i,"",{});
    }

    for (auto it = stat.begin(); it != stat.end(); ++it)
    {
        if (it->second.size() == 2 * (n-1))
            wyn.push_back(it->first);
    }
    sort(wyn.begin(),wyn.end());
    cout << wyn.size() << '\n';
    for (int i = 0; i < wyn.size(); ++i)
        cout << wyn[i] << '\n';

    return 0;
}