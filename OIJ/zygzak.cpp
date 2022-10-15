#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ciag;
    double wysokosc_g = 0;
    double szerokosc_g = 0;
    long long wysokosc_g_int = 0;
    long long szerokosc_g_int = 0;
    double proporcja_g = 0;
    double proporcja_b = 0;
    double wysokosc_b = 0;
    double szerokosc_b = 0;
    cin >> ciag;
    for (int i = 0; i < ciag.size(); i++)
    {
        if (ciag[i] == 'P')
        {
            szerokosc_g++;
            szerokosc_g_int++;
        }
        else
        {
            wysokosc_g++;
            wysokosc_g_int++;
        }
    }

    proporcja_g = wysokosc_g / szerokosc_g;

    for (int i = 0; i < ciag.size(); i++)
    {
        proporcja_b = (wysokosc_b+1) / szerokosc_b;
        if (proporcja_b <= proporcja_g)
        {
            if (ciag[i] == 'G')
            {
                wysokosc_b++;
            }
            else
            {
                cout << "NIE";
                return 0;
            }
        }
        else
        {
            if (ciag[i] == 'P')
            {
                szerokosc_b++;
            }
            else
            {
                cout << "NIE";
                return 0;
            }
        }
    }

    cout << (wysokosc_g_int / __gcd(wysokosc_g_int,szerokosc_g_int)) << "/" << (szerokosc_g_int / __gcd(wysokosc_g_int,szerokosc_g_int));
    return 0;
}