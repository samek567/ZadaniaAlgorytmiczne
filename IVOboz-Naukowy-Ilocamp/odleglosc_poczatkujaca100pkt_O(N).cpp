#include <iostream>

using namespace std;

int n = 0, wczytana_liczba = 0, max_I = -1e9, max_J = -1e9;

int main()
{
    // O(N), maksymalizujemy wyrazenie A_i + A_j + j - i, biorac najwieksze mozliwe A_i + i, oraz najwieksze mozliwe A_j + j.
    // Dodajemy te 2 wyrazenie(maksymalne) do siebie, i to jest wynik.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        max_I = max(max_I, wczytana_liczba - i);
        max_J = max(max_J, wczytana_liczba + i);
    }

    cout << max_I + max_J << '\n';

    return 0;
}