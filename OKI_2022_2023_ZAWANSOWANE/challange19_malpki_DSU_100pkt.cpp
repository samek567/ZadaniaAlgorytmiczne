#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Malpka
{
    int lewa_reka;
    int prawa_reka;
};

int n = 0, m = 0, a = 0, b = 0;
vector<Malpka> malpki;
vector<bool> visited_lewe;
vector<bool> visited_prawe;
vector<int> wyn;
vector<int> rep;
vector<pair<int,int>> zapytania;
queue<int> Q;
vector<vector<int>> krawedzie;

inline int findd(int x)
{
    int res = 0, child = 0, v = x;
    while(true)
    {
        if (rep[v] == v)
        {
            res = v;
            break;
        }
        v = rep[v];
    }
    v = x;
    while(true)
    {
        if (rep[v] == v)
            break;
        child = rep[v];
        rep[v] = res;
        v = child;
    }
    return res;
}

inline void unionn(int x, int y)
{
    int f_x = findd(x), f_y = findd(y);
    if (f_x == 1)
    {
        rep[f_y] = 1;
        krawedzie[1].push_back(f_y);
    }
    else if (f_y == 1)
    {
        rep[f_x] = 1;
        krawedzie[1].push_back(f_x);
    }
    else
    {
        krawedzie[f_y].push_back(f_x);
        rep[f_x] = f_y;
    }
}

inline void aktualizuj(int wartosc_find, int val)
{
    if (wyn[wartosc_find] != -50)
        return;
    Q.push(wartosc_find);
    wyn[wartosc_find] = val;
    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for (int i = 0; i < krawedzie[v].size(); ++i)
        {
            int wierz = krawedzie[v][i];
            if (wyn[wierz] == -50)
            {
                Q.push(wierz);
                wyn[wierz] = val;
            }
        }
    }
}

int main()
{
    // DSU z odwaracaniem czasu.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    krawedzie.assign(n+1,{});
    rep.assign(n+1,-1);
    for (int i = 1; i <= n; ++i)
        rep[i] = i;
    wyn.assign(n+1,-50);
    visited_lewe.assign(n+1,false);
    visited_prawe.assign(n+1,false);
    malpki.assign(n+1,{-1,-1});
    for (int i = 1; i <= n; ++i)
        cin >> malpki[i].lewa_reka >> malpki[i].prawa_reka;

    zapytania.assign(m,{-1,-1});
    for (int i = 0; i < m; ++i)
        cin >> zapytania[i].first >> zapytania[i].second;

    for (int i = 0; i < m; ++i)
    {
        if (zapytania[i].second == 1)
            visited_lewe[zapytania[i].first] = true;
        else
            visited_prawe[zapytania[i].first] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (malpki[i].lewa_reka != -1 and visited_lewe[i] == false)
            unionn(i, malpki[i].lewa_reka);
        if (malpki[i].prawa_reka != -1 and visited_prawe[i] == false)
            unionn(i, malpki[i].prawa_reka);
    }
    aktualizuj(1,-1);

    for (int i = m-1; i >= 0; --i)
    {
        a = zapytania[i].first;
        if (zapytania[i].second == 1)
            b = malpki[a].lewa_reka;
        else
            b = malpki[a].prawa_reka;
        if (findd(a) != findd(b))
        {
            if (findd(a) == 1)
                aktualizuj(findd(b),i);
            if (findd(b) == 1)
                aktualizuj(findd(a),i);
            unionn(a,b);
        }
    }


    for (int i = 1; i <= n; ++i)
        cout << wyn[i] << '\n';

    return 0;
}