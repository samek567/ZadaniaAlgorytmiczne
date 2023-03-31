#include <iostream>
#include <vector>

using namespace std;

int a = 0, b = 0, n = 50, ile_zostalo = 0;
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    dp.assign(n,{});
    for (int i = 0; i < 25; ++i)
        dp[i].assign(n,0);
    for (int i = 25; i < n; ++i)
        dp[i].assign(n,1);

    ile_zostalo = b-1;
    for (int i = 1; i < n and ile_zostalo > 0; i += 2)
    {
        for (int j = 1; j < n and ile_zostalo > 0; j += 2)
        {
            ile_zostalo--;
            dp[i][j] = 1;
        }
    }

    ile_zostalo = a-1;
    for (int i = 26; i < n and ile_zostalo > 0; i += 2)
    {
        for (int j = 1; j < n and ile_zostalo > 0; j += 2)
        {
            ile_zostalo--;
            dp[i][j] = 0;
        }
    }

    cout << n << ' ' << n << '\n';
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
