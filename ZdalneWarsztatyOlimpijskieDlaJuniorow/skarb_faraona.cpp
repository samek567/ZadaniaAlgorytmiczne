#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int m = 0;
    long long wczytana_waga = 0;
    long long wczytana_wartosc = 0;
    long long max_wynik = 0;

    cin >> n >> m;

    long long koszty[m+1] {0};

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_waga >> wczytana_wartosc;
        for (int j = m; j >= 1; --j)
        {
            if (koszty[j] == 0)
            {
                continue;
            }
            if (j + wczytana_waga <= m)
            {
                koszty[j+wczytana_waga] = max(koszty[j+wczytana_waga],koszty[j]+wczytana_wartosc);
            }
        }
        if (wczytana_waga <= m)
        {
            koszty[wczytana_waga] = max(koszty[wczytana_waga],wczytana_wartosc);
        }

    }

    for (int i = 1; i <= m; ++i)
    {
        max_wynik = max(max_wynik,koszty[i]);
        //cout << koszty[i] << endl;
    }

    cout << max_wynik;
    return 0;
}