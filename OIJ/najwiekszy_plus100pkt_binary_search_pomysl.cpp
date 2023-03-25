#include <iostream>
#include <vector>

using namespace std;

int n = 0, poczatek = 0, koniec = 0, srodek = 0, ile_pod_rzad = 0;
vector<int> wysokosci;
vector<int> sumy_prefiksowe;

inline bool czy_pasuje(int x)
{
    ile_pod_rzad = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ile_pod_rzad == x)
        {
            if (wysokosci[i] >= 2*x+1)
                ile_pod_rzad++;
            else if (wysokosci[i] <= x)
                ile_pod_rzad = 0;
        }
        else
        {
            if (wysokosci[i] > x)
                ile_pod_rzad++;
            else
                ile_pod_rzad = 0;
        }
        if (ile_pod_rzad == 2*x+1)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    sumy_prefiksowe.assign(n,-1);
    wysokosci.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> wysokosci[i];

    poczatek = 0, koniec = 4e5+20;
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