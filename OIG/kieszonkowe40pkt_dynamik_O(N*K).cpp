#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, wczytana_liczba = 0, maxx = 0;
vector<int> A;
vector<int> B;
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    A.assign(n,0);
    B.assign(n,0);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < n; ++i)
        cin >> B[i];


    // W dp uwzgledniamy ze k >= 2, bo dynamika inicjalizujemy przynajmniej 2.
    if (k == 1)
    {
        for (int i = 0; i < n; ++i)
            maxx = max(maxx, A[i]);
        cout << maxx << '\n';
        return 0;
    }

    dp.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp[i].assign(k+1,0);

    dp[0][1] = A[0];
    dp[0][2] = A[0] + B[0];
    for (int i = 1; i < n; ++i)
    {
        dp[i][1] = max(dp[i-1][1], A[i]);
        dp[i][2] = max(dp[i-1][2], max(dp[i-1][1] + A[i], A[i] + B[i]));
        for (int j = 3; j <= k; ++j)
            dp[i][j] = max(dp[i-1][j], max(dp[i-1][j-1] + A[i], dp[i-1][j-2] + A[i] + B[i]));
    }

    cout << dp[n-1][k] << '\n';

    return 0;
}