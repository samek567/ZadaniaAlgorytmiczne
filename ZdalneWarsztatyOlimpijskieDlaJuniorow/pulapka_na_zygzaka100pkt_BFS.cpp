#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pole
{
    int y;
    int x;
};

int n = 0, m = 0, v = 0, czas = 1, rozlanie_SIZE = 0, delta_SIZE = 4;
char wczytany_znak;
Pole spr = {-1,-1};
vector<vector<char>> plansza;
vector<vector<int>> droga_zygzaka;
queue<Pole> Q_zygzak;
queue<Pole> Q_ogien;
vector<int> delta_Y = {-1,1,0,0};
vector<int> delta_X = {0,0,-1,1};

void rozlewaj_ogien()
{
    rozlanie_SIZE = Q_ogien.size();
    for (int i = 0; i < rozlanie_SIZE; ++i)
    {
        spr = Q_ogien.front();
        for (int j = 0; j < delta_SIZE; ++j)
        {
            if (spr.y + delta_Y[j] >= 0 && spr.y + delta_Y[j] < n && spr.x + delta_X[j] >= 0 && spr.x + delta_X[j] < m)
            {
                if (plansza[spr.y + delta_Y[j]][spr.x + delta_X[j]] == '.')
                {
                    plansza[spr.y + delta_Y[j]][spr.x + delta_X[j]] = '*';
                    Q_ogien.push({spr.y + delta_Y[j], spr.x + delta_X[j]});
                }
            }
        }
        Q_ogien.pop();
    }
}

void rozlewaj_zygzak()
{
    rozlanie_SIZE = Q_zygzak.size();
    for (int i = 0; i < rozlanie_SIZE; ++i)
    {
        spr = Q_zygzak.front();
        if (plansza[spr.y][spr.x] == '*')
        {
            Q_zygzak.pop();
            continue;
        }
        for (int j = 0; j < delta_SIZE; ++j)
        {
            if (spr.y + delta_Y[j] >= 0 && spr.y + delta_Y[j] < n && spr.x + delta_X[j] >= 0 && spr.x + delta_X[j] < m)
            {
                if (plansza[spr.y + delta_Y[j]][spr.x + delta_X[j]] == '.' && droga_zygzaka[spr.y + delta_Y[j]][spr.x + delta_X[j]] == -1)
                {
                    droga_zygzaka[spr.y + delta_Y[j]][spr.x + delta_X[j]] = droga_zygzaka[spr.y][spr.x] + 1;
                    Q_zygzak.push({spr.y + delta_Y[j], spr.x + delta_X[j]});
                }
            }
        }
        Q_zygzak.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> v;
    for (int i = 0; i < n; ++i)
    {
        plansza.push_back({});
        droga_zygzaka.push_back({});
        for (int j = 0; j < m; ++j)
        {
            cin >> wczytany_znak;
            plansza[i].push_back(wczytany_znak);
            droga_zygzaka[i].push_back(-1);
            if (wczytany_znak == 'Z')
            {
                if (i == 0 && j == 0)
                {
                    printf("0");
                    return 0;
                }
                Q_zygzak.push({i,j});
                plansza[i][j] = '.';
                droga_zygzaka[i][j] = 0;
            }
            if (wczytany_znak == '*')
                Q_ogien.push({i,j});
        }
    }

    while(!Q_zygzak.empty())
    {
        rozlewaj_zygzak();
        if (czas % v == 0)
            rozlewaj_ogien();
        if (droga_zygzaka[0][0] != -1)
        {
            printf("%d",droga_zygzaka[0][0]);
            return 0;
        }
        czas++;
    }
    printf("-1");

    return 0;
}