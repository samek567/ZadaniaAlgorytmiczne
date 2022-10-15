#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n = 0;
    long long m = 0;
    long long q = 0;
    long long max_wynik = 0;
    long long wczytany_x = 0;
    long long wczytany_y = 0;
    long long s = 0;

    cin >> n >> m >> q;

    long long kolumny[n+1] {0};
    long long wiersze[m+1] {0};
    long long przekatne_a[n+m] {0};
    long long przekatne_b[n+m] {0};

    for (int i = 0; i < q; ++i)
    {
        cin >> wczytany_x >> wczytany_y;

        long long s_obrot = n - wczytany_x + 1 + wczytany_y;

        s = wczytany_x + wczytany_y;

        przekatne_a[s-1]++;
        przekatne_b[s_obrot-1]++;

        kolumny[wczytany_x]++;
        wiersze[wczytany_y]++;
        max_wynik = max(max_wynik,kolumny[wczytany_x]);
        max_wynik = max(max_wynik,wiersze[wczytany_y]);
        max_wynik = max (max_wynik,przekatne_a[s-1]);
        max_wynik = max(max_wynik,przekatne_b[s_obrot-1]);

        cout << max_wynik << endl;
    }

    return 0;
}