#include <iostream>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    long long min_wynik = LLONG_MAX;
    long long wczytana_liczba = 0;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        min_wynik = min(min_wynik,wczytana_liczba);
    }

    cout << min_wynik << ".00";
    return 0;
}