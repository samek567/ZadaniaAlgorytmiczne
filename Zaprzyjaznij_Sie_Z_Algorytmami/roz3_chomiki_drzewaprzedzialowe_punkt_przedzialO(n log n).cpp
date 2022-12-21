#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, base = 0, rozmiar_drzewa = 0, a_i = 0, b_i = 0;
vector<int> liczby;
vector<int> drzewo_przedzialowe;

int querry_min(int p, int k)
{
    int poczatek = p + base - 2;
    int koniec = k + base;
    int wyn = 1e9;
    while(poczatek / 2 != koniec / 2)
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
    /*
     Drzewa przedzialowe O(n log n). Dzialaja dla wartosci dowolnych. Nie tylko [1,5]
     Rozwiazanie wolniejsze od wzorcowki z sumami prefiksowymi.
     */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    base = (1 << (int)(ceil(log2(n))));
    rozmiar_drzewa = 2 * base;
    drzewo_przedzialowe.assign(rozmiar_drzewa,1e9);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        drzewo_przedzialowe[base+i] = wczytana_liczba;
    }
    for (int i = base-1; i >= 1; --i)
        drzewo_przedzialowe[i] = min(drzewo_przedzialowe[2*i],drzewo_przedzialowe[2*i+1]);

    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        printf("%d \n", querry_min(a_i,b_i));
    }

    return 0;
}
