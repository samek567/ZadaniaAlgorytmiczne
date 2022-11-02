#include <iostream>
#include <map>

using namespace std;

int t = 0, n = 0, wczytana_liczba = 0;
long long wynik = 0;

int main()
{
    /* Zadanie Same Differences z Code Forces. Opiera sie na prostej obserwacji ze jesli chcemy zeby i oraz j pasowało,to l[i] = i + x, l[j] = j + x.
       gdzie x to dowolna liczba całkowita oraz i oraz j to rozne idx-y w ciagu n.
    */
    // O(q * n * log n), bo operacje na mapie wykonuja sie w O(log n) a dla kazdego zapytania jest kolo n. Wiemy z tresci zadania, ze sumaryczne n nie przekracza 2 * 10^5.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    for (int z = 0; z < t; ++z)
    {
        map<long long,long long> przesuniecie; // Przesuniecie wartosci wzgledem idx-u.
        wynik = 0;

        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> wczytana_liczba;
            int przes = wczytana_liczba - i;
            if (auto it = przesuniecie.find(przes) != przesuniecie.end()) // Znalezlismy
            {
                przesuniecie[przes]++;
            }
            else
            {
                przesuniecie[przes] = 1;
            }
        }

        for (auto i : przesuniecie)
        {
            wynik += i.second * (i.second-1) / 2; // Wzor na liczbe przywitan
        }
        cout << wynik << endl;
    }
    return 0;
}
