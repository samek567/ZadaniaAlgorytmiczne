#include <iostream>

using namespace std;

long long n = 0, poczatek = 0, koniec = 0, srodek = 0, szukana = 0;

long long cnt(long long x)
{
    long long wyn = 0;
    long long ile_wsk = n;
    long long val = n;
    long long i = 1;

    while (i <= n)
    {
        while (val > x)
        {
            val -= i;
            --ile_wsk;
        }
        wyn += ile_wsk;
        val += ile_wsk;
        ++i;
    }

    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    poczatek = 0;
    koniec = n * n + 1;
    szukana = n * n / 2 + 1;

    while (koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (cnt(srodek) >= szukana)
            koniec = srodek;
        else
            poczatek = srodek;
    }

    printf("%lld",koniec);

    return 0;
}