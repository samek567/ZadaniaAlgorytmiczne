#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, suma = 0, suma_lewo = 0, min_wyn = 1e9;
vector<int> liczby;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        suma += wczytana_liczba;
    }

    for (int i = 0; i < n-1; ++i)
    {
        suma_lewo += liczby[i];
        min_wyn = min(min_wyn,abs(suma_lewo - (suma - suma_lewo)));
    }

    printf("%d",min_wyn);

    return 0;
}
