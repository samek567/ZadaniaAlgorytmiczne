#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;

    cin >> n;
    int pref = 0;
    int wczytana_liczba = 0;
    long long wynik = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba == 0)
        {
            pref++;
        }
        else
        {
            wynik += pref;
        }
    }

    cout << wynik;
    return 0;
}