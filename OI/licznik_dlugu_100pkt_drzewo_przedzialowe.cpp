#include <iostream>
#include <vector>

using namespace std;

int n = 0, z = 0, base = (1 << 17), rozmiar_drzewa = base * 2, INF = 1e9;
string wewnetrzny;
string zewnetrzny;
char decyzja;
vector<int> stat_wewnetrzny;
vector<int> stat_zewnetrzny;
vector<int> drzewo_przedzialowe_minus_jeden;
vector<int> drzewo_przedzialowe_max;

inline void update_minus_jeden(int v, int val)
{
    v += base;
    drzewo_przedzialowe_minus_jeden[v] = val;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe_minus_jeden[v] = min(drzewo_przedzialowe_minus_jeden[v*2],drzewo_przedzialowe_minus_jeden[v*2+1]);
        v /= 2;
    }
}

inline int query_minus_jeden(int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    int res = INF;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res = min(res,drzewo_przedzialowe_minus_jeden[l+1]);
        if (p % 2 == 1)
            res = min(res, drzewo_przedzialowe_minus_jeden[p-1]);
        l /= 2;
        p /= 2;
    }
    return res;
}

inline void update_max(int v, int val)
{
    v += base;
    drzewo_przedzialowe_max[v] = val;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe_max[v] = max(drzewo_przedzialowe_max[v*2],drzewo_przedzialowe_max[v*2+1]);
        v /= 2;
    }
}

inline int query_max(int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    int res = -INF;
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


inline void napelniaj()
{
    stat_wewnetrzny.assign(n,0);
    stat_zewnetrzny.assign(n,0);
    for (int i = 1; i < n; ++i)
        stat_wewnetrzny[i] = (int)wewnetrzny[i-1]-48;
    for (int i = 1; i < n; ++i)
        stat_zewnetrzny[i] = (int)zewnetrzny[i-1]-48;

    drzewo_przedzialowe_max.assign(rozmiar_drzewa,-INF);
    drzewo_przedzialowe_minus_jeden.assign(rozmiar_drzewa,INF);
    for (int i = 1; i < n; ++i)
    {
        if (stat_wewnetrzny[i] + stat_zewnetrzny[i] <= 8)
            update_minus_jeden(i,i);
        else
            update_max(i,stat_wewnetrzny[i] + stat_zewnetrzny[i]);
    }
}

inline void update()
{
    int v = 0, val = 0;
    cin >> v >> val;
    v = n - v;

    if (stat_wewnetrzny[v] + stat_zewnetrzny[v] <= 8)
        update_minus_jeden(v,INF);
    else
        update_max(v,-INF);

    if (decyzja == 'W')
        stat_wewnetrzny[v] = val;
    else
        stat_zewnetrzny[v] = val;

    if (stat_wewnetrzny[v] + stat_zewnetrzny[v] <= 8)
        update_minus_jeden(v,v);
    else
        update_max(v,stat_wewnetrzny[v] + stat_zewnetrzny[v]);
}

inline int query()
{
    int v = 0, val = 0, idx_minus_jeden = 0, koniec_query = 0;
    cin >> v;
    v = n - v;

    val = stat_zewnetrzny[v] + stat_wewnetrzny[v];
    idx_minus_jeden = query_minus_jeden(v+1,n);

    if (idx_minus_jeden == INF)
        koniec_query = n;
    else
        koniec_query = idx_minus_jeden - 1;
    if (idx_minus_jeden == v+1)
        return val % 10;
    if (query_max(v+1,koniec_query) >= 10)
        return (val+1) % 10;
    return val % 10;
}

int main()
{
    /* Jeśli suma na pozycji i jest >= 10, to A[i] = 1,
       jak == 9, to A[i] = 0, jak <= 8 to A[i] = -1,
       dostaję zapytanie o pozycję x.
       Szukam gdzie jest pierwsza -1 na przedziale [x+1,n] i jeśli na przedziale [x+1,idx_pierwszej_minus_jedynki-1] robię querry,
       czy jest chociaż jedna 1. Jak jest to wiem, że dodaję jeden, jak nie to wiem, że nie dodaję. O(N lg N + Q lg N).
    */
    // https://forum.pasja-informatyki.pl/584364/zadanie-licznik-dlugu-xxviii-oi
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> z >> wewnetrzny >> zewnetrzny;

    napelniaj();

    while(z--)
    {
        cin >> decyzja;
        if (decyzja == 'S')
            cout << query() << '\n';
        else
            update();
    }

    return 0;
}
