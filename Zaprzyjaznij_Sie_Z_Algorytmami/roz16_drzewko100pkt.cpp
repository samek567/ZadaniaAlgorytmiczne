#include <iostream>

using namespace std;

long long n = 0, k = 0, lewo = 1, prawo = 1, ile_dziel = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    lewo = 1;
    prawo = ((long long)1 << k) / 2;
    ile_dziel = ((long long)1 << k) / 4;

    for (int i = 0; i < k-1; ++i)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            lewo += ile_dziel;
        }
        else
        {
            n = n / 2 + 1;
            prawo -= ile_dziel;
        }
        ile_dziel /= 2;
    }

    printf("%lld",lewo-1);

    return 0;
}
