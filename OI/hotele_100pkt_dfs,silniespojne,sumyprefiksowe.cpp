#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n = 0, a_i = 0, b_i = 0, max_size_bfs = 0;
long long wyn = 0;
vector<int> ile_dojscie;
vector<bool> czy_bylismy;
vector<vector<int>> krawedzie;

void DFS(int v, int val)
{
    // Zamiast BFS-a do uzupelnienia vectora ile.
    ile_dojscie[v] = val;
    max_size_bfs = max(max_size_bfs,val);
    for (int i = 0; i < krawedzie[v].size(); ++i)
        if (ile_dojscie[krawedzie[v][i]] == -1)
            DFS(krawedzie[v][i],val+1);
}

int main()
{
    /*
    O(n^2)
    Traktujemy kazdy wierzcholek jako srodek ustawienia.
     */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    krawedzie.assign(n+1,{});
    ile_dojscie.assign(n+1,-1);
    czy_bylismy.assign(n+1,false);
    for (int i = 0; i < n-1; ++i)
    {
        cin >> a_i >> b_i;
        krawedzie[a_i].push_back(b_i);
        krawedzie[b_i].push_back(a_i);
    }

    for (int i = 1; i <= n; ++i)
    {
        max_size_bfs = 0;
        fill(ile_dojscie.begin(), ile_dojscie.end(), -1);
        fill(czy_bylismy.begin(),czy_bylismy.end(),false);
        DFS(i,0);
        vector<vector<int>> grupy;
        vector<vector<int>> sumy_prefiksowe;
        grupy.assign(max_size_bfs+1,{});

        czy_bylismy[i] = true;
        for (int k = 0; k < krawedzie[i].size(); ++k)
        {
            queue<int> Q;
            Q.push(krawedzie[i][k]);
            int wartosc = 1;
            int ile_elementow = 0;
            while (!Q.empty())
            {
                int spr = Q.front();
                czy_bylismy[spr] = true;

                if (ile_dojscie[spr] == wartosc)
                    ile_elementow++;
                else
                {
                    grupy[wartosc].push_back(ile_elementow);
                    wartosc = ile_dojscie[spr];
                    ile_elementow = 1;
                }
                for (int j = 0; j < krawedzie[spr].size(); ++j)
                    if (czy_bylismy[krawedzie[spr][j]] == false)
                        Q.push(krawedzie[spr][j]);
                Q.pop();
            }
            grupy[wartosc].push_back(ile_elementow);
        }

        sumy_prefiksowe.push_back({});
        for (int j = 1; j <= max_size_bfs; ++j)
        {
            int sum = 0;
            sumy_prefiksowe.push_back({});
            for (int k = 0; k < grupy[j].size(); ++k)
            {
                sum += grupy[j][k];
                sumy_prefiksowe[j].push_back(sum);
            }
        }
        for (int j = 1; j <= max_size_bfs; ++j)
        {
            for (int k = 1; k < sumy_prefiksowe[j].size()-1; ++k)
            {
                wyn += grupy[j][k] * sumy_prefiksowe[j][k-1] * (sumy_prefiksowe[j][sumy_prefiksowe[j].size()-1] - sumy_prefiksowe[j][k]);
            }
        }
    }

    printf("%lld",wyn);

    return 0;
}
