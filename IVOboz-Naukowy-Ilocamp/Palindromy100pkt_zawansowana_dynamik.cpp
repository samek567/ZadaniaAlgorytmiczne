#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, ile_odjecie = 97, a_i = 0, b_i = 0, l = 0, p = 0;
string ciag;
char wczytany_znak;
vector<int> stat(1e3,1e9);
vector<vector<int>> dp;

int main()
{
    // O(n^2) dynamik. dp[i][j] - min koszt, zeby spojny podciag i,i+1,i+2... j byl palindromem.
    // Zauwazmy, ze zawsze oplaca nam sie wykonywac mina z usuniecia i dodania litery x, bo mozemy albo usunac, albo symetrycznie dodac.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> ciag;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak >> a_i >> b_i;
        stat[wczytany_znak-ile_odjecie] = min(a_i,b_i);
    }
    for (int i = 0; i < m; ++i)
    {
        dp.push_back({});
        for (int j = 0; j < m; ++j)
            dp[i].push_back(0);
    }
    for (int i = 0; i < m; ++i)
        dp[i][i] = 0;
    for (int i = 0; i < m-1; ++i)
        if (ciag[i] != ciag[i+1])
            dp[i][i+1] = min(stat[(int)ciag[i] - ile_odjecie],stat[(int)ciag[i+1] - ile_odjecie]);
    for (int i = 3; i <= m; ++i)
    {
        for (int j = 0; j <= m - i; ++j)
        {
            l = j, p = j+i-1;
            if (ciag[l] == ciag[p])
                dp[l][p] = dp[l+1][p-1];
            else
                dp[l][p] = min(dp[l][p-1] + stat[(int)ciag[p] - ile_odjecie], dp[l+1][p] + stat[(int)ciag[l] - ile_odjecie]);
        }
    }
    printf("%d",dp[0][m-1]);
    return 0;
}
