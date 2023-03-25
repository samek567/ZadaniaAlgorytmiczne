#include <iostream>
#include <vector>

using namespace std;

int n = 0, poczatek = 0, koniec = 0, srodek = 0, sum = 0;
vector<int> wysokosci;
vector<int> sumy_prefiksowe;

inline bool czy_pasuje(int x)
{
    sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (wysokosci[i] <= x)
            sum++;
        sumy_prefiksowe[i] = sum;
    }
    for (int i = x; i < n-x; ++i)
    {
        int ile = 0;
        if (i-x == 0)
            ile = sumy_prefiksowe[i+x];
        else
            ile = sumy_prefiksowe[i+x] - sumy_prefiksowe[i-x-1];
        if (wysokosci[i] >= 2*x+1 and ile == 0)
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

    poczatek = 0, koniec = 1e6+20;
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