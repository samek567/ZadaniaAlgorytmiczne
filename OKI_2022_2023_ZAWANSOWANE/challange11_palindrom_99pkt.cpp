#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Para
{
    int poczatek;
    int koniec;
    bool operator < (const Para &para) const
    {
        if (poczatek == para.poczatek)
            return koniec < para.koniec;
        return poczatek > para.poczatek;
    }
};

struct Budowanie_drzewa_przedzialowego
{
    int koniec_val;
    int idx_w_parach;
    bool operator < (const Budowanie_drzewa_przedzialowego &budowanie_drzewa_przedzialowego) const
    {
        if (koniec_val == budowanie_drzewa_przedzialowego.koniec_val)
            return idx_w_parach < budowanie_drzewa_przedzialowego.idx_w_parach;
        return koniec_val < budowanie_drzewa_przedzialowego.koniec_val;
    }
};

int n = 0, wczytana_liczba = 0, base = 0, rozmiar_drzewa = 0, idx_znalezionego = 0;
vector<Para> pary;
vector<vector<int>> stat;
vector<vector<int>> stat_poczatek;
vector<int> idxy_w_drzewie_przedzialowym;
vector<Budowanie_drzewa_przedzialowego> budowanie_drzewa;
vector<int> drzewo_przedzialowe;
vector<pair<int,int>> do_zarymowania; // Jaka wartosc, jaki wierzcholek

void update(int v, int val)
{
    v = v + base;
    drzewo_przedzialowe[v] = val;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe[v] = max(drzewo_przedzialowe[v*2],drzewo_przedzialowe[v*2+1]);
        v /= 2;
    }
}

int querry(int p, int k)
{
    p = p + base - 1;
    k = k + base + 1;
    int wyn_zap = -1e9;
    while (p / 2 != k / 2)
    {
        if (p % 2 == 0)
            wyn_zap = max(wyn_zap,drzewo_przedzialowe[p+1]);
        if (k % 2 == 1)
            wyn_zap = max(wyn_zap,drzewo_przedzialowe[k-1]);
        p /= 2;
        k /= 2;
    }
    return wyn_zap;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    stat.assign(n+1,{});
    stat_poczatek.assign(n+1,{});
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        stat[wczytana_liczba].push_back(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < stat[i].size(); ++j)
        {
            for (int k = j+1; k < stat[i].size(); ++k)
                pary.push_back({stat[i][j],stat[i][k]});
        }
    }
    sort(pary.begin(),pary.end());

    for (int i = 0; i < pary.size(); ++i)
        budowanie_drzewa.push_back({pary[i].koniec,i});
    sort(budowanie_drzewa.begin(),budowanie_drzewa.end());

    for (int i = 0; i < budowanie_drzewa.size(); ++i)
        stat_poczatek[pary[budowanie_drzewa[i].idx_w_parach].poczatek].push_back(i);

    idxy_w_drzewie_przedzialowym.assign(pary.size(),-1);
    for (int i = 0; i < budowanie_drzewa.size(); ++i)
        idxy_w_drzewie_przedzialowym[budowanie_drzewa[i].idx_w_parach] = i;

    base = (1 << int(ceil((double)log2(budowanie_drzewa.size()))));
    rozmiar_drzewa = base * 2;
    drzewo_przedzialowe.assign(rozmiar_drzewa,0);
    for (int i = 0; i < pary.size(); ++i)
    {
        idx_znalezionego = -1;
        for (int j = idxy_w_drzewie_przedzialowym[i] - 1; j >= 0; --j)
        {
            if (budowanie_drzewa[j].koniec_val < budowanie_drzewa[idxy_w_drzewie_przedzialowym[i]].koniec_val)
            {
                idx_znalezionego = j;
                break;
            }
        }
        if (idx_znalezionego == -1)
        {
            update(idxy_w_drzewie_przedzialowym[i],2);
        }
        else
        {
            // Rymujemy na chwile te co maja ten sam poczatek i robimy querry.
            for (int j = 0; j < stat_poczatek[pary[i].poczatek].size(); ++j)
            {
                do_zarymowania.push_back({drzewo_przedzialowe[stat_poczatek[pary[i].poczatek][j] + base],stat_poczatek[pary[i].poczatek][j]});
                update(stat_poczatek[pary[i].poczatek][j],0);
            }
            update(idxy_w_drzewie_przedzialowym[i], querry(0,idx_znalezionego)+2);
            for (auto j : do_zarymowania)
            {
                if (idxy_w_drzewie_przedzialowym[i] != j.second)
                    update(j.second,j.first);
            }
            do_zarymowania.clear();
        }
    }
    printf("%d", querry(0,base-1));

    return 0;
}