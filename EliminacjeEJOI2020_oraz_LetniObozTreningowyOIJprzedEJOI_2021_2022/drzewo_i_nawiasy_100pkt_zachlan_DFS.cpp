#include <iostream>
#include <vector>

using namespace std;

int n = 0, a = 0, b = 0, lisc = -1, p = 0;
string res;
vector<vector<int>> krawedzie;
vector<int> visited;
vector<int> ile_wchodzi;

inline void DFS(int v)
{
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i];
        if (visited[wierz] != -1)
            continue;
        if (visited[v] == 0)
            visited[wierz] = 1;
        else
            visited[wierz] = 0;
        DFS(wierz);
    }
}

int main()
{
    /* O(N), dowod poprawnosci tego algorytmu jest taki, ze kolorujac w ten sposob graf
    mamy zagwarantowane, ze kazda sciezka wlasciwa parzystej dlugosci tworzy poprawne nawiasowanie
    a zauwazmy, ze interesuja nas tylko te sciezki, bo sciezki nieparzystej dlugosci nigdy nie beda
    tworzyc poprawnego wyrazenia nawiasowego*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;

    krawedzie.assign(n+1,{});
    ile_wchodzi.assign(n+1,0);
    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        ile_wchodzi[a]++;
        ile_wchodzi[b]++;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (ile_wchodzi[i] <= 1)
        {
            lisc = i;
            break;
        }
    }

    visited.assign(n+1,-1);
    visited[lisc] = 0;
    DFS(lisc);

    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == 0)
            res += '(';
        else
            res += ')';
    }

    cout << res << '\n';

    return 0;
}
