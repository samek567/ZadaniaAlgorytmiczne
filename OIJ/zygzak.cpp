#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll a = 0, b = 0, c = 0, d = 0, wysokosc = 0, GCD = 0;
string ciag;

int main()
{
    /*
    O(n)
    a - wysokosc duzego prostokata
    b - szerokosc duzego prostokata
    c - wysokosc malego prostokata
    d - szerokosc malego prostokata
    Korzystamy z tw. Talesa a / b = c / d => a / b * c = d.
    Sprawdzamy czy mozemy isc jedno w gore. Mozemy gdy c + 1 < d.
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag;
    for (int i = 0; i < ciag.size(); ++i)
    {
        if (ciag[i] == 'G')
            a++;
        else
            b++;
    }
    GCD = __gcd(a,b);
    a /= GCD;
    b /= GCD;

    for (int i = 0; i < ciag.size(); ++i)
    {
        if (d == 0)
            wysokosc = 0;
        else
            wysokosc = (long double)a * (long double)d / (long double)b;
        if ((long double)c+1 <= wysokosc) // Idziemy w gore
        {
            if (ciag[i] == 'P')
            {
                printf("NIE");
                return 0;
            }
            else
                c++;
        }
        else // Idziemy w prawo
        {
            if (ciag[i] == 'G')
            {
                printf("NIE");
                return 0;
            }
            else
                d++;
        }
    }
    printf("%lld/%lld",a,b);

    return 0;
}