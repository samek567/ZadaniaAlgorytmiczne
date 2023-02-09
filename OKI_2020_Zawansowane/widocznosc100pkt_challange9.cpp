#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Element
{
    int val;
    int idx;
    bool operator < (const Element &element) const
    {
        if (val == element.val)
            return idx < element.idx;
        return val < element.val;
    }
};

int n = 0, wczytana_liczba = 0, base = 0, rozmiar_drzewa = 0;
vector<Element> elementy;
vector<int> jaki_idx_w_drzewie_przedzialowym;
vector<int> drzewo_przedzialowe;
vector<int> liczby;

int binary_searchh(int val)
{
    int poczatek = 0, koniec = n, srodek = 0;
    while(koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (elementy[srodek].val <= val)
            poczatek = srodek;
        else
            koniec = srodek;
    }
    return poczatek;
}

int querry(int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    int wyn = -1;
    while(l / 2 != p / 2)
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

void update (int v, int val)
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

int main()
{
    // O(N lg N) - drzewo przedzialowe
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        elementy.push_back({wczytana_liczba,i});
    }
    sort(elementy.begin(),elementy.end());
    for (int i = 0; i < n; ++i)
        jaki_idx_w_drzewie_przedzialowym.push_back(binary_searchh(liczby[i]));
    base = (1 << int(ceil((double)log2(n+25))));
    rozmiar_drzewa = base * 2;
    drzewo_przedzialowe.assign(rozmiar_drzewa,-1);
    for (int i = 0; i < n; ++i)
    {
        int wyn_max = querry(jaki_idx_w_drzewie_przedzialowym[i]+1,n+10);
        update(jaki_idx_w_drzewie_przedzialowym[i],i);
        if (wyn_max == -1)
            cout << "-1" << '\n';
        else
            cout << wyn_max + 1 << '\n';
    }
    return 0;
}