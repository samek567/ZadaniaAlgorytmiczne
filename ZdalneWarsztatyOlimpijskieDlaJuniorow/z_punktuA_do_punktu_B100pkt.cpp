#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 0, m = 0, A = 0, B = 0, a_i = 0, b_i = 0;
vector<vector<int>> krawedzie;
queue<pair<int,int>> Q; // Wierzcholek, wartosc
vector<bool> czy_odwiedzone;

inline int BFS(int a, int b)
{
    if (a == b)
        return 0;
    Q.push({a,0});
    czy_odwiedzone[a] = true;
    while (!Q.empty())
    {
        pair<int,int> spr = Q.front();
        for (int i = 0; i < krawedzie[spr.first].size(); ++i)
        {
            if (czy_odwiedzone[krawedzie[spr.first][i]] == false)
            {
                if (krawedzie[spr.first][i] == b)
                    return spr.second+1;
                czy_odwiedzone[krawedzie[spr.first][i]] = true;
                Q.push({krawedzie[spr.first][i],spr.second+1});
            }
        }
        Q.pop();
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> A >> B;
    krawedzie.assign(n+1,{});
    czy_odwiedzone.assign(n+1,false);
    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        krawedzie[a_i].push_back(b_i);
    }
    int droga = BFS(A,B);
    if (droga == -1)
        printf("niestety");
    else
        printf("%d",droga);
    return 0;
}