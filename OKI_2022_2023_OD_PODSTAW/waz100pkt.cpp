#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum Kierunek
{
    GORA, DOL, LEWO, PRAWO
};

struct Pole
{
    int y;
    int x;
};

int n = 0, m = 0, k = 0;
char wczytany_znak;
Kierunek kierunek_weza;
Pole glowa_weza = {-1,-1};
vector<vector<char>> plansza;
vector<vector<bool>> czy_jest_waz;
queue<Pole> Q;

inline void aktualizuj_kierunek(char &ruch_weza)
{
    if (kierunek_weza == GORA)
    {
        if (ruch_weza == 'N')
            kierunek_weza = GORA;
        else if (ruch_weza == 'L')
            kierunek_weza = LEWO;
        else if (ruch_weza == 'P')
            kierunek_weza = PRAWO;
    }
    else if (kierunek_weza == DOL)
    {
        if (ruch_weza == 'N')
            kierunek_weza = DOL;
        else if (ruch_weza == 'L')
            kierunek_weza = PRAWO;
        else if (ruch_weza == 'P')
            kierunek_weza = LEWO;
    }
    else if (kierunek_weza == PRAWO)
    {
        if (ruch_weza == 'N')
            kierunek_weza = PRAWO;
        else if (ruch_weza == 'L')
            kierunek_weza = GORA;
        else if (ruch_weza == 'P')
            kierunek_weza = DOL;
    }
    else if (kierunek_weza == LEWO)
    {
        if (ruch_weza == 'N')
            kierunek_weza = LEWO;
        else if (ruch_weza == 'L')
            kierunek_weza = DOL;
        else if (ruch_weza == 'P')
            kierunek_weza = GORA;
    }
}

inline Pole kolejne_pole(char &kierunek)
{
    Pole res = glowa_weza;
    if (kierunek_weza == GORA)
    {
        if (kierunek == 'N')
            res.y--;
        else if (kierunek == 'L')
            res.x--;
        else if (kierunek == 'P')
            res.x++;
    }
    else if (kierunek_weza == DOL)
    {
        if (kierunek == 'N')
            res.y++;
        else if (kierunek == 'L')
            res.x++;
        else if (kierunek == 'P')
            res.x--;
    }
    else if (kierunek_weza == LEWO)
    {
        if (kierunek == 'N')
            res.x--;
        else if (kierunek == 'L')
            res.y++;
        else if (kierunek == 'P')
            res.y--;
    }
    else if (kierunek_weza == PRAWO)
    {
        if (kierunek == 'N')
            res.x++;
        else if (kierunek == 'L')
            res.y--;
        else if (kierunek == 'P')
            res.y++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    plansza.assign(n,{});
    for (int i = 0; i < n; ++i)
        plansza[i].assign(m,'B');

    czy_jest_waz.assign(n,{});
    for (int i = 0; i < n; ++i)
        czy_jest_waz[i].assign(m,false);

    cin >> wczytany_znak;
    if (wczytany_znak == 'N')
        kierunek_weza = GORA;
    else if (wczytany_znak == 'E')
        kierunek_weza = PRAWO;
    else if (wczytany_znak == 'S')
        kierunek_weza = DOL;
    else
        kierunek_weza = LEWO;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> plansza[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (plansza[i][j] == 'W')
                glowa_weza = {i,j};

    Q.push(glowa_weza);
    czy_jest_waz[glowa_weza.y][glowa_weza.x] = true;
    for (int z = 0; z < k; ++z)
    {
        Pole spr = Q.front();
        cin >> wczytany_znak;
        Pole kolejne = kolejne_pole(wczytany_znak);
        if (kolejne.y < 0 or kolejne.y == n or kolejne.x < 0 or kolejne.x == m)
        {
            cout << z+1 << '\n';
            return 0;
        }
        if (czy_jest_waz[kolejne.y][kolejne.x] == true)
        {
            cout << z+1 << '\n';
            return 0;
        }
        Q.push(kolejne);
        if (plansza[kolejne.y][kolejne.x] == 'J')
            plansza[kolejne.y][kolejne.x] = '.';
        else
        {
            czy_jest_waz[spr.y][spr.x] = false;
            Q.pop();
        }
        czy_jest_waz[kolejne.y][kolejne.x] = true;
        glowa_weza = kolejne;
        aktualizuj_kierunek(wczytany_znak);
    }

    cout << "OK" << '\n';

    return 0;
}