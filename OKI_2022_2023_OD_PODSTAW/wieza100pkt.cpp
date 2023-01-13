#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, max_val = -1e9, poczatek = 0, koniec = 0, srodek = 0;
vector<int> maxe_prefixowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        max_val = max(max_val,wczytana_liczba);
        maxe_prefixowe.push_back(max_val);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        poczatek = -1, koniec = n;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (wczytana_liczba > maxe_prefixowe[srodek])
                poczatek = srodek;
            else
                koniec = srodek;
        }
        printf("%d ",poczatek+1);
    }
    return 0;
}