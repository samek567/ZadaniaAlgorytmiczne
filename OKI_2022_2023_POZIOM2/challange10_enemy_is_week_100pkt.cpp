#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Element
{
    long long wartosc;
    int idx;
    bool operator < (const Element &element) const
    {
        return wartosc < element.wartosc;
    }
};

struct Stat
{
    long long ile_wiekszych_na_lewo;
    long long ile_mniejszych_na_prawo;
};

int n = 0, wczytana_liczba = 0, base = 0, rozmiar_drzewa = 0;
long long wyn = 0;
vector<Element> elementy;
vector<Stat> statystyki;
vector<int> drzewo_przedzialowe;

void update(int v)
{
    v = base + v;
    drzewo_przedzialowe[v] = 0;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe[v] = drzewo_przedzialowe[2 * v] + drzewo_przedzialowe[v * 2 + 1];
        v /= 2;
    }
}

int querry(int p, int k)
{
    int poczatek = p + base - 1;
    int koniec = k + base + 1;
    int res = 0;
    while (poczatek / 2 != koniec / 2)
    {
        if (poczatek % 2 == 0)
            res += drzewo_przedzialowe[poczatek+1];
        if (koniec % 2 == 1)
            res += drzewo_przedzialowe[koniec-1];
        poczatek /= 2;
        koniec /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    statystyki.assign(n,{0,0});
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        elementy.push_back({wczytana_liczba,i});
    }
    sort(elementy.begin(),elementy.end());

    base = (1 << (int((double)ceil(log2(n)))));
    rozmiar_drzewa = base * 2;
    drzewo_przedzialowe.assign(rozmiar_drzewa,1);
    for (int i = base-1; i >= 1; --i)
        drzewo_przedzialowe[i] = drzewo_przedzialowe[i*2] + drzewo_przedzialowe[i*2+1];
    for (int i = 0; i < n; ++i)
    {
        update(elementy[i].idx);
        statystyki[elementy[i].idx].ile_wiekszych_na_lewo = querry(0,elementy[i].idx);
    }

    reverse(elementy.begin(),elementy.end());

    for (int i = base; i < rozmiar_drzewa; ++i)
        drzewo_przedzialowe[i] = 1;
    for (int i = base-1; i >= 0; --i)
        drzewo_przedzialowe[i] = drzewo_przedzialowe[i*2] + drzewo_przedzialowe[i*2+1];
    for (int i = 0; i < n; ++i)
    {
        update(elementy[i].idx);
        statystyki[elementy[i].idx].ile_mniejszych_na_prawo = querry(elementy[i].idx,n-1);
    }

    for (int i = 0; i < n; ++i)
        wyn += statystyki[i].ile_wiekszych_na_lewo * statystyki[i].ile_mniejszych_na_prawo;

    printf("%lld",wyn);

    return 0;
}