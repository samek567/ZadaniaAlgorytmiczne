#include <iostream>

using namespace std;
typedef long long ll;
ll z = 0, p = 0, q = 0, poczatek = 0, koniec = 0, srodek = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> z;
    for (int i = 0; i < z; ++i)
    {
        cin >> p >> q;
        poczatek = -1, koniec = 1e6+5;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (srodek * srodek * srodek + p * srodek > q)
                koniec = srodek;
            else
                poczatek = srodek;
        }
        if (poczatek * poczatek * poczatek + p * poczatek == q)
            printf("%lld\n",poczatek);
        else
            printf("NIE\n");
    }
    return 0;
}