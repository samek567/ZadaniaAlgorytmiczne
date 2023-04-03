#include <iostream>
#include <vector>

using namespace std;

enum Stan
{
    BRAK, A, B
};

int n = 0, m = 0, a = 0, b = 0;
bool czy_pasuje = true;
vector<vector<int>> krawedzie;
vector<Stan> stany;

inline void DFS(int v, Stan jaki_kolor)
{
    if (czy_pasuje == false)
        return;
    stany[v] = jaki_kolor;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i];
        if (stany[wierz] == jaki_kolor)
            czy_pasuje = false;
        else if (stany[wierz] == BRAK)
        {
            if (jaki_kolor == A)
                DFS(wierz,B);
            else
                DFS(wierz,A);
        }
    }
}

int main()
{
    // O(N+M), Czy graf jest dwukolorowalny
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    krawedzie.assign(n+1,{});
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    stany.assign(n+1,BRAK);
    czy_pasuje = true;
    for (int i = 1; i <= n; ++i)
    {
        if (stany[i] == BRAK)
            DFS(i,A);
    }
    if (czy_pasuje == true)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}