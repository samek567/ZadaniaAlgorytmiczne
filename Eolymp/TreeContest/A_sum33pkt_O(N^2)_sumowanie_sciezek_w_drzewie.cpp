#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, a = 0, b = 0, c = 0, mod = 1e9;
ll wyn = 0;
vector<vector<pair<int,int>>> krawedzie;

inline void DFS(int v, ll sum, int parent)
{
    wyn = wyn + sum;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i].first;
        if (wierz == parent)
            continue;
        DFS(wierz,sum + krawedzie[v][i].second,v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    krawedzie.assign(n+1,{});
    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b >> c;
        krawedzie[a].push_back({b,c});
        krawedzie[b].push_back({a,c});
    }

    for (int i = 1; i <= n; ++i)
        DFS(i,0,-1);

    cout << (wyn / (ll)2) % (ll)mod << '\n';

    return 0;
}