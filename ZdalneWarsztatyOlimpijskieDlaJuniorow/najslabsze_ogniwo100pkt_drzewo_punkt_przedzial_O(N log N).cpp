#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, wczytana_liczba = 0, base = (1 << int(ceil((double)log2(1e6+2)))), rozmiar_drzewa = base * 2;
ll wyn = 0, sum = 0;
vector<int> drzewo_przedzialowe;
vector<int> liczby;
vector<int> L; // Idx na lewy ostatniego >=
vector<int> P; // Idx na prawo ostatniego >=
vector<ll> sumy_prefiksowe;

void update_max(int v, int val)
{
    v += base;
    drzewo_przedzialowe[v] = val;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe[v] = max(drzewo_przedzialowe[v*2],drzewo_przedzialowe[v*2+1]);
        v /= 2;
    }
}

void update_min(int v, int val)
{
    v += base;
    drzewo_przedzialowe[v] = val;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe[v] = min(drzewo_przedzialowe[v*2],drzewo_przedzialowe[v*2+1]);
        v /= 2;
    }
}

int querry_max(int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    int val = -1;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            val = max(val,drzewo_przedzialowe[l+1]);
        if (p % 2 == 1)
            val = max(val,drzewo_przedzialowe[p-1]);
        l /= 2;
        p /= 2;
    }
    return val;
}

int querry_min(int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    int val = 1e7+5;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            val = min(val,drzewo_przedzialowe[l+1]);
        if (p % 2 == 1)
            val = min(val,drzewo_przedzialowe[p-1]);
        l /= 2;
        p /= 2;
    }
    return val;
}

int main()
{
    // O(N * log N), podobny pomysl w zadaniu Promocja z finału 7 OI(łatwiejsze niż to zadanie).
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    drzewo_przedzialowe.assign(rozmiar_drzewa,-1);

    cin >> n;
    L.assign(n,-1);
    P.assign(n,-1);

    for(int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        sum += wczytana_liczba;
        sumy_prefiksowe.push_back(sum);
        liczby.push_back(wczytana_liczba);
    }

    // Szukamy max wynik.
    for (int i = 0; i < n; ++i)
    {
        L[i] = querry_max(0,liczby[i]-1);
        update_max(liczby[i],i);
    }

    drzewo_przedzialowe.assign(rozmiar_drzewa,1e7+5);

    for (int i = n-1; i >= 0; --i)
    {
        P[i] = querry_min(0,liczby[i]-1);
        update_min(liczby[i],i);
    }

    for (int i = 0; i < n; ++i)
    {
        int lewy_wsk_zap = 0, prawy_wsk_zap = 0; // Lewy wsk mowi jaki jest idx naszego przedzialu (poczatek), a prawy koniec, zakladajac, ze liczby[i] jest najmniejsza.
        if (L[i] == -1)
            lewy_wsk_zap = 0;
        else
            lewy_wsk_zap = L[i] + 1;
        if (P[i] == 1e7+5)
            prawy_wsk_zap = n-1;
        else
            prawy_wsk_zap = P[i] - 1;
        if (lewy_wsk_zap == 0 && prawy_wsk_zap == n-1)
            wyn = max(wyn,(ll)liczby[i] * sumy_prefiksowe[n-1]);
        else if (lewy_wsk_zap == 0)
            wyn = max(wyn,(ll)liczby[i] * sumy_prefiksowe[prawy_wsk_zap]);
        else if (prawy_wsk_zap == n-1)
            wyn = max(wyn,(ll)liczby[i] * (sumy_prefiksowe[n-1] - sumy_prefiksowe[lewy_wsk_zap-1]));
        else
            wyn = max(wyn,(ll)liczby[i] * (sumy_prefiksowe[prawy_wsk_zap] - sumy_prefiksowe[lewy_wsk_zap-1]));
    }

    printf("%lld\n",wyn);

    return 0;
}
