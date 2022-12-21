#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Przedzial
{
    int poczatek;
    int koniec;
    bool operator < (const Przedzial &przedzial) const
    {
        if (poczatek == przedzial.poczatek)
            return koniec < przedzial.koniec;
        return poczatek < przedzial.poczatek;
    }
};

int n = 0, m = 0, a_i = 0, b_i = 0, wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0, max_ai = 0;
vector<Przedzial> przedzialy;
vector<int> gwozdzie;

bool czy_pasuje(int x) // Ile pierwszych desek bierzemy.
{
    int ile_mamy = 0;
    int wsk_gwozdzie = 0;
    vector<int> posortowane_gwozdzie;
    vector<bool> counting_sort;
    counting_sort.assign(max_ai+1, false);
    for (int i = 0; i < x; ++i)
        counting_sort[gwozdzie[i]] = true;
    for (int i = 1; i <= max_ai; ++i)
        if (counting_sort[i] == true)
            posortowane_gwozdzie.push_back(i);

    if (posortowane_gwozdzie.size() == 0)
        return false;

    for (int i = 0; i < n; ++i)
    {
        if (posortowane_gwozdzie[wsk_gwozdzie] < przedzialy[i].poczatek)
        {
            wsk_gwozdzie++;
            i--;
        }
        else if (posortowane_gwozdzie[wsk_gwozdzie] > przedzialy[i].koniec)
            return false;
        else
            ile_mamy++;
        if (wsk_gwozdzie == x)
            break;
    }

    if (ile_mamy == n)
        return true;
    else
        return false;
}

int main()
{
    /*
    O(n * log m), korzystamy z obserwacji, ze jesli mozemy pokryc x pierwszymi deskami, to mozemy tez x+1, x+2, x+3 itd, pierwszymi deskami
    oraz jesli nie mozemy pokryc x pierwszymi deskami, to nie mozemy tez pokryc x-1, x-2, x-3 pierwszymi deskami. Wiec x mozemy wyszukac binarnie.
    Rozwiazanie ma taka zlozonnosc, bo dla kazdego sprawdzania gwozdzie mozemy posortowac counting sortem, bo a_i <= 10^6
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a_i >> b_i;
        max_ai = max(max_ai, b_i);
        przedzialy.push_back({a_i, b_i});
    }
    sort(przedzialy.begin(),przedzialy.end());
    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        gwozdzie.push_back(wczytana_liczba);
    }

    poczatek = 0;
    koniec = n+1;

    while (koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_pasuje(srodek))
            koniec = srodek;
        else
            poczatek = srodek;
    }

    printf("%d",koniec);

    return 0;
}
