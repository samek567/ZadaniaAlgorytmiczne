#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 0, wczytany_p = 0, wczytany_k = 0, poczatek = 0, koniec = 0;
long long wynik = 0;
vector<vector<int>> krawedzie;
vector<vector<int>> ile;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    krawedzie.assign(n+1,{});
    for (int i = 0; i <= n; ++i)
    {
        ile.push_back({});
        for (int j = 0; j <= n; ++j)
        {
            ile[i].push_back(-1);
        }
    }

    for (int i = 0; i < n-1; ++i)
    {
        cin >> wczytany_p >> wczytany_k;
        krawedzie[wczytany_p].push_back(wczytany_k);
        krawedzie[wczytany_k].push_back(wczytany_p);
    }

    for (int i = 1; i <= n; ++i)
    {
        queue<int> Q;
        Q.push(i);
        ile[i][i] = 0;

        while(!Q.empty())
        {
            int spr = Q.front();

            for (int j = 0; j < krawedzie[spr].size(); ++j)
            {
                if (ile[i][krawedzie[spr][j]] == -1)
                {
                    ile[i][krawedzie[spr][j]] = ile[i][spr] + 1;
                    Q.push(krawedzie[spr][j]);
                }
            }
            Q.pop();
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i+1; j <= n; ++j)
        {
            for (int k = j+1; k <= n; ++k)
            {
                if (ile[i][j] == ile[i][k] && ile[i][j] == ile[j][k])
                {
                    wynik++;
                }
            }
        }
    }

    cout << wynik << "\n";

    return 0;
}
