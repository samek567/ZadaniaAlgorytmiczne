#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pole
{
    int y;
    int x;
};

int n = 0, m = 0, y_1 = 0, x_1 = 0, y_2 = 0, x_2 = 0, ile_skokow = 0, delta_SIZE = 4;
char znak;
Pole v = {-1,-1};
vector<vector<char>> plansza;
queue<Pole> Q_DFS;
queue<Pole> Q_do_skoku;
vector<int> delta_X = {0,0,-1,1};
vector<int> delta_Y = {1,-1,0,0};
vector<int> delta_X_skok = {0,0,-2,2};
vector<int> delta_Y_skok = {2,-2,0,0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> y_1 >> x_1 >> y_2 >> x_2;
    for (int i = 0; i < n; ++i)
    {
        plansza.push_back({});
        for (int j = 0; j < m; ++j)
        {
            cin >> znak;
            plansza[i].push_back(znak);
        }
    }
    Q_DFS.push({y_1-1,x_1-1});
    plansza[y_1-1][x_1-1] = '#';
    while(!Q_DFS.empty())
    {
        while (!Q_DFS.empty())
        {
            v = Q_DFS.front();
            Q_do_skoku.push(v);
            for (int i = 0; i < delta_SIZE; ++i)
            {
                if (v.y + delta_Y[i] >= 0 && v.y + delta_Y[i] < n && v.x + delta_X[i] >= 0 && v.x + delta_X[i] < m)
                {
                    if (plansza[v.y + delta_Y[i]][v.x + delta_X[i]] == '.')
                    {
                        plansza[v.y + delta_Y[i]][v.x + delta_X[i]] = '#';
                        Q_DFS.push({v.y + delta_Y[i], v.x + delta_X[i]});
                    }
                }
            }
            Q_DFS.pop();
        }
        if (plansza[y_2-1][x_2-1] == '#')
        {
            printf("%d",ile_skokow);
            return 0;
        }
        ile_skokow++;
        while (!Q_do_skoku.empty())
        {
            for (int i = 0; i < delta_SIZE; ++i)
            {
                if (Q_do_skoku.front().y + delta_Y_skok[i] >= 0 && Q_do_skoku.front().y + delta_Y_skok[i] < n && Q_do_skoku.front().x + delta_X_skok[i] >= 0 && Q_do_skoku.front().x + delta_X_skok[i] < m)
                {
                    if (plansza[Q_do_skoku.front().y + delta_Y_skok[i]][Q_do_skoku.front().x + delta_X_skok[i]] == '.')
                    {
                        plansza[Q_do_skoku.front().y + delta_Y_skok[i]][Q_do_skoku.front().x + delta_X_skok[i]] = '#';
                        Q_DFS.push({Q_do_skoku.front().y + delta_Y_skok[i],Q_do_skoku.front().x + delta_X_skok[i]});
                    }
                }
            }
            Q_do_skoku.pop();
        }
    }

    printf("-1");
    return 0;
}