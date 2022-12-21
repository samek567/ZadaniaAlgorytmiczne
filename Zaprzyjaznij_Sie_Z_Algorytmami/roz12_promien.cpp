#include <iostream>
#include <vector>

using namespace std;

int n = 0;
long long wczytana_liczba = 0;
vector<long long> szukana_suma;
vector<long long> sumy_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    sumy_prefiksowe.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        sumy_prefiksowe.push_back(sumy_prefiksowe[i] + wczytana_liczba);
    }
    szukana_suma.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        szukana_suma.push_back(wczytana_liczba);
    }

    for (int i = 1; i <= n; ++i)
    {
        int poczatek = -1, koniec = n, srodek = 0, pocz_zapytanie = 0, kon_zapytanie = 0;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            pocz_zapytanie = i - srodek;
            kon_zapytanie = i + srodek;
            pocz_zapytanie = max(pocz_zapytanie,1);
            kon_zapytanie = min(kon_zapytanie,n);
            if (sumy_prefiksowe[kon_zapytanie] - sumy_prefiksowe[pocz_zapytanie-1] >= szukana_suma[i])
                koniec = srodek;
            else
                poczatek = srodek;
        }
        if (koniec == n)
            printf("-1");
        else
            printf("%d ",koniec);
    }

    return 0;
}
