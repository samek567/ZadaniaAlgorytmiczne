#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n = 0, bilans = 0, base = 0, rozmiar_drzewa = 0, wyn = 0;
const int DOD = 1e6;
string ciag;
vector<int> stat;
vector<int> wystapienia[2*DOD+5];
vector<int> drzewo_przedzialowe;

inline int querry (int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    int wyn = -1e8;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            wyn = max(wyn,drzewo_przedzialowe[l+1]);
        if (p % 2 == 1)
            wyn = max(wyn,drzewo_przedzialowe[p-1]);
        l /= 2;
        p /= 2;
    }
    return wyn;
}

int main()
{
    // O(N lg N)
    /*
    1 traktujemy calosc jako gorki i dolki (pomarancza w gole, jablko w dol)
    2 - z kazdego punkty szukamy pierwszego punktu, ktory jest polozony nizej niz sprawdzany.
    3 - bierzemy maxa (drzewem przedzialowym)
    4 - Szukamy binarnie ostatniego maxa <= koncowi przedzialowi.
    Wykonujemy 2 wyszukiwania binarne, i jedno querry na drzewie przedzialowym punkt - przedzial, wszystkie te 3 operacje mają O(log N)
    Kluczowe jest spostrzerzenie, gdy sprawdzamy punkt i, ze koniec nie moze byc dalej niz pierwszy spadek ponizej stat[i],
    i zawsze ten punkt musi byc tez najwyzszy, gdybysmy nie wzieli najwyzeszego, to idac od konca bylaby sytuacja, gdy jest wiecej jablek od konca,
    czyli bierzemy ostatni, mieszczacy sie w przedziale, ktory jest najwyzszy.
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;

    stat.push_back(0);
    wystapienia[0+DOD].push_back(0);
    for (int i = 0; i < n; ++i)
    {
        if (ciag[i] == 'p')
            bilans++;
        else
            bilans--;
        stat.push_back(bilans);
        wystapienia[bilans+DOD].push_back(i+1);
    }

    base = (1 << int(ceil(log2(n+1))));
    rozmiar_drzewa = base * 2;
    drzewo_przedzialowe.assign(rozmiar_drzewa,-1e8);
    for (int i = 0; i <= n; ++i)
        drzewo_przedzialowe[base+i] = stat[i];
    for (int i = base-1; i > 0; --i)
        drzewo_przedzialowe[i] = max(drzewo_przedzialowe[i*2], drzewo_przedzialowe[i*2+1]);

    for (int i = 0; i <= n; ++i)
    {
        // Pierwszy binary search
        int poczatek = 0, koniec = 0, srodek = 0, idx_ostatniego = 0, val_MAX = 0;
        if (stat[i] == -1e6)
            idx_ostatniego = n;
        else if (wystapienia[stat[i]-1+DOD].size() == 0)
            idx_ostatniego = n;
        else
        {
            poczatek = -1, koniec = wystapienia[stat[i]-1+DOD].size();
            while (koniec - poczatek > 1)
            {
                srodek = (poczatek + koniec) / 2;
                if (wystapienia[stat[i]-1+DOD][srodek] > i)
                    koniec = srodek;
                else
                    poczatek = srodek;
            }
            if (koniec == wystapienia[stat[i]-1+DOD].size())
                idx_ostatniego = n;
            else
                idx_ostatniego = wystapienia[stat[i]-1+DOD][koniec] - 1;
        }

        // Querry na drzewie przedzialowym punkt - przedzial
        val_MAX = querry(i,idx_ostatniego);

        // Drugi binary search
        poczatek = -1, koniec = wystapienia[val_MAX+DOD].size();
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (wystapienia[val_MAX+DOD][srodek] <= idx_ostatniego)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        wyn = max(wyn,wystapienia[val_MAX+DOD][poczatek]-i);
    }

    cout << wyn << '\n';

    return 0;
}
