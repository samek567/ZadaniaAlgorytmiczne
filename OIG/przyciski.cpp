#include <iostream>

using namespace std;

int przyciski[1000005]{0};
int n = 0, m = 0, p = 0, licznik = 0,max_licznik = 0;

void uzupelnij_na_maxa()
{
    // Uzupelniamy tam gdzie niema jeszcze maxa.
    for (int i = 1; i <= n; ++i)
    {
        przyciski[i] = max(max_licznik,przyciski[i]);
    }
}

void wypisz_stan_przyciskow()
{
    // Iterujemy po przyciskach i wypisujemy ich stan.
    for (int i = 1; i <= n; ++i)
    {
        cout << przyciski[i] << " ";
    }
}

int main()
{
    // Przyspieszamy wejscie,wyjscie
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> p;
        if (p == n+1) // Jesli klikniêty jest n+1 przycisk
        {
            max_licznik = licznik;
            continue;
        }
        // To robi sie jesli nie zostal klikniety n+1 przycisk.
        przyciski[p] = max(przyciski[p],max_licznik);
        przyciski[p]++;
        licznik = max(licznik,przyciski[p]);
    }

    uzupelnij_na_maxa();

    wypisz_stan_przyciskow();

    return 0;
    // Nie musimy podczas (n+1 przycisku) uzupelniac wszystkich, wystarczy nam zmienna max_licznik, ktora przechowuje maxa i mozemy w O(1) uzupelnic maxa dla interesujacego nas przycisku,
    // nie musimy dla innych.
    // O(n), ponieważ wszystkie operacje robimy w O(1) a jest ich n.
    // Takie rozwiazanie daje 100 pkt z duzym zapasem.
}