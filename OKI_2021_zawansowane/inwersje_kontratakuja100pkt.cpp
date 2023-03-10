#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Element
{
    int wartosc;
    int idx;
    bool operator < (const Element &element) const
    {
        if (wartosc == element.wartosc)
            return idx > element.idx;
        return wartosc > element.wartosc;
    }
};

int n = 0, wczytana_liczba = 0, base = (1<<17), rozmiar_drzewa = base * 2, wyn = 0;
vector<int> drzewo_przedzialowe;
vector<Element> elementy;

inline void update (int v)
{
    v += base;
    drzewo_przedzialowe[v] = 1;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe[v] = drzewo_przedzialowe[v*2] + drzewo_przedzialowe[v * 2 + 1];
        v /= 2;
    }
}

inline int querry(int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    int wyn = 0;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            wyn += drzewo_przedzialowe[l+1];
        if (p % 2 == 1)
            wyn += drzewo_przedzialowe[p-1];
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

    drzewo_przedzialowe.assign(rozmiar_drzewa,0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        elementy.push_back({wczytana_liczba,i});
    }
    sort(elementy.begin(),elementy.end());

    for (int i = 0; i < n; ++i)
    {
        if (elementy[i].idx != 0)
            wyn += querry(0,elementy[i].idx);
        update(elementy[i].idx);
    }

    cout << wyn << '\n';

    return 0;
}