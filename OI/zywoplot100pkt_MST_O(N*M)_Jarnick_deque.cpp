#include <iostream>
#include <vector>
#include <deque>

using namespace std;

enum Kierunek
{
    GORA, DOL, LEWO, PRAWO, BRAK
};

struct Pole
{
    int y;
    int x;
    Kierunek kier;
    int val;
};

int n = 0, m = 0, wyn_cis = 0, wyn_inne = 0;
char wczytany_znak;
vector<vector<int>> dp;
vector<vector<int>> krawedzie_gora;
vector<vector<int>> krawedzie_dol;
vector<vector<int>> krawedzie_lewo;
vector<vector<int>> krawedzie_prawo;
deque<Pole> Q;
vector<vector<bool>> czy_w_MST_pionowe;
vector<vector<bool>> czy_w_MST_poziome;
vector<vector<bool>> visited;

int main()
{
    // O(N*M), MST, algorytm Prima na deque(zamiast kolejki priorytetowej / seta, bo wagi na krawedziach to 0 i 1, robimy tak jak Dijkstra 0-1 na deque)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    dp.assign(n+2,{});
    for (int i = 1; i <= n+1; ++i)
        dp[i].assign(m+2,1e9);

    krawedzie_gora.assign(n+2,{});
    for (int i = 1; i <= n+1; ++i)
        krawedzie_gora[i].assign(m+2,0);

    krawedzie_dol.assign(n+2,{});
    for (int i = 1; i <= n+1; ++i)
        krawedzie_dol[i].assign(m+2,0);

    krawedzie_lewo.assign(n+2,{});
    for (int i = 1; i <= n+1; ++i)
        krawedzie_lewo[i].assign(m+2,0);

    krawedzie_prawo.assign(n+2,{});
    for (int i = 1; i <= n+1; ++i)
        krawedzie_prawo[i].assign(m+2,0);

    czy_w_MST_poziome.assign(n+2,{});
    for (int i = 1; i <= n+1; ++i)
        czy_w_MST_poziome[i].assign(m+1,false);

    czy_w_MST_pionowe.assign(n+1,{});
    for (int i = 1; i <= n; ++i)
        czy_w_MST_pionowe[i].assign(m+2,false);

    visited.assign(n+2,{});
    for (int i = 1; i <= n+1; ++i)
        visited[i].assign(m+2,false);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 2; j <= m; ++j)
        {
            cin >> wczytany_znak;
            if (wczytany_znak == 'T')
            {
                krawedzie_dol[i][j] = 1;
                krawedzie_gora[i+1][j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> wczytany_znak;
            if (wczytany_znak == 'T')
            {
                krawedzie_prawo[i][j] = 1;
                krawedzie_lewo[i][j+1] = 1;
            }
        }
    }

    for (int j = 1; j <= m+1; ++j)
    {
        dp[1][j] = 0;
        Q.push_back({1,j,BRAK,0});
    }
    for (int j = 1; j <= m+1; ++j)
    {
        dp[n+1][j] = 0;
        Q.push_back({n+1,j,BRAK,0});
    }
    for (int i = 2; i <= n; ++i)
    {
        dp[i][1] = 0;
        Q.push_back({i,1,BRAK,0});
    }
    for (int i = 2; i <= n; ++i)
    {
        dp[i][m+1] = 0;
        Q.push_back({i,m+1,BRAK,0});
    }

    while(!Q.empty())
    {
        Pole spr = Q.front();
        Q.pop_front();
        if (spr.val > dp[spr.y][spr.x] or visited[spr.y][spr.x] == true)
            continue;
        visited[spr.y][spr.x] = true;
        if (spr.kier != BRAK)
        {
            if (spr.kier == LEWO)
                czy_w_MST_poziome[spr.y][spr.x-1] = true;
            else if (spr.kier == PRAWO)
                czy_w_MST_poziome[spr.y][spr.x] = true;
            if (spr.kier == GORA)
                czy_w_MST_pionowe[spr.y-1][spr.x] = true;
            else if (spr.kier == DOL)
                czy_w_MST_pionowe[spr.y][spr.x] = true;
        }
        if (spr.y - 1 >= 1)
        {
            if (krawedzie_gora[spr.y][spr.x] == 0)
            {
                if (0 < dp[spr.y-1][spr.x])
                {
                    dp[spr.y-1][spr.x] = 0;
                    Q.push_front({spr.y-1, spr.x,DOL, 0});
                }
            }
            else
            {
                if (1 < dp[spr.y-1][spr.x])
                {
                    dp[spr.y-1][spr.x] = 1;
                    Q.push_back({spr.y-1, spr.x, DOL,1});
                }
            }
        }
        if (spr.y + 1 <= n+1)
        {
            if (krawedzie_dol[spr.y][spr.x] == 0)
            {
                if (0 < dp[spr.y+1][spr.x])
                {
                    dp[spr.y+1][spr.x] = 0;
                    Q.push_front({spr.y+1, spr.x, GORA,0});
                }
            }
            else
            {
                if (1 < dp[spr.y+1][spr.x])
                {
                    dp[spr.y+1][spr.x] = 1;
                    Q.push_back({spr.y+1, spr.x, GORA,1});
                }
            }
        }
        if (spr.x - 1 >= 1)
        {
            if (krawedzie_lewo[spr.y][spr.x] == 0)
            {
                if (0 < dp[spr.y][spr.x-1])
                {
                    dp[spr.y][spr.x-1] = 0;
                    Q.push_front({spr.y, spr.x-1, PRAWO,0});
                }
            }
            else
            {
                if (1 < dp[spr.y][spr.x-1])
                {
                    dp[spr.y][spr.x-1] = 1;
                    Q.push_back({spr.y, spr.x-1, PRAWO,1});
                }
            }
        }
        if (spr.x + 1 <= m+1)
        {
            if (krawedzie_prawo[spr.y][spr.x] == 0)
            {
                if (0 < dp[spr.y][spr.x+1])
                {
                    dp[spr.y][spr.x+1] = 0;
                    Q.push_front({spr.y, spr.x+1, LEWO,0});
                }
            }
            else
            {
                if (1 < dp[spr.y][spr.x+1])
                {
                    dp[spr.y][spr.x+1] = 1;
                    Q.push_back({spr.y, spr.x+1, LEWO,1});
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 2; j <= m; ++j)
        {
            if (czy_w_MST_pionowe[i][j] == true)
            {
                if (krawedzie_dol[i][j] == 0)
                    wyn_cis++;
                else
                    wyn_inne++;
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (czy_w_MST_poziome[i][j] == true)
            {
                if (krawedzie_prawo[i][j] == 0)
                    wyn_cis++;
                else
                    wyn_inne++;
            }
        }
    }
    cout << wyn_cis+wyn_inne << ' ' << wyn_cis << '\n';

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 2; j <= m; ++j)
        {
            if (czy_w_MST_pionowe[i][j] == true)
                cout << 'Z';
            else
                cout << '.';
        }
        cout << '\n';
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (czy_w_MST_poziome[i][j] == true)
                cout << 'Z';
            else
                cout << '.';
        }
        cout << '\n';
    }

    return 0;
}
