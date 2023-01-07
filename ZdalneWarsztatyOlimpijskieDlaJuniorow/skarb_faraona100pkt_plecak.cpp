#include <iostream>
#include <vector>

using namespace std;

int n = 0, b = 0, a_i = 0, b_i = 0;
vector<long long> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b;
    dp.assign(b+1,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a_i >> b_i;
        for (int j = b; j >= 0; --j)
        {
            if (j + a_i <= b)
                dp[j+a_i] = max(dp[j+a_i],dp[j] + b_i);
        }
    }
    printf("%lld",dp[b]);
    return 0;