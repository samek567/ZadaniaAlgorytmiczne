#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    long long wynik = 0;
    long long wczytana_liczba = 0;
    long long licznik_ujemnych = 0;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba < 0)
        {
            licznik_ujemnych++;
        }
    }

    wynik = licznik_ujemnych * (n-1);

    cout << wynik;
    return 0;
}