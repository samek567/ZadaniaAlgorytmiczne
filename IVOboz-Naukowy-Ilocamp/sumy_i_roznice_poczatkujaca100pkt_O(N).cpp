#include <iostream>

using namespace std;
typedef long long ll;

ll n = 0, wczytana_liczba = 0, ile_ujemnych = 0, wyn = 0;

int main()
{
    // O(N), zauwazamy ze do kazdej liczby ujemnej, mozemy ulozyc pare szukana na wejsciu.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba < 0)
            ile_ujemnych++;
    }

    wyn = ile_ujemnych * (n-1);

    cout << wyn << '\n';

    return 0;
}