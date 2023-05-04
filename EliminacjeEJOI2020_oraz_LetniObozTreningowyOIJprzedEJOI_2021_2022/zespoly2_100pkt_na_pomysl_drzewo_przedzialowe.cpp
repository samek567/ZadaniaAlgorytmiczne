#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Zapytanie
{
    int val;
    int idx;
};

struct Przedzial
{
    int lewy;
    int prawy;
    int priorytet; // zeby wiedziec ktore jest ostanie na drzewie przedzial - punkt
    bool operator < (const Przedzial &przedzial) const
    {
        return priorytet < przedzial.priorytet;
    }
};

struct Element_dp
{
    int val;
    int numer;
};

int n = 0, q = 0, wczytana_liczba = 0, base = (1 << 19), rozmiar_drzewa = base * 2, rozmiar_stat = 0, wyn = 0, numer_priorytetu = 0;
vector<int> zawodnicy;
vector<Zapytanie> zapytania;
vector<int> drzewo_przedzialowe_sum;
vector<Przedzial> drzewo_przedzialowe_przedzialow;
vector<int> kompresja;
unordered_map<int,int> stat; // jaki ma idx w liczbach.
vector<Element_dp> dp;

inline void update_sum(int val, int v)
{
    v += base;
    drzewo_przedzialowe_sum[v] = val;
    v /= 2;
    while(v > 0)
    {
        drzewo_przedzialowe_sum[v] = drzewo_przedzialowe_sum[v*2] + drzewo_przedzialowe_sum[v*2+1];
        v /= 2;
    }
}

inline int query_sum(int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    int res = 0;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res += drzewo_przedzialowe_sum[l+1];
        if (p % 2 == 1)
            res += drzewo_przedzialowe_sum[p-1];
        l /= 2;
        p /= 2;
    }
    return res;
}

inline void update_przedzial(Przedzial val, int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            drzewo_przedzialowe_przedzialow[l+1] = val;
        if (p % 2 == 1)
            drzewo_przedzialowe_przedzialow[p-1] = val;
        l /= 2;
        p /= 2;
    }
}

inline Przedzial query_przedzial(int v)
{
    Przedzial res = {-1,-1,-1};
    v += base;
    while(v > 0)
    {
        res = max(res,drzewo_przedzialowe_przedzialow[v]);
        v /= 2;
    }
    return res;
}



