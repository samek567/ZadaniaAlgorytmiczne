#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, a = 0, b = 0, poczatek = 0, koniec = 0, srodek = 0, wyn = 0;
vector<pair<int,int>> krawedzie_wczytane;
vector<vector<int>> krawedzie;
vector<bool> czy_bylismy;

inline void DFS(int v)
{
    czy_bylismy[v] = true;
    wyn++;
    for (int i = 0; i < krawedzie[v].size(); ++i)
        if (czy_bylismy[krawedzie[v][i]] == false)
            DFS(krawedzie[v][i]);
}

inline bool czy_pasuje (int k)
{
    fill(czy_bylismy.begin(), czy_bylismy.end(), false);
    for (int i = 1; i <= n; ++i)
        krawedzie[i].clear();
    for (int i = 0; i < k; ++i)
    {
        krawedzie[krawedzie_wczytane[i].first].push_back(krawedzie_wczytane[i].second);
        krawedzie[krawedzie_wczytane[i].second].push_back(krawedzie_wczytane[i].first);
    }
    wyn = 0;
    DFS(1);
    if (wyn == n)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    krawedzie.assign(n+1,{});
    czy_bylismy.assign(n+1,false);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        krawedzie_wczytane.push_back({a,b});
    }

    poczatek = -1, koniec = m+1;
    while(koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_pasuje(srodek) == true)
            koniec = srodek;
        else
            poczatek = srodek;
    }

    if (koniec == m+1)
        cout << "NIE ISTNIEJE" << '\n';
    else
        cout << koniec << '\n';

    return 0;
}