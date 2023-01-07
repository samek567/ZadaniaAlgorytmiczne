#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n = 0, q = 0,  poczatek = 0, koniec = 0, srodek = 0;
ll wczytana_liczba = 0;
vector<int> liczby;
vector<ll> sumy_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    sort(liczby.begin(),liczby.end(),greater<int>());
    sumy_prefiksowe.push_back(liczby[0]);
    for (int i = 1; i < n; ++i)
        sumy_prefiksowe.push_back(sumy_prefiksowe[i-1] + liczby[i]);
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> wczytana_liczba;
        poczatek = -1, koniec = n;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (sumy_prefiksowe[srodek] >= wczytana_liczba)
                koniec = srodek;
            else
                poczatek = srodek;
        }
        printf("%d\n",koniec+1);
    }
    return 0;
}