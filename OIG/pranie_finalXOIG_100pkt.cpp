#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

struct Element_seta
{
    int wysokosc;
    int idx;
    bool operator < (const Element_seta &element_seta) const
    {
        if (wysokosc == element_seta.wysokosc)
            return idx < element_seta.idx;
        return wysokosc < element_seta.wysokosc;
    }
};

int n = 0, base = (1 << 18), rozmiar_drzewa = base * 2;
ll wyn = 0;
vector<int> liczby;
set<Element_seta> S;
vector<int> drzewo_przedzialowe_max;
vector<int> drzewo_przedzialowe_ile;

inline int querry_max(int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    int res = -1;
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

inline int querry_ile (int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    int res = 0;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res += drzewo_przedzialowe_ile[l+1];
        if (p % 2 == 1)
            res += drzewo_przedzialowe_ile[p-1];
        l /= 2;
        p /= 2;
    }
    return res;
}

inline void update_max (int val, int v)
{
    v += base;
    drzewo_przedzialowe_max[v] = val;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe_max[v] = max(drzewo_przedzialowe_max[v*2], drzewo_przedzialowe_max[v*2+1]);
        v /= 2;
    }
}

inline void update_ile (int val, int v)
{
    v += base;
    drzewo_przedzialowe_ile[v] = val;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe_ile[v] = drzewo_przedzialowe_ile[v*2] + drzewo_przedzialowe_ile[v*2+1];
        v /= 2;
    }
}

int main()
{
    // O(N lg N), drzewa przedzialowe z setem.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    liczby.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];

    drzewo_przedzialowe_max.assign(rozmiar_drzewa,-1);
    drzewo_przedzialowe_ile.assign(rozmiar_drzewa,0);

    S.insert({liczby[0], 0});
    update_max(0, liczby[0]);
    update_ile(1, 0);
    for (int i = 1; i < n; ++i)
    {
        int maxx = querry_max(liczby[i],n+1);
        if (maxx == -1)
            wyn += S.size();
        else
            wyn += querry_ile(maxx,n+1);
        while(!S.empty())
        {
            if (liczby[i] > S.begin()->wysokosc)
            {
                update_ile(0, S.begin()->idx);
                S.erase(*S.begin());
            }
            else
                break;
        }
        S.insert({liczby[i], i});
        update_ile(1, i);
        update_max(i, liczby[i]);
    }

    cout << wyn << '\n';

    return 0;
}
