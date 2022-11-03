#include <iostream>

using namespace std;

long long n = 0, m = 0, min_wartosc = 10e17, wczytana_liczba = 0;

int main()
{
    // Zadanie Minimum Maxiumum z Code Chef. Opiera sie na prostej obserwacji, ze zawsze najlepiej porownywac nam kazda liczbe z najmniejsza.
    // O(n)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m;

    for (int i = 0; i < m; ++i)
    {
        min_wartosc = 10e17;

        cin >> n;

        for (int j = 0; j < n; ++j)
        {
            cin >> wczytana_liczba;
            min_wartosc = min(min_wartosc,wczytana_liczba);
        }

        cout << min_wartosc * (n-1) << endl;
    }
    return 0;
}
