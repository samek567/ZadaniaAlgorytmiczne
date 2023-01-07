#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n = 0, m = 0, a_i = 0, b_i = 0, A = 0, B = 0, C = 0;
vector<vector<int>> krawedzie;
vector<int> ile_bfs;
queue<int> Q;

int BFS(int w1, int w2)
{
    fill(ile_bfs.begin(),ile_bfs.end(),-1);
    while (!Q.empty())
        Q.pop();
    Q.push(w1);
    ile_bfs[w1] = 0;
    while (!Q.empty())
    {
        for (int i = 0; i < krawedzie[Q.front()].size(); ++i)
        {
            if (ile_bfs[krawedzie[Q.front()][i]] == -1)
            {
                ile_bfs[krawedzie[Q.front()][i]] = ile_bfs[Q.front()] + 1;
                Q.push(krawedzie[Q.front()][i]);
            }
        }
        Q.pop();
    }
    return ile_bfs[w2];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    krawedzie.assign(n+1,{});
    ile_bfs.assign(n+1,-1);
    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        krawedzie[a_i].push_back(b_i);
        krawedzie[b_i].push_back(a_i);
    }
    cin >> A >> B >> C;
    if (BFS(A,B) < BFS(A,C) + BFS(C,B))
        printf("NIE");
    else
        printf("TAK");
    return 0;
}