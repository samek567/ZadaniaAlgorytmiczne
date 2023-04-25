#include <iostream>
#include <vector>

using namespace std;
typedef long double ld;

int n = 0, m = 0, a = 0, b = 0;
vector<int> krawedz_lewa;
vector<int> krawedz_prawa;
vector<ld> dp;

inline void DFS(int v, ld val)
{
    dp[v] = val;
    if (krawedz_lewa[v] != -1)
        DFS(krawedz_lewa[v], val * 2);
    if (krawedz_prawa[v] != -1)
        DFS(krawedz_prawa[v], val * 2 + 1);
}

int main()
{
    // Brucik.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    dp.assign(n+1,-1);
    krawedz_lewa.assign(n+1,-1);
    krawedz_prawa.assign(n+1,-1);
    for (int i = 1; i <= n; ++i)
        cin >> krawedz_lewa[i] >> krawedz_prawa[i];

    DFS(1,0);

    cin >> m;
    while(m--)
    {
        cin >> a >> b;
        if (dp[a] >= dp[b])
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }

    return 0;
}