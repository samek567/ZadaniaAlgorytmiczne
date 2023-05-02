#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, max_A = 0, max_B = 0, max_C = 0;
ll INF = 1e18+20;
vector<int> A;
vector<int> B;
vector<int> C;
vector<int> min_sum;
vector<vector<ll>> dp;

int main()
{
    // O(N * 2^3), dp[i][mask] - min wynik sprawdzajac elementy od 0 do i, gdzie elementy wziete tworza taka maske bitowa.
    // https://forum.pasja-informatyki.pl/584389/zadanie-cukiernia-xxviii-oi
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    A.assign(n,-1);
    B.assign(n,-1);
    C.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> A[i] >> B[i] >> C[i];

    for (int i = 0; i < n; ++i)
    {
        max_A = max(max_A,A[i]), max_B = max(max_B,B[i]), max_C = max(max_C,C[i]);
    }

    min_sum.assign(n,-1);
    for (int i = 0; i < n; ++i)
        min_sum[i] = min(A[i] + B[i], min(A[i] + C[i], B[i] + C[i]));

    dp.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp[i].assign(8,INF);

    dp[0][0] = min_sum[0];
    dp[0][1] = A[0] + B[0];
    dp[0][2] = A[0] + C[0];
    dp[0][4] = B[0] + C[0];

    for (int i = 0; i < n-1; ++i)
    {
        for (int j = 0; j < 8; ++j)
            dp[i+1][j] = dp[i][j] + min_sum[i+1];
        for (int j = 0; j < 8; ++j)
        {
            int b = (4 & j);
            if (b == 0)
            {
                int mask = j + 4;
                dp[i+1][mask] = min(dp[i+1][mask],dp[i][j] + B[i+1] + C[i+1]);
            }
            b = (2 & j);
            if (b == 0)
            {
                int mask = j + 2;
                dp[i+1][mask] = min(dp[i+1][mask],dp[i][j] + A[i+1] + C[i+1]);
            }
            b = (1 & j);
            if (b == 0)
            {
                int mask = j + 1;
                dp[i+1][mask] = min(dp[i+1][mask],dp[i][j] + A[i+1] + B[i+1]);
            }
        }
    }

    int sum = 0;
    if (max_A > 0)
        sum += 4;
    if (max_B > 0)
        sum += 2;
    if (max_C > 0)
        sum++;

    cout << dp[n-1][sum] << '\n';

    return 0;
}
