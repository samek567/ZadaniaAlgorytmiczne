#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

struct Przystanek
{
    int y;
    int x;
    int cena;
};

struct Element
{
    int x;
    int cena;
    bool operator < (const Element &element) const
    {
        return x < element.x;
    }
};

int n = 0, m = 0, q = 0, x = 0, y = 0, z = 0, wysokosc = 1, szerokosc = 1, wyn = 0, suma = 0, base = 0, rozmiar_drzewa = 0;
vector<int> stat_Y;
vector<int> stat_X;
unordered_map<int,int> jaki_idx_Y;
unordered_map<int,int> jaki_idx_X;
vector<vector<Element>> liczby;
vector<Przystanek> przystanki;
vector<int> maxy;

inline void update(int v, int val)
{
    v += base;
    maxy[v] = val;
    v /= 2;
    while (v > 0)
    {
        maxy[v] = max(maxy[v*2], maxy[2*v+1]);
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
            wyn = max(wyn,maxy[l+1]);
        if (p % 2 == 1)
            wyn = max(wyn,maxy[p-1]);
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

    cin >> m >> n >> q;

    for (int i = 0; i < q; ++i)
    {
        cin >> x >> y >> z;
        y = n - y + 1;
        przystanki.push_back({y,x,z});
        stat_Y.push_back(y);
        stat_X.push_back(x);
    }

    sort(stat_Y.begin(), stat_Y.end());
    sort(stat_X.begin(), stat_X.end());

    jaki_idx_Y[stat_Y[0]] = 1;
    for (int i = 1; i < stat_Y.size(); ++i)
    {
        if (stat_Y[i] != stat_Y[i-1])
        {
            wysokosc++;
            jaki_idx_Y[stat_Y[i]] = wysokosc;
        }
    }

    jaki_idx_X[stat_X[0]] = 1;
    for (int i = 1; i < stat_X.size(); ++i)
    {
        if (stat_X[i] != stat_X[i-1])
        {
            szerokosc++;
            jaki_idx_X[stat_X[i]] = szerokosc;
        }
    }

    liczby.assign(wysokosc+1,{});

    for (int i = 0; i < q; ++i)
    {
        liczby[jaki_idx_Y[przystanki[i].y]].push_back({jaki_idx_X[przystanki[i].x] ,przystanki[i].cena});
    }

    base = (1 << int(ceil(log2(szerokosc+1))));
    rozmiar_drzewa = base * 2;
    maxy.assign(rozmiar_drzewa,0);

    for (int i = 1; i <= wysokosc; ++i)
        sort(liczby[i].begin(),liczby[i].end());

    for (int i = 0; i < liczby[wysokosc].size(); ++i)
    {
        suma += liczby[wysokosc][i].cena;
        update(liczby[wysokosc][i].x ,suma);
        wyn = max(wyn, suma);
    }

    for (int i = wysokosc-1; i >= 1; --i)
    {
        for (int j = 0; j < liczby[i].size(); ++j)
        {
            int val = querry(0,liczby[i][j].x) + liczby[i][j].cena;
            update(liczby[i][j].x, val);
            wyn = max(wyn, val);
        }
    }

    cout << wyn << '\n';

    return 0;
}