#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Znak
{
    long long p;
    long long k;
    double predkosc;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long liczba_znakow = 0;
    long long dlugosc_odcinka = 0;
    long long dlugosc_trasy = 0;
    long long max_przesuniecie = 0;
    long long wskazywany_lewo = 0;
    long long wskazywany_prawo = 0;
    long long wskaznik_lewo = 0;
    long long wskaznik_prawo = 0;
    double wynik = 0;
    double min_wynik = 0;

    cin >> liczba_znakow >> dlugosc_odcinka >> dlugosc_trasy;

    Znak znaki[liczba_znakow];

    for (int i = 0; i < liczba_znakow; ++i)
    {
        cin >> znaki[i].p >> znaki[i].predkosc;
        if (i != 0)
        {
            znaki[i-1].k = znaki[i].p;
        }
    }
    znaki[liczba_znakow-1].k = dlugosc_trasy;


    // Ustawiamy poczatek i koniec gasienicy
    wskaznik_lewo = 0;
    wskaznik_prawo = 0;

    for (int i = 0; i < liczba_znakow; ++i)
    {
        if (znaki[i].k < dlugosc_odcinka)
        {
            wskaznik_prawo += znaki[i].k - wskaznik_prawo;
            wynik += (znaki[i].k - znaki[i].p) / znaki[i].predkosc;
        }
        else if (znaki[i].k  == dlugosc_odcinka)
        {
            wskaznik_prawo += znaki[i].k - wskaznik_prawo;
            wynik += (znaki[i].k - znaki[i].p) / znaki[i].predkosc;
            wskazywany_prawo = i;
            break;
        }
        else if (znaki[i].k > dlugosc_odcinka)
        {
            // Sprawdzamy dopelnienie
            wynik += (dlugosc_odcinka - wskaznik_prawo) / znaki[i].predkosc;
            wskaznik_prawo += dlugosc_odcinka - wskaznik_prawo;
            wskazywany_prawo = i;
            break;
        }

    }
    min_wynik = wynik;
    wskazywany_lewo = 0;

    while (wskaznik_prawo < dlugosc_trasy)
    {
        max_przesuniecie = min((znaki[wskazywany_lewo].k - wskaznik_lewo),(znaki[wskazywany_prawo].k - wskaznik_prawo));
        wskaznik_lewo += max_przesuniecie;
        wskaznik_prawo += max_przesuniecie;
        wynik -= max_przesuniecie / znaki[wskazywany_lewo].predkosc;
        wynik += max_przesuniecie / znaki[wskazywany_prawo].predkosc;
        if (wynik < min_wynik)
        {
            min_wynik = wynik;
        }
        if (wskaznik_prawo == znaki[wskazywany_prawo].k)
        {
            wskazywany_prawo++;
        }
        if (wskaznik_lewo == znaki[wskazywany_lewo].k)
        {
            wskazywany_lewo++;
        }
    }

    cout << fixed << setprecision(3) << min_wynik;
    return 0;
}