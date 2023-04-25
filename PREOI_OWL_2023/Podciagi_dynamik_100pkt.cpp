#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, mod = 1e9+7, wyn = 0;
vector<int> A;
vector<int> val;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);

    cin >> n;

    A.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    val.assign(1e6+1,0);

    dp.assign(n,-1);
    dp[n-1] = 2;
    val[A[n-1]] = 1;

    for (int i = n-2; i >= 0; --i)
    {
        dp[i] = ( (ll)dp[i+1] * (ll)2 - (ll)val[A[i]] ) % (ll)mod;
        val[A[i]] = dp[i+1];
    }

    cout << dp[0] << '\n';

    return 0;
}