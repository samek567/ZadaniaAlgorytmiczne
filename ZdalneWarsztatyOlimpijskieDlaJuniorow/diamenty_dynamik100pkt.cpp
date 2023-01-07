#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pole
{
    int y;
    int x;
};

int z = 0, n = 0, m = 0, wczytana_liczba = 0;
vector<vector<int>> plansza;
vector<vector<int>> dp;
vector<vector<Pole>> rodzic;
vector<char> droga;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> z;
    for (int g = 0; g < z; ++g)
    {
        cin >> m >> n;
        plansza.clear();
        dp.clear();
        rodzic.clear();
        droga.clear();
        for(int i = 0; i < n; ++i)
        {
            plansza.push_back({});
            dp.push_back({});
            rodzic.push_back({});
            for (int j = 0; j < m; ++j)
            {
                cin >> wczytana_liczba;
                plansza[i].push_back(wczytana_liczba);
                dp[i].push_back(0);
                rodzic[i].push_back({-1,-1});
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (i == 0 && j == 0)
                {
                    if (plansza[0][0] == 1)
                        dp[0][0] = 1;
                    else
                        dp[0][0] = 0;
                }
                else if (i == 0)
                {
                    dp[0][j] = dp[0][j-1];
                    rodzic[0][j] = {0,j-1};
                    if (plansza[i][j] == 1)
                        dp[i][j]++;
                }
                else if (j == 0)
                {
                    dp[i][0] = dp[i-1][0];
                    rodzic[i][0] = {i-1,0};
                    if (plansza[i][j] == 1)
                        dp[i][j]++;
                }
                else
                {
                    if (dp[i-1][j] > dp[i][j-1])
                    {
                        dp[i][j] = dp[i-1][j];
                        rodzic[i][j] = {i-1,j};
                    }
                    else
                    {
                        dp[i][j] = dp[i][j-1];
                        rodzic[i][j] = {i,j-1};
                    }
                    if (plansza[i][j] == 1)
                        dp[i][j]++;
                }
            }
        }
        Pole spr = {n-1,m-1};
        while(true)
        {
            if (spr.y == -1)
                break;
            else if (rodzic[spr.y][spr.x].y == -1)
                break;
            else if (rodzic[spr.y][spr.x].y < spr.y)
                droga.push_back('v');
            else
                droga.push_back('>');
            spr = rodzic[spr.y][spr.x];
        }
        reverse(droga.begin(),droga.end());
        printf("%d ",dp[n-1][m-1]);
        for (int i = 0; i < droga.size(); ++i)
            printf("%c",droga[i]);
        printf("\n");
    }
    return 0;
}