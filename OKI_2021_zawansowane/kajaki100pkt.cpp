#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int w = 0, n = 0, wczytana_liczba = 0, wyn = 0, base = 256, rozmiar_drzewa = 512;
vector<int> stat(205,0);
vector<int> drzewo_przedzialowe;

int querry(int l, int p)
{
    l += base - 1;
    p += base + 1;
    int wyn = 0;
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

void update(int v, int val)
{
    v += base;
    drzewo_przedzialowe[v] = val;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe[v] = max(drzewo_przedzialowe[v * 2], drzewo_przedzialowe[v * 2 + 1]);
        v /= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        stat[wczytana_liczba]++;
    }
    drzewo_przedzialowe.assign(rozmiar_drzewa,0);
    for (int i = 5; i <= w; ++i)
        if (stat[i] > 0)
            drzewo_przedzialowe[i + base] = i;
    for (int i = base-1; i >= 0; --i)
        drzewo_przedzialowe[i] = max(drzewo_przedzialowe[i*2],drzewo_przedzialowe[i*2+1]);

    while(true)
    {
        int max_przedzial = querry(0,w);
        if (max_przedzial == 0)
            break;
        stat[max_przedzial]--;
        if (stat[max_przedzial] == 0)
            update(max_przedzial,0);
        int max_podprzedzial = querry(0,w - max_przedzial);
        if (max_podprzedzial != 0)
        {
            stat[max_podprzedzial]--;
            if (stat[max_podprzedzial] == 0)
                update(max_podprzedzial,0);
        }
        wyn++;
    }

    cout << wyn;

    return 0;
}