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

        if (spr.y + 1 >= 0 && spr.y + 1 < n && spr.x >= 0 && spr.x < m)
        {
            if (rozlewanie[spr.y + 1][spr.x] == -1)
            {
                rozlewanie[spr.y + 1][spr.x] = rozlewanie[spr.y][spr.x] + 1;
                Q.push({spr.y + 1,spr.x});
            }
        }

        if (spr.y - 1 >= 0 && spr.y - 1 < n && spr.x >= 0 && spr.x < m)
        {
            if (rozlewanie[spr.y - 1][spr.x] == -1)
            {
                rozlewanie[spr.y - 1][spr.x] = rozlewanie[spr.y][spr.x] + 1;
                Q.push({spr.y - 1,spr.x});
            }
        }

        if (spr.y >= 0 && spr.y < n && spr.x + 1 >= 0 && spr.x + 1 < m)
        {
            if (rozlewanie[spr.y][spr.x + 1] == -1)
            {
                rozlewanie[spr.y][spr.x + 1] = rozlewanie[spr.y][spr.x] + 1;
                Q.push({spr.y,spr.x + 1});
            }
        }

        if (spr.y >= 0 && spr.y < n && spr.x - 1 >= 0 && spr.x - 1 < m)
        {
            if (rozlewanie[spr.y][spr.x - 1] == -1)
            {
                rozlewanie[spr.y][spr.x - 1] = rozlewanie[spr.y][spr.x] + 1;
                Q.push({spr.y,spr.x - 1});
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
