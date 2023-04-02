#include <iostream>

using namespace std;

int n = 0, k = 0, poczatek = 0, koniec = 0, srodek = 0, ile_w_gasienicy = 0;
string ciag;

inline bool czy_pasuje(int x)
{
    if (x > n)
        return false;
    ile_w_gasienicy = 0;
    for (int i = 0; i < x; ++i)
        if (ciag[i] == '0' and (i == 0 or ciag[i-1] == '1'))
            ile_w_gasienicy++;
    if (ile_w_gasienicy <= k)
        return true;
    for (int i = x; i < n; ++i)
    {
        if (ciag[i] == '0' and ciag[i-1] == '1')
            ile_w_gasienicy++;
        if (ciag[i-x] == '0' and ciag[i-x+1] == '1')
            ile_w_gasienicy--;
        if (ile_w_gasienicy <= k)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> ciag;

    poczatek = 0, koniec = n+5;
    while(koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_pasuje(srodek) == true)
            poczatek = srodek;
        else
            koniec = srodek;
    }

    cout << poczatek << '\n';

    return 0;
}