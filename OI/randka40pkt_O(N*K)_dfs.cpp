#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, a = 0, b = 0, wyn_A = 1e6, wyn_B = 1e6;
vector<int> krawedz;
vector<int> dp_A;
vector<int> dp_B;

inline void DFS_A(int v, int val)
{
    dp_A[v] = val;
    if (dp_A[krawedz[v]] == -1)
        DFS_A(krawedz[v], val+1);
}

inline void DFS_B(int v, int val)
{
    dp_B[v] = val;
    if (dp_A[v] != -1)
    {
        if (max(dp_A[v],dp_B[v]) < max(wyn_A, wyn_B))
        {
            wyn_A = dp_A[v], wyn_B = dp_B[v];
        }
        else if (max(dp_A[v],dp_B[v]) == max(wyn_A, wyn_B) and min(dp_A[v],dp_B[v]) < min(wyn_A, wyn_B))
        {
            wyn_A = dp_A[v], wyn_B = dp_B[v];
        }
    }
    if (dp_B[krawedz[v]] == -1)
        DFS_B(krawedz[v], val+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    krawedz.assign(n+1,-1);
    for (int i = 1; i <= n; ++i)
        cin >> krawedz[i];
    dp_A.assign(n+1,-1);
    dp_B.assign(n+1,-1);

    while(k--)
    {
        cin >> a >> b;
        fill(dp_A.begin(), dp_A.end(),-1);
        fill(dp_B.begin(), dp_B.end(),-1);
        wyn_A = 1e6, wyn_B = 1e6;
        DFS_A(a,0);
        DFS_B(b,0);
        if (wyn_A == 1e6)
            cout << "-1 -1" << '\n';
        else
            cout << wyn_A << ' ' << wyn_B << '\n';
    }

    return 0;
}