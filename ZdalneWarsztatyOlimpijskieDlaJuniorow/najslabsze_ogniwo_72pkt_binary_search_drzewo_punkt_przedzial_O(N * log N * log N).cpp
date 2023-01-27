#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int n = 0, wczytana_liczba = 0, base = 0, rozmiar_drzewa = 0, idx_ostatni = 0, idx_pierwszy = 0, poczatek = 0, koniec = 0, srodek = 0, wsk = 0;
ll wyn = 0;
vector<int> liczby;
vector<int> drzewa_przedzialowe;
vector<ll> sumy_prefiksowe;

int querry(int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    int wyn_min = 1e9;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            wyn_min = min(wyn_min,drzewa_przedzialowe[l+1]);
        if (p % 2 == 1)
            wyn_min = min(wyn_min,drzewa_przedzialowe[p-1]);
        l /= 2;
        p /= 2;
    }
    return wyn_min;
}

int main()
{
    // O(n * log n * log n)
    // Dla kazdej liczby zakladamy, ze jest ona najmniejsza, i szukamy binarnie z drzewem przedzialowym najdluzeszgo takiego przedzialu.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    base = (1 << int(ceil((double)log2(n))));
    rozmiar_drzewa = base * 2;
    drzewa_przedzialowe.assign(rozmiar_drzewa,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    for (int i = 0; i < n; ++i)
        drzewa_przedzialowe[base + i] = liczby[i];
    for (int i = base-1; i > 0; --i)
        drzewa_przedzialowe[i] = min(drzewa_przedzialowe[i*2],drzewa_przedzialowe[i*2+1]);

    sumy_prefiksowe.push_back(0);
    for (int i = 0; i < n; ++i)
        sumy_prefiksowe.push_back(sumy_prefiksowe[i] + liczby[i]);

    for (int i = 0; i < n; ++i)
    {
        koniec = n, poczatek = i;
        int cnt = 0;
        while (koniec - poczatek > 1)
        {
            cnt++;
            srodek = (poczatek + koniec) / 2;
            if (querry(i,srodek) == liczby[i])
                poczatek = srodek;
            else
                koniec = srodek;
            if (cnt > 5000)
            {
                cout << "KK";
                return 0;
            }
        }
        idx_ostatni = poczatek;

        koniec = i, poczatek = -1;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (querry(srodek,i) == liczby[i])
                koniec = srodek;
            else
                poczatek = srodek;
            if (cnt > 5000)
            {
                cout << "KK";
                return 0;
            }
        }
        idx_pierwszy = koniec;

        wyn = max(wyn,(sumy_prefiksowe[idx_ostatni+1] - sumy_prefiksowe[idx_pierwszy]) * (ll)liczby[i]);
    }
    printf("%lld",wyn);
    return 0;
}