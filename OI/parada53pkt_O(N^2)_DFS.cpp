#include <iostream>
#include <vector>

using namespace std;

int n = 0, a = 0, b = 0, wyn = 0;
vector<vector<int>> krawedzie;

inline void DFS(int v, int parent, int val)
{
    if (parent != -1)
        wyn = max(wyn, val);
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i];
        if (wierz == parent)
            continue;
        DFS(wierz,v,val - 1 + krawedzie[wierz].size() - 1);
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
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
        DFS(i,-1,krawedzie[i].size());

    cout << wyn << '\n';

    return 0;
}