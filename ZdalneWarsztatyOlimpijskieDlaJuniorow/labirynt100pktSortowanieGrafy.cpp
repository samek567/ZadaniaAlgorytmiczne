#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    int wartosc;
    int y;
    int x;
    bool operator < (const Element &element) const
    {
        return wartosc < element.wartosc;
    }
};

int n = 0, m = 0, k = 0, ile_sasiadow_wolne_pole = 0, delta_size = 4;
char znak;
vector<vector<char>> plansza;
vector<Element> elementy;
vector<int> delta_Y = {-1,1,0,0};
vector<int> delta_X = {0,0,1,-1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        plansza.push_back({});
        for (int j = 0; j < m; ++j)
        {
            cin >> znak;
            plansza[i].push_back(znak);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (plansza[i][j] == '.')
            {
                ile_sasiadow_wolne_pole = 0;
                for (int f = 0; f < delta_size; ++f)
                {
                    if (i + delta_Y[f] >= 0 && i + delta_Y[f] < n && j + delta_X[f] >= 0 && j + delta_X[f] < m)
                    {
                        if (plansza[i + delta_Y[f]][j + delta_X[f]] == '.')
                            ile_sasiadow_wolne_pole++;
                    }
                }
                elementy.push_back({ile_sasiadow_wolne_pole,i,j});
            }
        }
    }
    sort(elementy.begin(),elementy.end());

    for (int i = 0; i < k; ++i)
    {
        plansza[elementy[i].y][elementy[i].x] = 'X';
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            printf("%c",plansza[i][j]);
        printf("\n");
    }

    return 0;
}