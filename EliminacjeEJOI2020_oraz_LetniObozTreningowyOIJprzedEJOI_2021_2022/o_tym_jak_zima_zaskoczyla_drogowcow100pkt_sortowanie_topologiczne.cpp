#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pole
{
    int y;
    int x;
};

enum Auto
{
    GORA, DOL, LEWO, PRAWO, BRAK
};

int z = 0, n = 0, m = 0, wyn = 0;
char wczytany_znak;
vector<vector<Auto>> plansza;
vector<int> ile_wchodzi;
vector<vector<int>> krawedzie;
queue<int> Q;

int main()
{
    // Skonstruowanie grafu i posortowanie go topologicznie.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> z;

    while(z--)
    {
        wyn = 0;
        cin >> n >> m;

        plansza.clear();
        plansza.assign(n,{});
        for (int i = 0; i < n; ++i)
            plansza[i].assign(m,BRAK);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> wczytany_znak;
                if (wczytany_znak == 'N')
                    plansza[i][j] = GORA;
                else if (wczytany_znak == 'E')
                    plansza[i][j] = PRAWO;
                else if (wczytany_znak == 'S')
                    plansza[i][j] = DOL;
                else if (wczytany_znak == 'W')
                    plansza[i][j] = LEWO;
            }
        }

        ile_wchodzi.assign(n*m,0);
        krawedzie.assign(n*m,{});

        for (int i = 0; i < n; ++i)
        {
            int idx = -1;
            for (int j = 0; j < m; ++j)
            {
                if (plansza[i][j] == BRAK)
                    continue;
                if (idx != -1)
                {
                    int wierz = idx + i*m, wierz_akt = j + i*m;
                    ile_wchodzi[wierz]++;
                    krawedzie[wierz_akt].push_back(wierz);
                }
                if (plansza[i][j] == PRAWO)
                    idx = j;
            }
            idx = -1;
            for (int j = m-1; j >= 0; --j)
            {
                if (plansza[i][j] == BRAK)
                    continue;
                if (idx != -1)
                {
                    int wierz = idx + i*m, wierz_akt = j + i*m;
                    ile_wchodzi[wierz]++;
                    krawedzie[wierz_akt].push_back(wierz);
                }
                if (plansza[i][j] == LEWO)
                    idx = j;
            }
        }

        for (int i = 0; i < m; ++i)
        {
            int idx = -1;
            for (int j = 0; j < n; ++j)
            {
                if (plansza[j][i] == BRAK)
                    continue;
                if (idx != -1)
                {
                    int wierz = i + idx*m, wierz_akt = i + j*m;
                    ile_wchodzi[wierz]++;
                    krawedzie[wierz_akt].push_back(wierz);
                }
                if (plansza[j][i] == DOL)
                    idx = j;
            }
            idx = -1;
            for (int j = n-1; j >= 0; --j)
            {
                if (plansza[j][i] == BRAK)
                    continue;
                if (idx != -1)
                {
                    int wierz = i + idx*m, wierz_akt = i + j*m;
                    ile_wchodzi[wierz]++;
                    krawedzie[wierz_akt].push_back(wierz);
                }
                if (plansza[j][i] == GORA)
                    idx = j;
            }
        }

        Q = queue<int>();
        for (int i = 0; i < n*m; ++i)
        {
            if (ile_wchodzi[i] == 0 and plansza[i/m][i%m] != BRAK)
            {
                Q.push(i);
                wyn++;
            }
        }
        while(!Q.empty())
        {
            int v = Q.front();
            Q.pop();
            for (int i = 0; i < krawedzie[v].size(); ++i)
            {
                int wierz = krawedzie[v][i];
                ile_wchodzi[wierz]--;
                if (ile_wchodzi[wierz] == 0)
                {
                    Q.push(wierz);
                    wyn++;
                }
            }
        }

        cout << wyn << '\n';
    }

    return 0;
}
