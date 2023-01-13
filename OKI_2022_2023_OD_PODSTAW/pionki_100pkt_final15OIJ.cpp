#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, ile_pionkow = 0, suma = 0, wyn = 1e9;
char wczytany_znak;
vector<vector<char>> plansza;
vector<int> ile_pionkow_wiersze; // Ile pionkow jest w it-ym wierszu
vector<int> ile_pionkow_kolumny; // Ile pionkow jest w it-ej kolumnie

int main()
{
    // O(n*m) Sumy prefiksowe
    // Dla kazdego pola liczba sprowadzenia to dla tych co sa w tym samym wierszu lub kolumnie co pole sprawdzane to 1, dla innych to 2.
    // Dlatego naliczamy sumy prefiksowe dla kazdego wiersza i kazdej kolumny.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        plansza.push_back({});
        for (int j = 0; j < m; ++j)
        {
            cin >> wczytany_znak;
            plansza[i].push_back(wczytany_znak);
            if (wczytany_znak == '#')
                ile_pionkow++;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        suma = 0;
        for (int j = 0; j < m; ++j)
            if (plansza[i][j] == '#')
                suma++;
        ile_pionkow_wiersze.push_back(suma);
    }
    for (int i = 0; i < m; ++i)
    {
        suma = 0;
        for (int j = 0; j < n; ++j)
            if (plansza[j][i] == '#')
                suma++;
        ile_pionkow_kolumny.push_back(suma);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (plansza[i][j] == '.')
                wyn = min(wyn,ile_pionkow_wiersze[i] + ile_pionkow_kolumny[j] + (ile_pionkow - (ile_pionkow_wiersze[i] + ile_pionkow_kolumny[j])) * 2);
            else
                wyn = min(wyn,(ile_pionkow_wiersze[i] + ile_pionkow_kolumny[j] - 2) + (ile_pionkow - (ile_pionkow_wiersze[i] + ile_pionkow_kolumny[j] - 1)) * 2);
        }
    }

    printf("%d",wyn);

    return 0;
}