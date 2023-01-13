#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

ull t = 0, m = 0, n = 0, poczatek = -1, koniec = n+1, srodek = 0;

int main()
{
    // O(t * log n) - wyszukiwanie binarne po wyniku.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> m;
        poczatek = 0, koniec = n+1, srodek = 0;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (pow(srodek,m) <= n)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        cout << poczatek << endl;
    }
    return 0;
}