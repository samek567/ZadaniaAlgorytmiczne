#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 0, k = 0, a = 0, b = 0;
vector<vector<int>> krawedzie;
vector<int> ile;
queue<int> Q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    krawedzie.assign(n+1,{});
    ile.assign(n+1,0);
    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        ile[a]++;
        ile[b]++;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
        if (ile[i] == 1)
            Q.push(i);

    for (int i = 0; i <= n; ++i)
    {
        int SIZE = Q.size();
        if (SIZE <= k)
        {
            cout << i << ' ' << max(SIZE,2) << '\n';
            if (SIZE == 1)
                cout << Q.front() << ' ' << krawedzie[Q.front()][0];
            else
            {
                for (int j = 0; j < SIZE; ++j)
                {
                    cout << Q.front() << ' ';
                    Q.pop();
                }
            }
            return 0;
        }
        for (int j = 0; j < SIZE; ++j)
        {
            int spr = Q.front();
            Q.pop();
            for (int k = 0; k < krawedzie[spr].size(); ++k)
            {
                ile[krawedzie[spr][k]]--;
                if (ile[krawedzie[spr][k]] == 1)
                    Q.push(krawedzie[spr][k]);
            }
        }
    }

    return 0;
}