#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pole
{
    int y;
    int x;
};

int m = 0, p = 0, n = 0, w_i = 0, k_i = 0, c_i = 0, zap_y = 0, zap_x = 0, czas = 0;
char wczytany_znak;
Pole wsp_weza = {0,0};
vector<vector<int>> plansza;
vector<vector<int>> wynik;
vector<int> elementy_weza;
queue<Pole> Q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> p >> n;

    for (int i = 0; i < m; ++i)
    {
        plansza.push_back({});
        wynik.push_back({});
        for (int j = 0; j < m; ++j)
        {
            plansza[i].push_back(-1);
            wynik[i].push_back(-1);
        }
    }
    elementy_weza.push_back(0);
    wynik[0][0] = 0;
    Q.push({0,0});

    for (int i = 0; i < p; ++i)
    {
        cin >> w_i >> k_i >> c_i;
        plansza[w_i - 1][k_i - 1] = c_i;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'G')
        {
            wsp_weza.y--;
        }
        else if (wczytany_znak == 'D')
        {
            wsp_weza.y++;
        }
        else if (wczytany_znak == 'P')
        {
            wsp_weza.x++;
        }
        else if (wczytany_znak == 'L')
        {
            wsp_weza.x--;
        }

        if (wczytany_znak == 'Z')
        {
            cin >> zap_y >> zap_x;
            if (wynik[zap_y - 1][zap_x - 1] == -1)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << elementy_weza[wynik[zap_y - 1][zap_x - 1] - czas] << "\n";
            }
        }
        else
        {
            Pole spr = Q.front();
            if (plansza[wsp_weza.y][wsp_weza.x] == -1) // Puste
            {
                czas++;
                wynik[spr.y][spr.x] = -1;
                Q.pop();
                wynik[wsp_weza.y][wsp_weza.x] = (int)elementy_weza.size() - 1 + czas;
                Q.push({wsp_weza.y,wsp_weza.x});
            }
            else
            {
                elementy_weza.push_back(plansza[wsp_weza.y][wsp_weza.x]);
                Q.push({wsp_weza.y,wsp_weza.x});
                wynik[wsp_weza.y][wsp_weza.x] = (int)elementy_weza.size() - 1 + czas;
                plansza[wsp_weza.y][wsp_weza.x] = -1;
            }
        }
    }

    return 0;
}