#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
long long wczytana_liczba = 0, suma = 0, wynik = 0, max_wolne = 0;
vector<long long> dziury;

int main()
{
    // Zadanie tapczany internetowe turnieje programistyczne
    // Zadanie opiera sie na prostej obserwacji: zawsze oplaca nam sie pokryc najwieksza dziure.
    // O(n log n) ze wzgledu na sortowanie.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        dziury.push_back(wczytana_liczba);
    }

    sort(dziury.begin(),dziury.end());

    for (int i = 0; i < n - 1; ++i)
    {
        suma += dziury[i+1] - dziury[i];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        max_wolne = max(max_wolne,dziury[i+1] - dziury[i]);
    }

    wynik = suma - max_wolne;

    cout << wynik;

    return 0;
}
