#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 0, m = 0, delta_SIZE = 8;
char wczytany_znak;
int dp[1000][1000];
queue<pair<int,int>> Q;
vector<int> delta_Y = {-2,-2,2,2,-1,-1,1,1};
vector<int> delta_X = {-1,1,-1,1,-2,2,-2,2};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> wczytany_znak;
            if (wczytany_znak == '.')
                dp[i][j] = -1; // wolne pole
            else if (wczytany_znak == 'n')
                dp[i][j] = -2; // cel
            else if (wczytany_znak == 'x')
                dp[i][j] = -3; // nie wolno isc
            else if (wczytany_znak == 'z')
            {
                dp[i][j] = 0; // Gdzie jest Bajtek
                Q.push({i,j});
            }
        }
    }

    while(!Q.empty())
    {
        pair<int,int> spr = Q.front();
        Q.pop();
        for (int i = 0; i < delta_SIZE; ++i)
        {
            if (spr.first + delta_Y[i] >= 0 && spr.first + delta_Y[i] < n && spr.second + delta_X[i] >= 0 && spr.second + delta_X[i] < m)
            {
                if (dp[spr.first + delta_Y[i]][spr.second + delta_X[i]] == -2)
                {
                    cout << dp[spr.first][spr.second] + 1 << '\n';
                    return 0;
                }
                else if (dp[spr.first + delta_Y[i]][spr.second + delta_X[i]] == -1)
                {
                    dp[spr.first + delta_Y[i]][spr.second + delta_X[i]] = dp[spr.first][spr.second] + 1;
                    Q.push({spr.first + delta_Y[i], spr.second + delta_X[i]});
                }
            }
        }
    }

    cout << "NIE" << '\n';

    return 0;
}