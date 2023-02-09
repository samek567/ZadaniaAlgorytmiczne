#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element
{
    int val; // Koszt dojscia
    int a; // w jakim wierzcholku jest agent 1
    int b; // w jakim wierzcholku jest agent 2
};

int n = 0, m = 0, a = 0, b = 0, a_i = 0, b_i = 0;
Element spr = {-1,-1,-1};
vector<vector<int>> krawedzie;
bool czy_bylismy[251][251];
bool czy_bylismy_half[251][251]; // Zeby nie isc bez sensownie, jak i tak to nic nie da!
queue<Element> Q;

int main()
{
    // O(N^3)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> a >> b;
    krawedzie.assign(n+1,{});

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            czy_bylismy[i][j] = false;
            czy_bylismy_half[i][j] = false;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        krawedzie[a_i].push_back(b_i);
    }
    Q.push({0,a,b});
    czy_bylismy[a][b] = true;
    czy_bylismy_half[a][b] = true;
    while(!Q.empty())
    {
        spr = Q.front();
        if (spr.a == spr.b)
        {
            cout << spr.val << '\n';
            return 0;
        }
        for (int i = 0; i < krawedzie[spr.a].size(); ++i)
        {
            if (czy_bylismy_half[krawedzie[spr.a][i]][spr.b] == false)
            {
                czy_bylismy_half[krawedzie[spr.a][i]][spr.b] = true;
                for (int j = 0; j < krawedzie[spr.b].size(); ++j)
                {
                    if (czy_bylismy[krawedzie[spr.a][i]][krawedzie[spr.b][j]] == false)
                    {
                        czy_bylismy[krawedzie[spr.a][i]][krawedzie[spr.b][j]] = true;
                        Q.push({spr.val+1,krawedzie[spr.a][i],krawedzie[spr.b][j]});
                    }
                }
            }
        }
        Q.pop();
    }

    cout << "NIE" << '\n';

    return 0;
}