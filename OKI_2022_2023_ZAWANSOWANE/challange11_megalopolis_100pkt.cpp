#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n = 0, m = 0, a_i = 0, b_i = 0, base = 0, rozmiar_drzewa = 0, cnt_idx_w_drzewie = 0;
char znak;
vector<vector<int>> krawedzie;
vector<int> numer_ojca;
vector<int> ile_ma_synow;
vector<int> drzewo_przedzialowe;
vector<int> kolejnosc_post_order;
vector<int> jaki_numer_w_drzewie_przedzialowym;
vector<int> ile;
vector<bool> czy_bylismy;

void update(int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            drzewo_przedzialowe[l+1]++;
        if (p % 2 == 1)
            drzewo_przedzialowe[p-1]++;
        l /= 2;
        p /= 2;
    }
}

int querry(int v)
{
    int wyn = 0;
    v += base;
    while (v > 0)
    {
        wyn += drzewo_przedzialowe[v];
        v /= 2;
    }
    return wyn;
}

void DFS_numer_ojcow(int v, int ojciec, int val)
{
    numer_ojca[v] = ojciec;
    ile[v] = val;
    jaki_numer_w_drzewie_przedzialowym[v] = cnt_idx_w_drzewie;
    cnt_idx_w_drzewie++;
    for (int i = 0; i < krawedzie[v].size(); ++i)
        if (numer_ojca[krawedzie[v][i]] == -1)
            DFS_numer_ojcow(krawedzie[v][i],v, val+1);
}

void DFS_post_order(int v)
{
    czy_bylismy[v] = true;
    for (int i = 0; i < krawedzie[v].size(); ++i)
        if (czy_bylismy[krawedzie[v][i]] == false)
            DFS_post_order(krawedzie[v][i]);
    kolejnosc_post_order.push_back(v);
}

int main()
{
    // O(m log n) - drzewo przedzialowe przedzial-punkt, dfs pre order, dfs post order, bardzo fajne zadanko
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    base = (1 << int(ceil((double)log2(n))));
    rozmiar_drzewa = base * 2;
    drzewo_przedzialowe.assign(rozmiar_drzewa,0);
    krawedzie.assign(n+1,{});
    numer_ojca.assign(n+1,-1);
    jaki_numer_w_drzewie_przedzialowym.assign(n+1,-1);
    ile.assign(n+1,0);
    ile_ma_synow.assign(n+1,0);
    czy_bylismy.assign(n+1,false);
    for (int i = 0; i < n-1; ++i)
    {
        cin >> a_i >> b_i;
        krawedzie[a_i].push_back(b_i);
        krawedzie[b_i].push_back(a_i);
    }

    DFS_numer_ojcow(1,-2,0);
    DFS_post_order(1);
    for (int i = 0; i < n; ++i)
    {
        int val = 0, ile_synow = 0;
        for (int j = 0; j < krawedzie[kolejnosc_post_order[i]].size(); ++j)
        {
            if (krawedzie[kolejnosc_post_order[i]][j] != numer_ojca[kolejnosc_post_order[i]])
            {
                val += ile_ma_synow[krawedzie[kolejnosc_post_order[i]][j]];
                ile_synow++;
            }
        }
        ile_ma_synow[kolejnosc_post_order[i]] = val + ile_synow;
    }

    cin >> m;
    for (int i = 0; i < n + m - 1; ++i)
    {
        cin >> znak;
        if (znak == 'W')
        {
            cin >> a_i;
            printf("%d\n", ile[a_i] - querry(jaki_numer_w_drzewie_przedzialowym[a_i]));
        }
        else
        {
            cin >> a_i >> b_i;
            if (numer_ojca[a_i] == b_i)
                update(jaki_numer_w_drzewie_przedzialowym[a_i],jaki_numer_w_drzewie_przedzialowym[a_i] + ile_ma_synow[a_i]);
            else
                update(jaki_numer_w_drzewie_przedzialowym[b_i],jaki_numer_w_drzewie_przedzialowym[b_i] + ile_ma_synow[b_i]);
        }
    }
    return 0;
}