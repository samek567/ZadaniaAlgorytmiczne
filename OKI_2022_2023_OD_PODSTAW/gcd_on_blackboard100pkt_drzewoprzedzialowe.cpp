#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n = 0, wczytana_liczba = 0, base = 0, rozmiar_drzewa = 0, wyn = 0;
vector<int> drzewo_przedzialowe;

int querry(int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    int wyn = 0;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
        {
            if (wyn == 0)
                wyn = drzewo_przedzialowe[l+1];
            else
                wyn = __gcd(wyn,drzewo_przedzialowe[l+1]);
        }
        if (p % 2 == 1)
        {
            if (wyn == 0)
                wyn = drzewo_przedzialowe[p-1];
            else
                wyn = __gcd(wyn,drzewo_przedzialowe[p-1]);
        }
        l /= 2;
        p /= 2;
    }
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    base = (1 << int(ceil((double)log2(n))));
    rozmiar_drzewa = base * 2;
    drzewo_przedzialowe.assign(rozmiar_drzewa,n);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        drzewo_przedzialowe[base + i] = wczytana_liczba;
    }
    for (int i = base - 1; i > 0; --i)
        drzewo_przedzialowe[i] = __gcd(drzewo_przedzialowe[i*2],drzewo_przedzialowe[i*2+1]);

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
            wyn = max(wyn, querry(1,n-1));
        else if (i == n-1)
            wyn = max(wyn, querry(0,n-2));
        else
            wyn = max(wyn, __gcd(querry(0,i-1), querry(i+1,n-1)));
    }

    printf("%d",wyn);

    return 0;
}
