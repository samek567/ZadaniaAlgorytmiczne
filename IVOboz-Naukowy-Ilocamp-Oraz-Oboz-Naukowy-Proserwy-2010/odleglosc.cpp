#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    long long max_wynik = 0;

    cin >> n;
    long long wczytana_liczba = 0;
    long long max_i = 0;
    long long max_j = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        max_i = max(max_i,wczytana_liczba - i);
        max_j = max(max_j,wczytana_liczba + i);
    }

    cout << max_i + max_j;
    return 0;
}