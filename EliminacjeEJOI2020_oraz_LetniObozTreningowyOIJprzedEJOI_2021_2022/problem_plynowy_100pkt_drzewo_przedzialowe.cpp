#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;

struct Operacja
{
    char decyzja;
    int idx;
    int wartosc;
    int objetosc;
};

struct Element
{
    int idx;
    int p;
    int q;
    bool operator < (const Element &element) const
    {
        return (ld)p * (ld)element.q > (ld)element.p * (ld)q;
    }
};

int n = 0, base = (1 << 18), rozmiar_drzewa = base * 2;
vector<Operacja> operacje;
unordered_map<int,int> jaki_idx_w_drzewie_przedzialowym;
vector<Element> elementy;
vector<ll> drzewo_przedzialowe_objetosc;
vector<ll> drzewo_przedzialowe_wartosc;

inline void update_objetosc (int v, int val)
{
    v += base;
    drzewo_przedzialowe_objetosc[v] = val;
    v /= 2;
    while(v > 0)
    {
        drzewo_przedzialowe_objetosc[v] = drzewo_przedzialowe_objetosc[v*2] + drzewo_przedzialowe_objetosc[v*2+1];
        v /= 2;
    }
}

inline ll query_tree_objetosc (int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    ll res = 0;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res += drzewo_przedzialowe_objetosc[l+1];
        if (p % 2 == 1)
            res += drzewo_przedzialowe_objetosc[p-1];
        l /= 2;
        p /= 2;
    }
    return res;
}

inline void update_wartosc (int v, int val)
{
    v += base;
    drzewo_przedzialowe_wartosc[v] = val;
    v /= 2;
    while(v > 0)
    {
        drzewo_przedzialowe_wartosc[v] = drzewo_przedzialowe_wartosc[v*2] + drzewo_przedzialowe_wartosc[v*2+1];
        v /= 2;
    }
}

inline ll query_tree_wartosc (int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    ll res = 0;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res += drzewo_przedzialowe_wartosc[l+1];
        if (p % 2 == 1)
            res += drzewo_przedzialowe_wartosc[p-1];
        l /= 2;
        p /= 2;
    }
    return res;
}

inline ll bin_serach(ll v, ll ile_zostalo, ll sum)
{
    if (v >= base)
        return v - base;
    if (sum + drzewo_przedzialowe_objetosc[v*2] > ile_zostalo)
        return bin_serach(v*2,ile_zostalo,sum);
    else
        return bin_serach(v*2+1,ile_zostalo,sum+drzewo_przedzialowe_objetosc[v*2]);
}

inline ld query (int idx)
{
    ll ile_zostalo = operacje[idx].idx, pierwszy_wiekszy = 0;
    ld res = 0;
    if (query_tree_objetosc(0,base) <= ile_zostalo)
        pierwszy_wiekszy = base;
    else
        pierwszy_wiekszy = bin_serach(1,ile_zostalo,0);
    res += query_tree_wartosc(0,pierwszy_wiekszy-1);
    if (pierwszy_wiekszy != base)
        res += (ld)(ile_zostalo - query_tree_objetosc(0,pierwszy_wiekszy-1)) * ((ld)query_tree_wartosc(pierwszy_wiekszy,pierwszy_wiekszy) / (ld)query_tree_objetosc(pierwszy_wiekszy,pierwszy_wiekszy));
    return res;
}

inline void dodaj (int idx)
{
    update_objetosc(jaki_idx_w_drzewie_przedzialowym[operacje[idx].idx], operacje[idx].objetosc);
    update_wartosc(jaki_idx_w_drzewie_przedzialowym[operacje[idx].idx], operacje[idx].wartosc);
}

inline void usun (int idx)
{
    update_objetosc(jaki_idx_w_drzewie_przedzialowym[operacje[idx].idx], 0);
    update_wartosc(jaki_idx_w_drzewie_przedzialowym[operacje[idx].idx], 0);
}

inline void wypisuje ()
{
    cout << "WYPISUJE" << endl;
    for (int i = 0; i < elementy.size(); ++i)
        cout << elementy[i].idx << " " << elementy[i].p << " " << elementy[i].q << endl;

    cout << "WYPISUJE" << endl;
    for (auto it = jaki_idx_w_drzewie_przedzialowym.begin(); it != jaki_idx_w_drzewie_przedzialowym.end(); ++it)
        cout << it->first << " " << it->second << endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    drzewo_przedzialowe_objetosc.assign(rozmiar_drzewa,0);
    drzewo_przedzialowe_wartosc.assign(rozmiar_drzewa,0);
    operacje.assign(n,{-1,-1,-1});
    for (int i = 0; i < n; ++i)
    {
        cin >> operacje[i].decyzja;
        if (operacje[i].decyzja == '+')
            cin >> operacje[i].idx >> operacje[i].wartosc >> operacje[i].objetosc;
        else
            cin >> operacje[i].idx;
    }

    for (int i = 0; i < n; ++i)
        if (operacje[i].decyzja == '+')
            elementy.push_back({operacje[i].idx, operacje[i].wartosc, operacje[i].objetosc});
    sort(elementy.begin(),elementy.end());

    for (int i = 0; i < elementy.size(); ++i)
        jaki_idx_w_drzewie_przedzialowym[elementy[i].idx] = i;

    for (int i = 0; i < n; ++i)
    {
        if (operacje[i].decyzja == '+')
            dodaj(i);
        else if (operacje[i].decyzja == '-')
            usun(i);
        else
            cout << fixed << setprecision(8) << query(i) << '\n';
    }

    return 0;
}
