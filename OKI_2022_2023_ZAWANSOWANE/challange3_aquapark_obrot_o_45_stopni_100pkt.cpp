#include <iostream>
#include <vector>

using namespace std;

struct Punkt
{
    int y;
    int x;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int r = 0;
    long long wczytana_liczba;
    int x_ratownika = 0;
    int y_ratownika = 0;
    int promien_ratownika = 0;

    cin >> n >> r;
    int wczytana_szachownica[n][n];
    vector<vector<int>> basen (n*2-1, vector<int>(n*2-1));
    vector<vector<long long>> basen_prefix (n*2-1, vector<long long>(n*2-1));
    Punkt wystapienia[n][n]; // Tablica mowi nam jaki idx ma dana wspolrzedna w 2 tablicy.

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytana_liczba;
            wczytana_szachownica[i][j] = wczytana_liczba;
        }
    }

    for (int i = 0; i < ((n * 2) -1); ++i)
    {
        for (int j = 0; j < ((n * 2) -1); ++j)
        {
            basen[i][j] = 0;
        }
    }

    int ile_razy = 1;
    int poczatek_x = n-1;
    int poczatek_y = 0;

    for (int i = 0; i < n; ++i)
    {
        int x = 0;
        int y = i;
        for (int j = 0; j < ile_razy; ++j)
        {
            basen[poczatek_y][poczatek_x+(2*j)] = wczytana_szachownica[y][x];
            wystapienia[y][x] = {poczatek_y,poczatek_x+(2*j)};
            y--;
            x++;
        }
        ile_razy++;
        poczatek_y++;
        poczatek_x--;
    }

    ile_razy = n-1;
    poczatek_x = 1;
    poczatek_y = n;
    for (int i = 1; i < n; ++i)
    {
        int x = i;
        int y = n-1;
        for (int j = 0; j < ile_razy; ++j)
        {
            basen[poczatek_y][poczatek_x+(2*j)] = wczytana_szachownica[y][x];
            wystapienia[y][x] = {poczatek_y,poczatek_x+(2*j)};
            y--;
            x++;
        }
        ile_razy--;
        poczatek_x++;
        poczatek_y++;
    }

    basen_prefix[0][0] = basen[0][0];
    for (int i = 1; i < n*2-1; ++i)
    {
        basen_prefix[0][i] = basen_prefix[0][i-1] + basen[0][i];
    }
    for (int i = 1; i < n*2-1; ++i)
    {
        basen_prefix[i][0] = basen_prefix[i-1][0] + basen[i][0];
    }

    for (int i = 1; i < n*2-1; ++i)
    {
        for (int j = 1; j < n*2-1; ++j)
        {
            basen_prefix[i][j] = basen_prefix[i-1][j] - basen_prefix[i-1][j-1] + basen[i][j] + basen_prefix[i][j-1];
        }
    }

    for (int i = 0; i < r; ++i)
    {
        cin >> y_ratownika >> x_ratownika >> promien_ratownika;
        long long suma = 0;
        int p_x = wystapienia[y_ratownika-1][x_ratownika-1].x - promien_ratownika;
        p_x = max(p_x,0);

        int k_x = wystapienia[y_ratownika-1][x_ratownika-1].x + promien_ratownika;
        k_x = min(k_x,n*2-2);

        int p_y = wystapienia[y_ratownika-1][x_ratownika-1].y - promien_ratownika;
        p_y = max(p_y,0);

        int k_y = wystapienia[y_ratownika-1][x_ratownika-1].y + promien_ratownika;
        k_y = min(k_y,n*2-2);

        suma = basen_prefix[k_y][k_x];
        if (p_y != 0)
        {
            suma -= basen_prefix[p_y-1][k_x];
        }
        if (p_x != 0)
        {
            suma -= basen_prefix[k_y][p_x-1];
        }
        if (p_x != 0 && p_y != 0)
        {
            suma += basen_prefix[p_y-1][p_x-1];
        }

        printf("%lld \n",suma);
    }


    return 0;
}