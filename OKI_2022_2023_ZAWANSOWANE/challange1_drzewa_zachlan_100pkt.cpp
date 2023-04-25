#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

enum Wynik
{
    OK, ZLE, NIE_WIADOMO
};

struct Element_seta
{
    int wierzcholek;
    int stopien;
};

int n = 0, wsk_stopnie = 0, nr = 1, cnt = 0;
Wynik stan = NIE_WIADOMO;
vector<int> stopnie;
stack<Element_seta> S;
vector<pair<int,int>> krawedzie_pary;
vector<vector<int>> krawedzie;
vector<int> nr_rodzica;

inline void DFS()
{
    if (stan != NIE_WIADOMO)
        return;
    int v = S.top().wierzcholek, zag = S.top().stopien;
    S.pop();
    if (zag == stopnie[wsk_stopnie])
    {
        wsk_stopnie++;
        if (wsk_stopnie == n)
        {
            if (S.size() == 0)
                stan = OK;
            else
                stan = ZLE;
        }
    }
    else if (zag > stopnie[wsk_stopnie])
        stan = ZLE;
    else
    {
        ++nr;
        nr_rodzica.push_back(v);
        krawedzie_pary.push_back({v,nr});
        S.push({nr,zag+1});
        DFS();
        ++nr;
        nr_rodzica.push_back(v);
        krawedzie_pary.push_back({v,nr});
        S.push({nr,zag+1});
        DFS();
    }
}

void DFS (int v, int parent)
{
    if (krawedzie[v].size() == 1 and v != 1)
        cout << "()";
    else
    {
        cout << '(';
        for (int i = 0; i < krawedzie[v].size(); ++i)
        {
            int wierz = krawedzie[v][i];
            if (wierz == parent)
                continue;
            DFS(wierz,v);
        }
        cout << ')';
    }
}

int main()
{
    // Zachlan na drzewie.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    stopnie.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> stopnie[i];

    nr_rodzica.push_back(-1);
    nr_rodzica.push_back(0);
    S.push({1,0});
    DFS();

    if (stan == OK and S.size() == 0)
    {
        for (int i = 1; i <= nr; ++i)
            cout << nr_rodzica[i] << ' ';
        cout << '\n';
        krawedzie.assign(nr+1,{});
        for (int i = 0; i < nr-1; ++i)
            krawedzie[krawedzie_pary[i].first].push_back(krawedzie_pary[i].second);
        DFS(1,0);
    }
    else
        cout << "NIE" << '\n';

    return 0;
}