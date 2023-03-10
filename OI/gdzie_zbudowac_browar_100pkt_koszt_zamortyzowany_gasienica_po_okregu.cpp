#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, a = 0, b = 0, wsk = 0, suma_zapotrzebowanie_poza_gasienica = 0, suma_zapotrzebowanie_w_gasienicy = 0, suma_dojscie_w_gasienicy = 0, suma_dojscie_poza_gasienica = 0, suma = 0;
ll wyn = 0, min_wyn = 1e18;
vector<int> zapotrzebowanie;
vector<int> krawedzie_przod;
vector<int> krawedzie_tyl;
vector<int> koszt;
vector<int> kto_nalezy;

int main()
{
    // O(N), koszt zamortyzowany, cos w stylu gasienicy po okregu.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    zapotrzebowanie.assign(n+1,-1);
    krawedzie_przod.assign(n+1,-1);
    krawedzie_tyl.assign(n+1,-1);
    koszt.assign(n+1,1e18);
    kto_nalezy.assign(n+1,-1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        zapotrzebowanie[i] = a;
        krawedzie_przod[i] = b;
        if (i == n)
            krawedzie_tyl[1] = b;
        else
            krawedzie_tyl[i+1] = b;
    }

    koszt[1] = 0;
    kto_nalezy[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        suma += krawedzie_tyl[i];
        koszt[i] = suma;
        kto_nalezy[i] = 0;
    }

    suma = 0;
    for (int i = n; i > 1; --i)
    {
        suma += krawedzie_przod[i];
        if (suma < koszt[i])
        {
            koszt[i] = suma;
            kto_nalezy[i] = 1;
        }
    }

    for (int i = 1; i <= n; ++i)
        wyn += (ll)koszt[i] * (ll)zapotrzebowanie[i];
    min_wyn = wyn;

    wsk = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (kto_nalezy[i] == 0)
        {
            wsk = i;
            suma_zapotrzebowanie_w_gasienicy += zapotrzebowanie[i];
            suma_dojscie_w_gasienicy += krawedzie_tyl[i];
        }
        else
        {
            suma_zapotrzebowanie_poza_gasienica += zapotrzebowanie[i];
            suma_dojscie_poza_gasienica += krawedzie_przod[i];
        }
    }

    suma_zapotrzebowanie_w_gasienicy += zapotrzebowanie[1];
    for (int i = 2; i <= n; ++i)
    {
        suma_zapotrzebowanie_poza_gasienica += zapotrzebowanie[i-1];
        suma_zapotrzebowanie_w_gasienicy -= zapotrzebowanie[i-1];
        wyn -= (ll)suma_zapotrzebowanie_w_gasienicy * (ll)krawedzie_tyl[i];
        wyn += (ll)suma_zapotrzebowanie_poza_gasienica * (ll)krawedzie_tyl[i];
        suma_dojscie_w_gasienicy -= krawedzie_tyl[i];
        suma_dojscie_poza_gasienica += krawedzie_tyl[i];
        kto_nalezy[i-1] = 1;
        while(true)
        {
            int wierz;
            if (wsk == n)
                wierz = 1;
            else
                wierz = wsk+1;
            if (kto_nalezy[wierz] == 0)
                break;
            if (suma_dojscie_w_gasienicy + krawedzie_przod[wsk] < suma_dojscie_poza_gasienica)
            {
                kto_nalezy[wierz] = 0;
                wyn -= (ll)zapotrzebowanie[wierz] * (ll)suma_dojscie_poza_gasienica;
                suma_zapotrzebowanie_w_gasienicy += zapotrzebowanie[wierz];
                suma_dojscie_w_gasienicy += krawedzie_przod[wsk];
                suma_dojscie_poza_gasienica -= krawedzie_przod[wierz];
                wyn += (ll)zapotrzebowanie[wierz] * (ll)suma_dojscie_w_gasienicy;
                suma_zapotrzebowanie_poza_gasienica -= zapotrzebowanie[wierz];
                wsk = wierz;
            }
            else
                break;
        }
        min_wyn = min(min_wyn, wyn);
    }

    cout << min_wyn << '\n';

    return 0;
}
