#include <iostream>

using namespace std;

long long k = 0, s = 0, suma_ciagu = 0, poczatek = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> s;

    suma_ciagu = (1 + k) * k / 2;

    if (suma_ciagu > s || (s-suma_ciagu) % k != 0)
    {
        printf("NIE");
        return 0;
    }

    poczatek = 1 + ((s-suma_ciagu) / k);

    for (int i = 0; i < k; ++i)
    {
        printf("%lld ",poczatek+i);
    }

    return 0;
}