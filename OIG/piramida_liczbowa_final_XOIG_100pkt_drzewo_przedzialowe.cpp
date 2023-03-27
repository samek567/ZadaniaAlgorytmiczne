#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int n = 0, base = 0, rozmiar_drzewa = 0, max_val = 0, zap = 0;
ll wyn = 0;
vector<int> liczby;
vector<int> drzewo_przedzialowe;
vector<int> ile_lewo;
vector<int> ile_prawo;

inline int querry_max(int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    int res = -1;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res = max(res, drzewo_przedzialowe[l+1]);
        if (p % 2 == 1)
            res = max(res, drzewo_przedzialowe[p-1]);
        l /= 2;
        p /= 2;
    }
    return res;
}

inline void update_max(int v, int val)
{
    v += base;
    drzewo_przedzialowe[v] = val;
    v /= 2;
    while(v > 0)
    {
        drzewo_przedzialowe[v] = max(drzewo_przedzialowe[v*2], drzewo_przedzialowe[v*2+1]);
        v /= 2;
    }
}

inline int querry_min(int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    int res = 1e9;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res = min(res, drzewo_przedzialowe[l+1]);
        if (p % 2 == 1)
            res = min(res, drzewo_przedzialowe[p-1]);
        l /= 2;
        p /= 2;
    }
    return res;
}

inline void update_min(int v, int val)
{
    v += base;
    drzewo_przedzialowe[v] = val;
    v /= 2;
    while(v > 0)
    {
        drzewo_przedzialowe[v] = min(drzewo_przedzialowe[v*2], drzewo_przedzialowe[v*2+1]);
        v /= 2;
    }
}

int main()
{
    // O(N * lg(max(A[i]))
    // tresc zadania z sprawdzarka: https://szkopul.edu.pl/problemset/problem/UJ7ImMeWphKxSOy6HFKT6AOW/site/?key=statement
    // OKI od podstaw 2021/2022: https://www.youtube.com/watch?v=JJzOAD4SBpc&list=PL9BlBU4U-rDPDamT7hFVsONnWDYrn5CEo&index=30
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    liczby.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];

    for (int i = 0; i < n; ++i)
        max_val = max(max_val, liczby[i]);

    base = (1 << int(ceil((double)log2(max_val+3)))), rozmiar_drzewa = base * 2;
    zap = max_val + 2;

    drzewo_przedzialowe.assign(rozmiar_drzewa,-1);
    ile_lewo.assign(n,-1);
    for (int i = 0; i < n; ++i)
    {
        ile_lewo[i] = querry_max(liczby[i], zap);
        update_max(liczby[i],i);
    }

    drzewo_przedzialowe.assign(rozmiar_drzewa,1e9);
    ile_prawo.assign(n,-1);
    for (int i = n-1; i >= 0; --i)
    {
        ile_prawo[i] = querry_min(liczby[i]+1,zap);
        update_min(liczby[i],i);
    }

    for (int i = 0; i < n; ++i)
    {
        int lewo = 0, prawo = 0;
        if (ile_lewo[i] == -1)
            lewo = i+1;
        else
            lewo = i - ile_lewo[i];
        if (ile_prawo[i] == 1e9)
            prawo = n - i;
        else
            prawo = ile_prawo[i] - i;
        wyn += (ll)lewo * (ll)prawo * (ll)liczby[i];
    }

    cout << wyn << '\n';

    return 0;
}