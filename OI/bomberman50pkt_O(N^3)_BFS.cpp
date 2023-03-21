#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pole
{
    int y;
    int x;
};

int n = 0, wyn = 1e9, delta_SIZE = 4;
char wczytany_znak;
Pole poczatek = {-1,-1}, koniec = {-1,-1}, wyn_pole = {-1, -1};
vector<vector<char>> plansza;
vector<vector<int>> dojscie_od_poczatku;
vector<vector<int>> dojscie_od_konca;
vector<vector<int>> dp_dojscie;
queue<Pole> Q;
vector<int> delta_Y = {-1,1,0,0};
vector<int> delta_X = {0,0,-1,1};
vector<vector<Pole>> idx_poprzedniej;

int main()
{
    // O(N^3), BFS
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        plansza.push_back({});
        plansza[i].assign(n,'s');
        for (int j = 0; j < n; ++j)
        {
            cin >> plansza[i][j];
            if (plansza[i][j] == 'P')
                poczatek = {i,j};
            else if (plansza[i][j] == 'K')
                koniec = {i,j};
        }
    }

    dojscie_od_poczatku.assign(n,{});
    for (int i = 0; i < n; ++i)
        dojscie_od_poczatku[i].assign(n,-1);

    Q.push(poczatek);
    dojscie_od_poczatku[poczatek.y][poczatek.x] = 0;
    while(!Q.empty())
    {
        Pole spr = Q.front();
        Q.pop();
        for (int i = 0; i < delta_SIZE; ++i)
        {
            int y = spr.y + delta_Y[i], x = spr.x + delta_X[i];
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dojscie_od_poczatku[y][x] == -1 and plansza[y][x] != 'X' and plansza[y][x] != '#')
                {
                    dojscie_od_poczatku[y][x] = dojscie_od_poczatku[spr.y][spr.x] + 1;
                    Q.push({y,x});
                }
            }
        }
    }

    dojscie_od_konca.assign(n,{});
    for (int i = 0; i < n; ++i)
        dojscie_od_konca[i].assign(n,-1);
    Q.push(koniec);
    dojscie_od_konca[koniec.y][koniec.x] = 0;
    while(!Q.empty())
    {
        Pole spr = Q.front();
        Q.pop();
        for (int i = 0; i < delta_SIZE; ++i)
        {
            int y = spr.y + delta_Y[i], x = spr.x + delta_X[i];
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dojscie_od_konca[y][x] == -1 and plansza[y][x] != 'X' and plansza[y][x] != '#')
                {
                    dojscie_od_konca[y][x] = dojscie_od_konca[spr.y][spr.x] + 1;
                    Q.push({y,x});
                }
            }
        }
    }

    dp_dojscie.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp_dojscie[i].assign(n,1e9);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (plansza[i][j] == 'X')
                continue;
            Pole do_kod_max_dol = {i,j}, do_kod_max_gora = {i,j}, do_kod_max_lewo = {i,j}, do_kod_max_prawo = {i,j};
            for (int k = j-1; k >= 0; --k)
            {
                if (plansza[i][k] == 'X')
                    break;
                do_kod_max_lewo = {i,k};
            }
            for (int k = j+1; k < n; ++k)
            {
                if (plansza[i][k] == 'X')
                    break;
                do_kod_max_prawo = {i,k};
            }
            for (int k = i-1; k >= 0; --k)
            {
                if (plansza[k][j] == 'X')
                    break;
                do_kod_max_gora = {k,j};
            }
            for (int k = i+1; k < n; ++k)
            {
                if (plansza[k][j] == 'X')
                    break;
                do_kod_max_dol = {k,j};
            }
            for (int k = do_kod_max_gora.y; k <= do_kod_max_dol.y; ++k)
                dp_dojscie[k][j] = 1e9;
            for (int k = do_kod_max_lewo.x; k <= do_kod_max_prawo.x; ++k)
                dp_dojscie[i][k] = 1e9;
            for (int k = do_kod_max_gora.y; k <= do_kod_max_dol.y; ++k)
            {
                for (int f = 0; f < delta_SIZE; ++f)
                {
                    int y = k + delta_Y[f], x = j + delta_X[f];
                    if (y >= 0 and y < n and x >= 0 and x < n)
                        if (dojscie_od_poczatku[y][x] != -1)
                            dp_dojscie[k][j] = min(dp_dojscie[k][j], dojscie_od_poczatku[y][x] + 1);
                }
            }
            for (int k = do_kod_max_lewo.x; k <= do_kod_max_prawo.x; ++k)
            {
                for (int f = 0; f < delta_SIZE; ++f)
                {
                    int y = i + delta_Y[f], x = k + delta_X[f];
                    if (y >= 0 and y < n and x >= 0 and x < n)
                        if (dojscie_od_poczatku[y][x] != -1)
                            dp_dojscie[i][k] = min(dp_dojscie[i][k], dojscie_od_poczatku[y][x] + 1);
                }
            }

            for (int k = do_kod_max_lewo.x; k < j; ++k)
                dp_dojscie[i][k+1] = min(dp_dojscie[i][k+1], dp_dojscie[i][k] + 1);
            for (int k = do_kod_max_prawo.x; k > j; --k)
                dp_dojscie[i][k-1] = min(dp_dojscie[i][k-1], dp_dojscie[i][k] + 1);

            for (int k = do_kod_max_gora.y; k < i; ++k)
                dp_dojscie[k+1][j] = min(dp_dojscie[k+1][j], dp_dojscie[k][j] + 1);
            for (int k = do_kod_max_dol.y; k > i; --k)
                dp_dojscie[k-1][j] = min(dp_dojscie[k-1][j], dp_dojscie[k][j] + 1);

            for (int k = j; k > do_kod_max_lewo.x; --k)
                dp_dojscie[i][k-1] = min(dp_dojscie[i][k-1], dp_dojscie[i][k] + 1);
            for (int k = j; k < do_kod_max_prawo.x; ++k)
                dp_dojscie[i][k+1] = min(dp_dojscie[i][k+1], dp_dojscie[i][k] + 1);

            for (int k = i; k > do_kod_max_gora.y; --k)
                dp_dojscie[k-1][j] = min(dp_dojscie[k-1][j], dp_dojscie[k][j] + 1);
            for (int k = i; k < do_kod_max_dol.y; ++k)
                dp_dojscie[k+1][j] = min(dp_dojscie[k+1][j], dp_dojscie[k][j] + 1);


            for (int k = do_kod_max_lewo.x; k <= do_kod_max_prawo.x; ++k)
            {
                if (dojscie_od_konca[i][k] != -1)
                {
                    if (dp_dojscie[i][k] + dojscie_od_konca[i][k] < wyn)
                    {
                        wyn = dp_dojscie[i][k] + dojscie_od_konca[i][k];
                        wyn_pole = {i,j};
                    }
                }
                for (int f = 0; f < delta_SIZE; ++f)
                {
                    int y = i + delta_Y[f], x = k + delta_X[f];
                    if (y >= 0 and y < n and x >= 0 and x < n)
                    {
                        if (dojscie_od_konca[y][x] != -1)
                        {
                            if (dp_dojscie[i][k] + dojscie_od_konca[y][x] + 1 < wyn)
                            {
                                wyn = dp_dojscie[i][k] + dojscie_od_konca[y][x] + 1;
                                wyn_pole = {i,j};
                            }
                        }
                    }
                }
            }

            for (int k = do_kod_max_gora.y; k <= do_kod_max_dol.y; ++k)
            {
                if (dojscie_od_konca[k][j] != -1)
                {
                    if (dp_dojscie[k][j] + dojscie_od_konca[k][j] < wyn)
                    {
                        wyn = dp_dojscie[k][j] + dojscie_od_konca[k][j];
                        wyn_pole = {i,j};
                    }
                }
                for (int f = 0; f < delta_SIZE; ++f)
                {
                    int y = k + delta_Y[f], x = j + delta_X[f];
                    if (y >= 0 and y < n and x >= 0 and x < n)
                    {
                        if (dojscie_od_konca[y][x] != -1)
                        {
                            if (dp_dojscie[k][j] + dojscie_od_konca[y][x] + 1 < wyn)
                            {
                                wyn = dp_dojscie[k][j] + dojscie_od_konca[y][x] + 1;
                                wyn_pole = {i,j};
                            }
                        }
                    }
                }
            }
        }
    }

    if (wyn == 1e9)
    {
        cout << "NIE" << '\n';
        return 0;
    }
    cout << wyn << '\n' << wyn_pole.y+1 << ' ' << wyn_pole.x+1 << '\n';
    for (int i = wyn_pole.x; i < n; ++i)
    {
        if (plansza[wyn_pole.y][i] == 'X')
            break;
        else if (plansza[wyn_pole.y][i] == '#')
            plansza[wyn_pole.y][i] = '.';
    }
    for (int i = wyn_pole.x; i >= 0; --i)
    {
        if (plansza[wyn_pole.y][i] == 'X')
            break;
        else if (plansza[wyn_pole.y][i] == '#')
            plansza[wyn_pole.y][i] = '.';
    }
    for (int i = wyn_pole.y; i < n; ++i)
    {
        if (plansza[i][wyn_pole.x] == 'X')
            break;
        else if (plansza[i][wyn_pole.x] == '#')
            plansza[i][wyn_pole.x] = '.';
    }
    for (int i = wyn_pole.y; i >= 0; --i)
    {
        if (plansza[i][wyn_pole.x] == 'X')
            break;
        else if (plansza[i][wyn_pole.x] == '#')
            plansza[i][wyn_pole.x] = '.';
    }

    idx_poprzedniej.assign(n,{});
    for (int i = 0; i < n; ++i)
    {
        dp_dojscie[i].assign(n,-1);
        idx_poprzedniej[i].assign(n,{-1,-1});
    }

    dp_dojscie[poczatek.y][poczatek.x] = 0;
    Q.push(poczatek);
    while(!Q.empty())
    {
        Pole spr = Q.front();
        Q.pop();
        for (int i = 0; i < delta_SIZE; ++i)
        {
            int y = spr.y + delta_Y[i], x = spr.x + delta_X[i];
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (plansza[y][x] != 'X' and plansza[y][x] != '#' and dp_dojscie[y][x] == -1)
                {
                    dp_dojscie[y][x] = dp_dojscie[spr.y][spr.x] + 1;
                    idx_poprzedniej[y][x] = {spr.y, spr.x};
                    Q.push({y,x});
                }
            }
        }
    }

    Pole odtw = koniec;
    vector<Pole> droga;
    int cnt = 0;
    while(true)
    {
        if (idx_poprzedniej[odtw.y][odtw.x].y == -1)
            break;
        droga.push_back(odtw);
        odtw = idx_poprzedniej[odtw.y][odtw.x];
    }

    reverse(droga.begin(), droga.end());
    odtw = poczatek;
    for (int i = 0; i < droga.size(); ++i)
    {
        if (droga[i].y < odtw.y)
            cout << 'G';
        else if (droga[i].y > odtw.y)
            cout << 'D';
        else if (droga[i].x > odtw.x)
            cout << 'P';
        else
            cout << 'L';
        odtw = droga[i];
    }

    return 0;
}
