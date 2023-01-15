#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, a = 0, b = 0;
vector<int> stat_ile_wystapien(1e6+1,0);
vector<vector<int>> stat;
vector<int> wyn;
vector<pair<int,int>> kafelki;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    wyn.assign(m,0);
    stat.assign(1e6+1,{});
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        stat_ile_wystapien[wczytana_liczba]++;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        kafelki.push_back({a,b});
        stat[a].push_back(i);
    }

    for (int i = 1; i <= 1e6; ++i)
    {
        if (stat_ile_wystapien[i] == 0)
            continue;
        for (int j = i; j <= 1e6; j += i)
        {
            for (int k = 0; k < stat[j].size(); ++k)
            {
                if (kafelki[stat[j][k]].second % i == 0)
                    wyn[stat[j][k]] += stat_ile_wystapien[i];
            }
        }
    }
    for (int i = 0; i < m; ++i)
        printf("%d\n",wyn[i]);
    
    return 0;
}
