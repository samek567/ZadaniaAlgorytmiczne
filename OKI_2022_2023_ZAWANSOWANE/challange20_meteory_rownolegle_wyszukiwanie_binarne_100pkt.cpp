#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Opad
{
    int l;
    int r;
    int ile_dod;
};

struct Element
{
    int l;
    int p;
    int srodek;
    int idx_miasta;
    bool operator < (const Element &element) const
    {
        return srodek < element.srodek;
    }
};

int n = 0, m = 0, k = 0, base = (1 << 19), rozmiar_drzewa = base * 2;
vector<ll> drzewo_przedzialowe;
vector<int> zapotrzebowanie;
vector<int> stacje;
vector<int> wyn;
vector<Opad> opady;
vector<vector<int>> jakie_idxy_ma_miasto;
vector<Element> elementy;

inline void update (int l, int p, ll val)
{
    l = l + base - 1, p = p + base + 1;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            drzewo_przedzialowe[l+1] += val;
        if (p % 2 == 1)
            drzewo_przedzialowe[p-1] += val;
        l /= 2;
        p /= 2;
    }
}

inline void dodaj (int l, int p, ll val)
{
    if (l <= p)
        update(l,p,val);
    else
    {
        update(l,m-1,val);
        update(0,p,val);
    }
}

inline ll query(int v)
{
    v += base;
    ll res = 0;
    while (v > 0)
    {
        if (drzewo_przedzialowe[v] > 1e9) // Zeby nie przekroczylo sie z long longa.
            return 1e9+5;
        res += drzewo_przedzialowe[v];
        v /= 2;
    }
    return res;
}

inline void clearuj_drzewo_przedzialowe()
{
    drzewo_przedzialowe.assign(rozmiar_drzewa,0);
}

int main()
{
    // Bardzo fajne zadanie na rownolegle wyszukiwanie binarne po wyniku,
    // https://forum.pasja-informatyki.pl/583882/zadanie-meteory-final-xviii-oi-rownolegle-wyszukiwanie-binarne?show=583891#a583891
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    zapotrzebowanie.assign(n+1,-1);
    wyn.assign(n+1,-1);
    stacje.assign(m,-1);
    jakie_idxy_ma_miasto.assign(n+1,{});

    for (int i = 0; i < m; ++i)
        cin >> stacje[i];

    for (int i = 0; i < m; ++i)
        jakie_idxy_ma_miasto[stacje[i]].push_back(i);

    for (int i = 1; i <= n; ++i)
        cin >> zapotrzebowanie[i];

    cin >> k;
    opady.assign(k,{});
    for (int i = 0; i < k; ++i)
        cin >> opady[i].l >> opady[i].r >> opady[i].ile_dod;

    for (int i = 1; i <= n; ++i)
        elementy.push_back({0,k+1,(k+1) / 2, i});
    sort(elementy.begin(), elementy.end());

    while(!elementy.empty())
    {
        int wsk = 0;
        vector<Element> nowy;
        clearuj_drzewo_przedzialowe();
        for (int i = 0; i < k and wsk < elementy.size(); ++i)
        {
            dodaj(opady[i].l-1, opady[i].r-1, opady[i].ile_dod);
            while(true)
            {
                if (elementy[wsk].srodek - 1 == i)
                {
                    ll sum = 0;
                    for (int j = 0; j < jakie_idxy_ma_miasto[elementy[wsk].idx_miasta].size(); ++j)
                        sum += query(jakie_idxy_ma_miasto[elementy[wsk].idx_miasta][j]);
                    int poczatek = 0, koniec = 0;
                    if (sum >= zapotrzebowanie[elementy[wsk].idx_miasta] or sum > 1e9)
                    {
                        poczatek = elementy[wsk].l, koniec = elementy[wsk].srodek;
                    }
                    else
                    {
                        poczatek = elementy[wsk].srodek, koniec = elementy[wsk].p;
                    }
                    if (koniec - poczatek == 1)
                        wyn[elementy[wsk].idx_miasta] = koniec;
                    else
                        nowy.push_back({poczatek, koniec, (poczatek + koniec) / 2, elementy[wsk].idx_miasta});
                    wsk++;
                }
                else
                    break;
            }
        }
        elementy = nowy;
        sort(elementy.begin(), elementy.end());
    }

    for (int i = 1; i <= n; ++i)
    {
        if (wyn[i] == k+1)
            cout << "NIE" << '\n';
        else
            cout << wyn[i] << '\n';
    }

    return 0;
}