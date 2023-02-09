#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pole
{
    int y;
    int x;
};

int n = 0, m = 0, delta_SIZE = 4;
char wczytany_znak;
vector<vector<int>> dp;
vector<int> delta_Y = {-1,1,0,0};
vector<int> delta_X = {0,0,1,-1};
queue<Pole> Q;

int main()
{
    // O(N*M), BFS rownolegly
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        dp.push_back({});
        for (int j = 0; j < m; ++j)
        {
            cin >> wczytany_znak;
            if (wczytany_znak == '1')
            {
                dp[i].push_back(0);
                Q.push({i,j});
            }
            else
                dp[i].push_back(-1);
        }
    }

    while(!Q.empty())
    {
        Pole spr = Q.front();
        for (int i = 0; i < delta_SIZE; ++i)
        {
            if (spr.y + delta_Y[i] >= 0 && spr.y + delta_Y[i] < n && spr.x + delta_X[i] >= 0 && spr.x + delta_X[i] < m)
            {
                if (dp[spr.y + delta_Y[i]][spr.x + delta_X[i]] == -1)
                {
                    dp[spr.y + delta_Y[i]][spr.x + delta_X[i]] = dp[spr.y][spr.x] + 1;
                    Q.push({spr.y + delta_Y[i], spr.x + delta_X[i]});
                }
            }
        }
        Q.pop();
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return 0;
}