#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 317, skok_zabki = 0, q = 0, lewy_wsk = 0, prawy_wsk = 0, w_gasienicy = 0, INF = 1e9+20, l = 0, p = 0;
vector<int> odleglosci;
vector<int> max_skok;
vector<int> idx_pierwszego_w_innym_przedziale;
vector<int> ile_skok_do_w_innym_przedziale;

inline void przesuwaj_lewy()
{
    w_gasienicy -= odleglosci[lewy_wsk];
    lewy_wsk++;
    if (lewy_wsk > prawy_wsk)
    {
        prawy_wsk = lewy_wsk;
        w_gasienicy = 0;
    }
}

inline void przesuwaj_prawy()
{
    w_gasienicy += odleglosci[prawy_wsk];
    prawy_wsk++;
}

inline void napelniaj_max_skok()
{
    max_skok.assign(n,-1);
    while(true)
    {
        max_skok[lewy_wsk] = prawy_wsk;
        if (lewy_wsk == prawy_wsk and lewy_wsk == n-1)
            break;
        else if (prawy_wsk == n-1)
            przesuwaj_lewy();
        else
        {
            if (w_gasienicy + odleglosci[prawy_wsk] <= skok_zabki)
                przesuwaj_prawy();
            else
                przesuwaj_lewy();
        }
    }
}

inline void napelniaj_sqrt_decomposition()
{
    idx_pierwszego_w_innym_przedziale.assign(n,-1);
    ile_skok_do_w_innym_przedziale.assign(n,0);
    idx_pierwszego_w_innym_przedziale[n-1] = INF, ile_skok_do_w_innym_przedziale[n-1] = 0;
    for (int i = n-2; i >= 0; --i)
    {
        if (max_skok[i] == i)
            continue;
        else if (i / k == max_skok[i] / k)
        {
            ile_skok_do_w_innym_przedziale[i] = ile_skok_do_w_innym_przedziale[max_skok[i]] + 1;
            idx_pierwszego_w_innym_przedziale[i] = idx_pierwszego_w_innym_przedziale[max_skok[i]];
        }
        else
        {
            ile_skok_do_w_innym_przedziale[i] = 1;
            idx_pierwszego_w_innym_przedziale[i] = max_skok[i];
        }
    }
}

inline int zapytanie()
{
    cin >> l >> p;
    if (l > p)
        swap(l,p);
    l--,p--;
    int res = 0;
    while(l < p)
    {
        if (idx_pierwszego_w_innym_przedziale[l] <= p)
        {
            res += ile_skok_do_w_innym_przedziale[l];
            l = idx_pierwszego_w_innym_przedziale[l];
        }
        else
        {
            res++;
            l = max_skok[l];
        }
    }
    return res;
}

int main()
{
    // O(Q * sqrt(N)), sqrt decomposition, podobny motyw co zadanie Holes z codeforces.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> skok_zabki;

    odleglosci.assign(n-1,-1);
    for (int i = 0; i < n-1; ++i)
        cin >> odleglosci[i];

    napelniaj_max_skok();
    napelniaj_sqrt_decomposition();

    cin >> q;
    while(q--)
        cout << zapytanie() << '\n';

    return 0;
}
