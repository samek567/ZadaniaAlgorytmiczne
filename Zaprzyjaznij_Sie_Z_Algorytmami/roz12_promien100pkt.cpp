#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0, pocz_zap = 0, kon_zap = 0;
long long sum = 0, suma_na_przedziale = 0;
vector<int> do_ulozenia;
vector<long long> sumy_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        sum += wczytana_liczba;
        sumy_prefiksowe.push_back(sum);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        do_ulozenia.push_back(wczytana_liczba);
    }

    for (int i = 0; i < n; ++i)
    {
        poczatek = -1, koniec = n;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            pocz_zap = max(i - srodek, 0);
            kon_zap = min(i + srodek, n-1);
            if (pocz_zap == 0)
                suma_na_przedziale = sumy_prefiksowe[kon_zap];
            else
                suma_na_przedziale = sumy_prefiksowe[kon_zap] - sumy_prefiksowe[pocz_zap-1];
            if (suma_na_przedziale < do_ulozenia[i])
                poczatek = srodek;
            else
                koniec = srodek;
        }
        if (koniec == n)
            printf("-1 ");
        else
            printf("%d ",koniec);
    }
    return 0;
}
