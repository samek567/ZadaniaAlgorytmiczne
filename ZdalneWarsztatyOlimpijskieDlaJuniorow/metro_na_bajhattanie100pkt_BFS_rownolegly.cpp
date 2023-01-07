#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pole
{
    int y;
    int x;
};

int n = 0, m = 0, s = 0, y_i = 0, x_i = 0, DELTA_SIZE = 4;
Pole spr = {-1,-1};
vector<vector<int>> dp;
queue<Pole> Q;
vector<int> delta_y = {-1,1,0,0};
vector<int> delta_x = {0,0,1,-1};

int main()
{
    // O(n * m), bfs rownolegly praktycznie kopia zadania bitmapa z 2 etapu VI OI.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i)
    {
        dp.push_back({});
        for (int j = 0; j < m; ++j)
            dp[i].push_back(-1);
    }
    for (int i = 0; i < s; ++i)
    {
        cin >> y_i >> x_i;
        Q.push({y_i-1,x_i-1});
        dp[y_i-1][x_i-1] = 0;
    }

    while (!Q.empty())
    {
        spr = Q.front();
        for (int i = 0; i < DELTA_SIZE; ++i)
        {
            if (spr.y + delta_y[i] >= 0 && spr.y + delta_y[i] < n && spr.x + delta_x[i] >= 0 && spr.x + delta_x[i] < m)
            {
                if (dp[spr.y + delta_y[i]][spr.x + delta_x[i]] == -1)
                {
                    dp[spr.y + delta_y[i]][spr.x + delta_x[i]] = dp[spr.y][spr.x] + 1;
                    Q.push({spr.y + delta_y[i],spr.x + delta_x[i]});
                }
            }
        }
        Q.pop();
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            printf("%d ",dp[i][j]);
        printf("\n");
    }

    return 0;
}