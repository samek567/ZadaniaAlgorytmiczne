#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, lewy_wsk = 0, prawy_wsk = 0;
long long wyn = 0;
vector<int> smakolyki;
vector<bool> czy_w_gasienicy;

inline void przesuwaj_lewy()
{
    wyn += prawy_wsk - lewy_wsk + 1; // Suma ciagu.
    czy_w_gasienicy[smakolyki[lewy_wsk]] = false;
    lewy_wsk++;
    if (lewy_wsk > prawy_wsk)
    {
        prawy_wsk = lewy_wsk;
        czy_w_gasienicy[smakolyki[lewy_wsk]] = true;
    }
}

int main()
{
    // Gasienica O(n + m)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    czy_w_gasienicy.assign(m+1,false);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        smakolyki.push_back(wczytana_liczba);
    }

    // rozszerzamy gasienice dopoki mozemy, jak nie to liczymy wynik.
    czy_w_gasienicy[smakolyki[0]] = true;
    while(lewy_wsk < n)
    {
        if (prawy_wsk == n-1) // przesuwamy lewy wskaznik.
        {
            przesuwaj_lewy();
        }
        else if (czy_w_gasienicy[smakolyki[prawy_wsk+1]] == true) // przesuwamy lewy wskaznik.
        {
            przesuwaj_lewy();
        }
        else // Przesuwamy prawy wskaznik.
        {
            czy_w_gasienicy[smakolyki[prawy_wsk+1]] = true;
            prawy_wsk++;
        }
    }

    printf("%lld",wyn);

    return 0;
}
