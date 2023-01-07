#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ciag1, ciag2;

    cin >> ciag1 >> ciag2;

    int dp[ciag1.size()+1][ciag2.size()+1];
    for (int i = 0; i <= ciag1.size(); ++i)
    {
        for (int j = 0; j <= ciag2.size(); ++j)
            dp[i][j] = 0;
    }

    for (int i = 1; i <= ciag1.size(); ++i)
    {
        for (int j = 1; j <= ciag2.size(); ++j)
        {
            if (ciag1[i-1] == ciag2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    printf("%d",dp[ciag1.size()][ciag2.size()]);


    return 0;
}