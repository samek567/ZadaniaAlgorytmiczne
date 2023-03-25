#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n = 0, q = 0, wczytana_liczba = 0, a = 0, b = 0, c = 0, base = 0, rozmiar_drzewa = 0;
vector<int> drzewo_przedzialowe;

void add (int v, int x)
{
    v = v + base - 1;
    drzewo_przedzialowe[v] = x;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe[v] = min(drzewo_przedzialowe[v * 2], drzewo_przedzialowe[v * 2 + 1]);
        v /= 2;
    }
}

int querry(int a, int b)
{
    int poczatek = a + base - 2;
    int koniec = b + base;
    int wyn = 1e9+5;
    while (poczatek / 2 != koniec / 2)
    {
        if (poczatek % 2 == 0)
            wyn = min(wyn,drzewo_przedzialowe[poczatek+1]);
        if (koniec % 2 == 1)
            wyn = min(wyn,drzewo_przedzialowe[koniec-1]);
        poczatek /= 2;
        koniec /= 2;
    }
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    base = (1 << int(ceil((double)log2(n))));
    rozmiar_drzewa = 2 * base;
    drzewo_przedzialowe.assign(rozmiar_drzewa,1e9+5);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        drzewo_przedzialowe[i + base] = wczytana_liczba;
    }
    for (int i = base - 1; i > 0; --i)
        drzewo_przedzialowe[i] = min(drzewo_przedzialowe[i * 2], drzewo_przedzialowe[i * 2 + 1]);
    for (int i = 0; i < q; ++i)
    {
        cin >> a >> b >> c;
        if (a == 2)
            printf("%d\n", querry(b,c));
        else
            add(b,c);
    }
    return 0;
}