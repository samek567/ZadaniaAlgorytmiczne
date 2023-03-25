#include <iostream>
#include <vector>

using namespace std;

int n = 0, poczatek = 0, koniec = 0, srodek = 0, base = (1 << 19), rozmiar_drzewa = base * 2, wyn = 0;
vector<int> drzewo_przedzialowe;

inline int querry(int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    int res = 4e5+50;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res = min(res, drzewo_przedzialowe[l+1]);
        if (p % 2 == 1)
            res = min(res, drzewo_przedzialowe[p-1]);
        l /= 2;
        p /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    drzewo_przedzialowe.assign(rozmiar_drzewa,4e5+50);
    for (int i = 0; i < n; ++i)
        cin >> drzewo_przedzialowe[base+i];
    for (int i = base-1; i >= 1; --i)
        drzewo_przedzialowe[i] = min(drzewo_przedzialowe[i*2], drzewo_przedzialowe[i*2+1]);

    for (int i = 0; i < n; ++i)
    {
        poczatek = 0, koniec = 4e5+50;
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (i - srodek < 0 or i + srodek >= n or drzewo_przedzialowe[i+base] < 2*srodek+1)
                koniec = srodek;
            else if (querry(i-srodek, i+srodek) > srodek)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        wyn = max(wyn, poczatek);
    }

    cout << wyn << '\n';

    return 0;
}