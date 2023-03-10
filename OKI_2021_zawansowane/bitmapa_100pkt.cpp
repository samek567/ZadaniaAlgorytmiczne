#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element_kolejki
{
    int wartosc;
    int y;
    int x;
};

int n = 0, m = 0, delta_SIZE = 4;
char wczytany_znak;
vector<vector<int>> dp;
queue<Element_kolejki> Q;
vector<int> delta_Y = {-1,1,0,0};
vector<int> delta_X = {0,0,-1,1};

int main()
{
    // BFS rownolegly
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
                Q.push({0,i,j});
            }
            else
                dp[i].push_back(-1);
        }
    }

    while(!Q.empty())
    {
        Element_kolejki spr = Q.front();
        Q.pop();
        for (int i = 0; i < delta_SIZE; ++i)
        {
            if (spr.y + delta_Y[i] >= 0 && spr.y + delta_Y[i] < n && spr.x + delta_X[i] >= 0 && spr.x + delta_X[i] < m)
            {
                if (dp[spr.y + delta_Y[i]][spr.x + delta_X[i]] == -1)
                {
                    dp[spr.y + delta_Y[i]][spr.x + delta_X[i]] = spr.wartosc + 1;
                    Q.push({spr.wartosc+1,spr.y + delta_Y[i], spr.x + delta_X[i]});
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}