#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, z = 0, a_i = 0, b_i = 0, numer_spojnej = 0;
vector<vector<int>> krawedzie;
vector<int> w_jakiej_spojnej_jest;

void DFS(int v)
{
    w_jakiej_spojnej_jest[v] = numer_spojnej;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        if (w_jakiej_spojnej_jest[krawedzie[v][i]] == -1)
            DFS(krawedzie[v][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    w_jakiej_spojnej_jest.assign(n+1,-1);
    krawedzie.assign(n+1,{});
    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        krawedzie[a_i].push_back(b_i);
        krawedzie[b_i].push_back(a_i);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (w_jakiej_spojnej_jest[i] == -1)
        {
            DFS(i);
            numer_spojnej++;
        }
    }

    cin >> z;
    for (int i = 0; i < z; ++i)
    {
        cin >> a_i >> b_i;
        if (w_jakiej_spojnej_jest[a_i] == w_jakiej_spojnej_jest[b_i])
            printf("TAK\n");
        else
            printf("NIE\n");
    }

    return 0;
}