int main()
{
    // O((N+Q) * lg (N+Q)), na pomysl, drzewo przedzialowe z statystykami
    //https://forum.pasja-informatyki.pl/581114/zadanie-zespoly-2-letni-oboz-treningowy-oij-przed-ejoi-2021?show=581114#q581114
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    drzewo_przedzialowe_sum.assign(rozmiar_drzewa,0);
    drzewo_przedzialowe_przedzialow.assign(rozmiar_drzewa,{-1,-1,-1});
    zawodnicy.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> zawodnicy[i];
    cin >> q;
    zapytania.assign(q,{});
    for (int i = 0; i < q; ++i)
        cin >> zapytania[i].idx >> zapytania[i].val;

    for (int i = 0; i < n; ++i)
        kompresja.push_back(zawodnicy[i]);
    for (int i = 0; i < q; ++i)
        kompresja.push_back(zapytania[i].val);
    sort(kompresja.begin(), kompresja.end());

    stat[kompresja[0]] = 0;
    rozmiar_stat = 1;
    for (int i = 1; i < n+q; ++i)
    {
        if (kompresja[i] != kompresja[i-1])
        {
            stat[kompresja[i]] = rozmiar_stat;
            rozmiar_stat++;
        }
    }

    dp.assign(rozmiar_stat,{});
    for (int i = 0; i < n; ++i)
        dp[stat[zawodnicy[i]]] = {dp[stat[zawodnicy[i]]].val + 1,zawodnicy[i]};

    for (int i = 0; i < q; ++i)
        dp[stat[zapytania[i].val]].numer = zapytania[i].val;

    for (int i = 0; i < rozmiar_stat; ++i)
        update_sum(dp[i].val,i);

    for (int i = 0; i < rozmiar_stat; ++i)
    {
        int koniec = i;
        for (int j = i+1; j < rozmiar_stat; ++j)
        {
            if (dp[j].numer == dp[j-1].numer + 1 and dp[j].val != 0)
                koniec = j;
            else
                break;
        }
        wyn += query_sum(i, koniec) / 2;
        update_przedzial({i,koniec,numer_priorytetu}, i, koniec);
        numer_priorytetu++;
        i += (koniec - i);
    }

    cout << wyn << '\n';

    for (int i = 0; i < q; ++i)
    {
        int jaki_idx_w_dp = stat[zawodnicy[zapytania[i].idx - 1]];
        zawodnicy[zapytania[i].idx - 1] = zapytania[i].val;

        // Usuwamy
        if (dp[jaki_idx_w_dp].val > 1)
        {
            if (query_sum(query_przedzial(jaki_idx_w_dp).lewy, query_przedzial(jaki_idx_w_dp).prawy) % 2 == 0)
                wyn--;
            dp[jaki_idx_w_dp].val--;
            update_sum(dp[jaki_idx_w_dp].val, jaki_idx_w_dp);
        }
        else
        {
            dp[jaki_idx_w_dp].val = 0;
            update_sum(0, jaki_idx_w_dp);
            if (jaki_idx_w_dp == 0)
            {
                if (rozmiar_stat != 1)
                {
                    if (dp[0].numer + 1 == dp[1].numer and dp[1].val > 0)
                    {
                        int ile = query_sum(0 ,query_przedzial(1).prawy);
                        if (ile % 2 == 1)
                            wyn--;
                        update_przedzial({0,0,numer_priorytetu},0,0);
                        numer_priorytetu++;
                        update_przedzial({1,query_przedzial(1).prawy,numer_priorytetu},1,query_przedzial(1).prawy);
                        numer_priorytetu++;
                    }
                }
            }
            else if (jaki_idx_w_dp == rozmiar_stat-1)
            {
                if (rozmiar_stat != 1)
                {
                    if (dp[rozmiar_stat-2].numer + 1 == dp[rozmiar_stat-1].numer and dp[rozmiar_stat-2].val > 0)
                    {
                        int ile = query_sum(query_przedzial(rozmiar_stat-2).lewy, rozmiar_stat - 1);
                        if (ile % 2 == 1)
                            wyn--;
                        update_przedzial({rozmiar_stat-1,rozmiar_stat-1,numer_priorytetu},rozmiar_stat-1,rozmiar_stat-1);
                        numer_priorytetu++;
                        update_przedzial({query_przedzial(rozmiar_stat-2).lewy, rozmiar_stat-2, numer_priorytetu}, query_przedzial(rozmiar_stat-2).lewy, rozmiar_stat-2);
                        numer_priorytetu++;
                    }
                }
            }
            else
            {
                int przedzial_lewy = jaki_idx_w_dp, przedzial_prawy = jaki_idx_w_dp;
                if (dp[jaki_idx_w_dp-1].numer + 1 == dp[jaki_idx_w_dp].numer and dp[jaki_idx_w_dp-1].val > 0)
                    przedzial_lewy = query_przedzial(jaki_idx_w_dp-1).lewy;
                if (dp[jaki_idx_w_dp].numer + 1 == dp[jaki_idx_w_dp+1].numer and dp[jaki_idx_w_dp+1].val > 0)
                    przedzial_prawy = query_przedzial(jaki_idx_w_dp+1).prawy;
                update_przedzial({jaki_idx_w_dp,jaki_idx_w_dp,numer_priorytetu},jaki_idx_w_dp,jaki_idx_w_dp);
                numer_priorytetu++;
                wyn -= (query_sum(przedzial_lewy, przedzial_prawy) + 1) / 2;
                if (przedzial_lewy != jaki_idx_w_dp)
                {
                    wyn += query_sum(przedzial_lewy, jaki_idx_w_dp-1) / 2;
                    update_przedzial({przedzial_lewy, jaki_idx_w_dp-1, numer_priorytetu}, przedzial_lewy, jaki_idx_w_dp-1);
                    numer_priorytetu++;
                }
                if (przedzial_prawy != jaki_idx_w_dp)
                {
                    wyn += query_sum(jaki_idx_w_dp+1, przedzial_prawy) / 2;
                    update_przedzial({jaki_idx_w_dp+1, przedzial_prawy, numer_priorytetu}, jaki_idx_w_dp+1, przedzial_prawy);
                    numer_priorytetu++;
                }
            }
        }

        // Dodajemy
        jaki_idx_w_dp = stat[zapytania[i].val];
        if (dp[jaki_idx_w_dp].val == 0)
        {
            dp[jaki_idx_w_dp].val++;
            update_sum(dp[jaki_idx_w_dp].val, jaki_idx_w_dp);
            if (jaki_idx_w_dp == 0)
            {
                if (rozmiar_stat != -1)
                {
                    if (dp[0].numer + 1 == dp[1].numer and dp[1].val > 0)
                    {
                        int ile = query_sum(query_przedzial(1).lewy ,query_przedzial(1).prawy);
                        if (ile % 2 == 1)
                            wyn++;
                        update_przedzial({0,query_przedzial(1).prawy,numer_priorytetu},0,query_przedzial(1).prawy);
                        numer_priorytetu++;
                    }
                }
            }
            else if (jaki_idx_w_dp == rozmiar_stat-1)
            {
                if (rozmiar_stat != 1)
                {
                    if (dp[rozmiar_stat-2].numer + 1 == dp[rozmiar_stat-1].numer and dp[rozmiar_stat-2].val > 0)
                    {
                        int ile = query_sum(query_przedzial(rozmiar_stat-2).lewy, rozmiar_stat-2);
                        if (ile % 2 == 1)
                            wyn++;
                        update_przedzial({query_przedzial(rozmiar_stat-2).lewy, rozmiar_stat-1, numer_priorytetu}, query_przedzial(rozmiar_stat-2).lewy, rozmiar_stat-1);
                        numer_priorytetu++;
                    }
                }
            }
            else
            {
                int przedzial_lewy = jaki_idx_w_dp;
                int przedzial_prawy = jaki_idx_w_dp;
                if (dp[jaki_idx_w_dp-1].numer + 1 == dp[jaki_idx_w_dp].numer and dp[jaki_idx_w_dp-1].val > 0)
                {
                    przedzial_lewy = query_przedzial(jaki_idx_w_dp-1).lewy;
                    wyn -= query_sum(przedzial_lewy, jaki_idx_w_dp-1) / 2;
                }
                if (dp[jaki_idx_w_dp].numer + 1 == dp[jaki_idx_w_dp+1].numer and dp[jaki_idx_w_dp+1].val > 0)
                {
                    przedzial_prawy = query_przedzial(jaki_idx_w_dp+1).prawy;
                    wyn -= query_sum(jaki_idx_w_dp+1, przedzial_prawy) / 2;
                }
                wyn += query_sum(przedzial_lewy, przedzial_prawy) / 2;
                update_przedzial({przedzial_lewy, przedzial_prawy, numer_priorytetu}, przedzial_lewy, przedzial_prawy);
                numer_priorytetu++;
            }
        }
        else
        {
            if (query_sum(query_przedzial(jaki_idx_w_dp).lewy, query_przedzial(jaki_idx_w_dp).prawy) % 2 == 1)
                wyn++;
            dp[jaki_idx_w_dp].val++;
            update_sum(dp[jaki_idx_w_dp].val, jaki_idx_w_dp);
        }

        cout << wyn << '\n';
    }

    return 0;
}
