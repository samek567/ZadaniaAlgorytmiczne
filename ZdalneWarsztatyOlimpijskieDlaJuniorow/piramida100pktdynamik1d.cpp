#include <iostream>
#include <vector>

using namespace std;

int n = 0, mod = 0, sum = 0;
char znak;
vector<char> droga;
vector<int> dp;

int main()
{
    // O(n)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> mod;
    for (int i = 0; i < n; ++i)
    {
        cin >> znak;
        droga.push_back(znak);
    }
    dp.push_back(1);
    for (int i = 1; i < n; ++i)
    {
        if (droga[i] == '1')
        {
            sum = 0;
            for (int j = 1; j <= 6 && i - j >= 0; ++j)
            {
                sum = (sum + dp[i-j]) % mod;
            }
            dp.push_back(sum);
        }
        else
            dp.push_back(0);
    }
    printf("%d",dp[n-1]);
    return 0;
}