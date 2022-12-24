#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Element
{
    int wartosc;
    int idx;
    bool operator < (const Element &element) const
    {
        if (wartosc == element.wartosc)
            return idx < element.idx;
        return wartosc < element.wartosc;
    }
};

int n = 0, wczytana_liczba = 0, base = 0, rozmiar_drzewa = 0, wyn = 0;
vector<Element> elementy;
vector<int> drzewa_przedzialowe;

void add(int v)
{
    v = base + v;
    drzewa_przedzialowe[v] = 0;
    v /= 2;
    while (v > 0)
    {
        drzewa_przedzialowe[v] = drzewa_przedzialowe[v * 2] + drzewa_przedzialowe[v * 2 + 1];
        v /= 2;
    }
}

int querry(int p, int k)
{
    int poczatek = base + p - 1;
    int koniec = base + k + 1;
    int suma = 0;
    while (poczatek / 2 != koniec / 2)
    {
        if (poczatek % 2 == 0)
            suma += drzewa_przedzialowe[poczatek+1];
        if (koniec % 2 == 1)
            suma += drzewa_przedzialowe[koniec-1];
        poczatek /= 2;
        koniec /= 2;
    }
    return suma;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        elementy.push_back({wczytana_liczba,i});
    }
    sort(elementy.begin(), elementy.end());

    base = (1 << (int)(ceil((double)log2(n))));
    rozmiar_drzewa = base * 2;
    drzewa_przedzialowe.assign(rozmiar_drzewa,0);

    for (int i = base; i < rozmiar_drzewa; ++i)
        drzewa_przedzialowe[i] = 1;
    for (int i = base-1; i > 0; --i)
        drzewa_przedzialowe[i] = drzewa_przedzialowe[2 * i] + drzewa_przedzialowe[2 * i + 1];

    for (int i = 0; i < n; ++i)
    {
        add(elementy[i].idx);
        if (elementy[i].idx != 0)
            wyn += querry(0,elementy[i].idx-1);
    }

    printf("%d",wyn);

    return 0;
}
