#include <iostream>
#include <queue>

using namespace std;

struct Punkt
{
    int y;
    int x;
};

queue<Punkt> droga_ognia;
bool statystyki_ognia[605][605];
char szachownica[605][605];

void uzupelniaj_ogien(int v,int n)
{
    // Rozpsestrzenia sie ogien.
    int ile_razy = droga_ognia.size();
    for (int j = 0; j < ile_razy; ++j)
    {
        Punkt ogien = droga_ognia.front();

        if (ogien.x+1 < n) // Prawo
        {
            if ((szachownica[ogien.y][ogien.x+1] == '.' || szachownica[ogien.y][ogien.x+1] == 'Z') && statystyki_ognia[ogien.y][ogien.x+1] == false)
            {
                statystyki_ognia[ogien.y][ogien.x+1] = true;
                droga_ognia.push({ogien.y,ogien.x+1});
            }
        }
        if (ogien.x-1 >= 0) // Lewo
        {
            if ((szachownica[ogien.y][ogien.x-1] == '.' || szachownica[ogien.y][ogien.x-1] == 'Z') && statystyki_ognia[ogien.y][ogien.x-1] == false)
            {
                statystyki_ognia[ogien.y][ogien.x-1] = true;
                droga_ognia.push({ogien.y,ogien.x-1});
            }
        }
        if (ogien.y-1 >= 0) // Gora
        {
            if ((szachownica[ogien.y-1][ogien.x] == '.' || szachownica[ogien.y-1][ogien.x] == 'Z') && statystyki_ognia[ogien.y-1][ogien.x] == false)
            {
                statystyki_ognia[ogien.y-1][ogien.x] = true;
                droga_ognia.push({ogien.y-1,ogien.x});
            }
        }
        if (ogien.y+1 < n) // Dol
        {
            if ((szachownica[ogien.y+1][ogien.x] == '.' || szachownica[ogien.y+1][ogien.x] == 'Z') && statystyki_ognia[ogien.y+1][ogien.x] == false)
            {
                statystyki_ognia[ogien.y+1][ogien.x] = true;
                droga_ognia.push({ogien.y+1,ogien.x});
            }
        }

        droga_ognia.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int m = 0;
    int v = 0;
    char wczytany_znak;

    cin >> n >> m >> v;

    int statystyki_drogi[n][m];
    queue<Punkt> droga_zygzaka;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            statystyki_ognia[i][j] = false;
            statystyki_drogi[i][j] = -1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> wczytany_znak;
            szachownica[i][j] = wczytany_znak;
            if (wczytany_znak == 'Z')
            {
                droga_zygzaka.push({i,j});
                if (droga_zygzaka.back().x == 0 && droga_zygzaka.back().y == 0)
                {
                    cout << "0";
                    return 0;
                }
                statystyki_drogi[i][j] = 0;
            }
            if (wczytany_znak == '*')
            {
                droga_ognia.push({i,j});
                statystyki_ognia[i][j] = true;
            }
        }
    }

    int licznik_pol = 0;
    while (!droga_zygzaka.empty())
    {
        Punkt zygzak = droga_zygzaka.front();
        if (statystyki_drogi[0][0] != -1)
        {
            if (statystyki_ognia[0][0] == true)
            {
                cout << "-1";
                return 0;
            }
            else
            {
                cout << statystyki_drogi[0][0];
                return 0;
            }
        }
        if (zygzak.x+1 < n) // Prawo
        {
            if (statystyki_drogi[zygzak.y][zygzak.x+1] == -1 && szachownica[zygzak.y][zygzak.x+1] == '.' && statystyki_ognia[zygzak.y][zygzak.x+1] == false)
            {
                if (licznik_pol < statystyki_drogi[zygzak.y][zygzak.x] + 1)
                {
                    licznik_pol = statystyki_drogi[zygzak.y][zygzak.x]+1;
                    if (licznik_pol % v == 0)
                    {
                        uzupelniaj_ogien(v,n);
                    }
                }
                if (statystyki_ognia[zygzak.y][zygzak.x+1] == false)
                {
                    statystyki_drogi[zygzak.y][zygzak.x+1] = statystyki_drogi[zygzak.y][zygzak.x] + 1;
                    droga_zygzaka.push({zygzak.y,zygzak.x+1});
                }
            }
        }
        if (zygzak.x-1 >= 0) // Lewo
        {
            if (statystyki_drogi[zygzak.y][zygzak.x-1] == -1 && szachownica[zygzak.y][zygzak.x-1] == '.' && statystyki_ognia[zygzak.y][zygzak.x-1] == false)
            {
                if (licznik_pol < statystyki_drogi[zygzak.y][zygzak.x] + 1)
                {
                    licznik_pol = statystyki_drogi[zygzak.y][zygzak.x]+1;
                    if (licznik_pol % v == 0)
                    {
                        uzupelniaj_ogien(v,n);
                    }
                }
                if (statystyki_ognia[zygzak.y][zygzak.x-1] == false)
                {
                    statystyki_drogi[zygzak.y][zygzak.x-1] = statystyki_drogi[zygzak.y][zygzak.x] + 1;
                    droga_zygzaka.push({zygzak.y,zygzak.x-1});
                }
            }
        }
        if (zygzak.y-1 >= 0) // Gora
        {
            if (statystyki_drogi[zygzak.y-1][zygzak.x] == -1 && szachownica[zygzak.y-1][zygzak.x] == '.' && statystyki_ognia[zygzak.y-1][zygzak.x] == false)
            {
                if (licznik_pol < statystyki_drogi[zygzak.y][zygzak.x] + 1)
                {
                    licznik_pol = statystyki_drogi[zygzak.y][zygzak.x]+1;
                    if (licznik_pol % v == 0)
                    {
                        uzupelniaj_ogien(v,n);
                    }
                }
                if (statystyki_ognia[zygzak.y-1][zygzak.x] == false)
                {
                    statystyki_drogi[zygzak.y-1][zygzak.x] = statystyki_drogi[zygzak.y][zygzak.x] + 1;
                    droga_zygzaka.push({zygzak.y-1,zygzak.x});
                }
            }
        }
        if (zygzak.y+1 < n) // Dol
        {
            if (statystyki_drogi[zygzak.y+1][zygzak.x] == -1 && szachownica[zygzak.y+1][zygzak.x] == '.' && statystyki_ognia[zygzak.y+1][zygzak.x] == false)
            {
                if (licznik_pol < statystyki_drogi[zygzak.y][zygzak.x] + 1)
                {
                    licznik_pol = statystyki_drogi[zygzak.y][zygzak.x]+1;
                    if (licznik_pol % v == 0)
                    {
                        uzupelniaj_ogien(v,n);
                    }
                }
                if (statystyki_ognia[zygzak.y+1][zygzak.x] == false)
                {
                    statystyki_drogi[zygzak.y+1][zygzak.x] = statystyki_drogi[zygzak.y][zygzak.x] + 1;
                    droga_zygzaka.push({zygzak.y+1,zygzak.x});
                }
            }
        }

        droga_zygzaka.pop();
    }
    cout << "-1";
    return 0;
}