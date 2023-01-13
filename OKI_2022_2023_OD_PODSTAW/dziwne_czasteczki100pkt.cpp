#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n = 0, k = 0, wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0;
long long wyn = 0, sum = 0;
vector<int> liczby;
vector<long long> sumy_prefiksowe;

int main()
{
    // O(n log n)
    // Dla kazdej czasteczki szukamy binarnie ostatniej takiej, ktora oddzialowywuje za k.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    sort(liczby.begin(),liczby.end());
    sumy_prefiksowe.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        sum += liczby[i];
        sumy_prefiksowe.push_back(sum);
    }

    for (int i = 0; i < n-1; ++i)
    {
        poczatek = i;
        koniec = n;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (liczby[srodek] - liczby[i] <= k)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        wyn += (ll)(poczatek - i) * (ll)k; // Dodajemy te ktore sa <= k, wiec wchodza za k.
        wyn += (sumy_prefiksowe[n] - sumy_prefiksowe[poczatek+1]); // Dodajemy sume tych ktore > k
        wyn -= (ll)(n-poczatek-1) * (ll)liczby[i]; // Odejmujemy tyle liczby[i] ile wchodzi za > k.
    }

    printf("%lld",wyn);

    return 0;
}