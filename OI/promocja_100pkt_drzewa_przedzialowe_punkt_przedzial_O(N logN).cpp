#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int n = 0, k = 0, wczytana_liczba = 0, base = 0, rozmiar_drzewa = 0, min_zap = 0, max_zap = 0;
ll wyn = 0;
vector<int> ile(1e6+1,0);
vector<int> drzewo_przedzialowe_max;
vector<int> drzewo_przedzialowe_min;

void update_min(int v, int val)
{
    v += base;
    drzewo_przedzialowe_min[v] = val;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe_min[v] = min(drzewo_przedzialowe_min[v * 2], drzewo_przedzialowe_min[v * 2 + 1]);
        v /= 2;
    }
}

void update_max(int v, int val)
{
    v += base;
    drzewo_przedzialowe_max[v] = val;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe_max[v] = max(drzewo_przedzialowe_max[v * 2], drzewo_przedzialowe_max[v * 2 + 1]);
        v /= 2;
    }
}

int querry_min(int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    int res = 1e6+5;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res = min(res,drzewo_przedzialowe_min[l+1]);
        if (p % 2 == 1)
            res = min(res, drzewo_przedzialowe_min[p-1]);
        l /= 2;
        p /= 2;
    }
    return res;
}

int querry_max(int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    int res = -1e6+5;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res = max(res,drzewo_przedzialowe_max[l+1]);
        if (p % 2 == 1)
            res = max(res, drzewo_przedzialowe_max[p-1]);
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

    base = (1 << ((int)ceil((double)log2(1e6+1))));
    rozmiar_drzewa = base * 2;
    drzewo_przedzialowe_min.assign(rozmiar_drzewa,1e6+5);
    drzewo_przedzialowe_max.assign(rozmiar_drzewa,0);

    cin >> n;
    while(n--)
    {
        cin >> k;
        while(k--)
        {
            cin >> wczytana_liczba;
            ile[wczytana_liczba]++;
            update_min(wczytana_liczba,wczytana_liczba);
            update_max(wczytana_liczba,wczytana_liczba);
        }
        max_zap = querry_max(1,1e6);
        ile[max_zap]--;
        if (ile[max_zap] == 0)
        {
            update_max(max_zap,0);
            update_min(max_zap,1e6+5);
        }
        min_zap = querry_min(1,1e6);
        ile[min_zap]--;
        if (ile[min_zap] == 0)
        {
            update_max(min_zap,0);
            update_min(min_zap,1e6+5);
        }
        wyn += max_zap - min_zap;
    }
    printf("%lld",wyn);
    return 0;
}