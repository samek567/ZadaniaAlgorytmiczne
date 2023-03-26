#include <iostream>
#include <vector>

using namespace std;

int n = 0, q = 0, a = 0, b = 0, numer_spojnej = 0;
string ciag;
char znak;
vector<char> stan_wierzcholka;
vector<int> w_jakiej_jest_spojnej;
vector<vector<int>> krawedzie;

void DFS (int v)
{
    w_jakiej_jest_spojnej[v] = numer_spojnej;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i];
        if (w_jakiej_jest_spojnej[wierz] == -1 and stan_wierzcholka[v] == stan_wierzcholka[wierz])
            DFS(wierz);
    }
}

int main()
{
    // O(N+Q), DFS / BFS
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> ciag;

    stan_wierzcholka.assign(n+1,'b');
    w_jakiej_jest_spojnej.assign(n+1,-1);
    krawedzie.assign(n+1, {});

    for (int i = 0; i < n; ++i)
        stan_wierzcholka[i+1] = ciag[i];

    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (w_jakiej_jest_spojnej[i] == -1)
        {
            DFS(i);
            numer_spojnej++;
        }
    }

    while (q--)
    {
        cin >> a >> b >> znak;
        if (w_jakiej_jest_spojnej[a] != w_jakiej_jest_spojnej[b])
            cout << '1';
        else if (stan_wierzcholka[a] == znak or stan_wierzcholka[b] == znak)
            cout << '1';
        else
            cout << '0';
    }

    return 0;
}