#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long wysokosc = 0;
    long long szerokosc = 0;
    long long t_max_kolumny = 0;
    long long b_max_kolumny = 0;
    long long t_max_wiersze = 0;
    long long b_max_wiersze = 0;
    long long idx_max_kolumny = 0;
    long long idx_max_wiersza = 0;
    long long licznik_pionkow = 0;
    long long wynik = 0;
    char znak;

    cin >> wysokosc >> szerokosc;

    int szachownica[wysokosc][szerokosc];

    for (int i = 0; i < wysokosc; i++)
    {
        for (int j = 0; j < szerokosc; j++)
        {
            cin >> znak;
            if (znak == '#')
            {
                szachownica[i][j] = 1;
                licznik_pionkow++;
            }
            else
            {
                szachownica[i][j] = 0;
            }
        }
    }

    // Szuakmy maksa w kolumnach

    for (int i = 0; i < szerokosc; i++)
    {
        b_max_kolumny = 0;
        for (int j = 0; j < wysokosc; j++)
        {
            if (szachownica[j][i] == 1)
            {
                b_max_kolumny++;
            }
        }
        if (b_max_kolumny > t_max_kolumny)
        {
            t_max_kolumny = b_max_kolumny;
            idx_max_kolumny = i;
        }
    }

    // Szuakmy maksa w wierszach

    for (int i = 0; i < wysokosc; i++)
    {
        b_max_wiersze = 0;
        for (int j = 0; j < szerokosc; j++)
        {
            if (szachownica[i][j] == 1)
            {
                b_max_wiersze++;
            }
        }
        if (b_max_wiersze > t_max_wiersze)
        {
            t_max_wiersze = b_max_wiersze;
            idx_max_wiersza = i;
        }
    }

    // Na kazde pole mozemy przejsc max 2 ruchami. Wynik to 2 * liczba pionków - najwieksza liczba pionow w wiersach i najwieksza liczba pionów w kolumnach.
    // Dlatego, bo tam mozemy przejsc nie 2 tylko 1 ruchem. Nie musimy sprawdzac czy pole pokrywania sie wierszy jest pionek, bo uwzgledniamy to szukaniu max-kolumn, max-wierszy.
    wynik = (2 * licznik_pionkow) - t_max_kolumny - t_max_wiersze;

    printf("%lld",wynik);
    return 0;
}