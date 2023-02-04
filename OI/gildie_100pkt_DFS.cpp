#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, a_i = 0, b_i = 0;
vector<vector<int>> krawedzie;
vector<int> ile_krawedzi;
vector<char> stan; // N - nieodwiedzone, K - kwaczek S - szwaczek

void DFS(int v, char jaka_gildia)
{
    stan[v] = jaka_gildia;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        if (stan[krawedzie[v][i]] == 'N')
        {
            if (jaka_gildia == 'K')
                DFS(krawedzie[v][i], 'S');
            else
                DFS(krawedzie[v][i], 'K');
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    krawedzie.assign(n+1,{});
    ile_krawedzi.assign(n+1,0);
    stan.assign(n+1,'N');
    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        krawedzie[a_i].push_back(b_i);
        krawedzie[b_i].push_back(a_i);
        ile_krawedzi[a_i]++;
        ile_krawedzi[b_i]++;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (ile_krawedzi[i] == 0)
        {
            cout << "NIE" << '\n';
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (stan[i] == 'N')
            DFS(i,'K');
    }

    cout << "TAK" << '\n';
    for (int i = 1; i <= n; ++i)
        cout << stan[i] << '\n';

    return 0;
}