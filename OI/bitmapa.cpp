#include <iostream>
#include <queue>

using namespace std;

struct Element
{
    int y;
    int x;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0, m = 0;
    char wczytany_znak;

    cin >> n >> m;

    int rozlewanie[n][m];
    queue<Element> Q;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> wczytany_znak;
            if (wczytany_znak == '0')
            {
                rozlewanie[i][j] = -1;
            }
            else
            {
                rozlewanie[i][j] = 0;
                Q.push({i,j});
            }
        }
    }

    while(!Q.empty())
    {
        Element spr = Q.front();
        int X = 4;
        vector<int> delta_x = {1,-1,0,0};
        vector<int> delta_y = {0,0,1,-1};

        for (int i = 0; i < X; ++i)
        {
            if (spr.y + delta_y[i] >= 0 && spr.y + delta_y[i] < n && spr.x + delta_x[i] >= 0 && spr.x + delta_x[i] < m)
            {
                if (rozlewanie[spr.y + delta_y[i]][spr.x + delta_x[i]] == -1)
                {
                    rozlewanie[spr.y + delta_y[i]][spr.x + delta_x[i]] = rozlewanie[spr.y][spr.x] + 1;
                    Q.push({spr.y + delta_y[i],spr.x + delta_x[i]});
                }
            }
        }

        Q.pop();
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << rozlewanie[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
