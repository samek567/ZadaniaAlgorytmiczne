#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, a = 0, b = 0, ile_spojnych = 0;
vector<int> rep;

inline int findd(int x)
{
    int wyn = 0, v = x, parent = 0;
    while (true)
    {
        if (rep[v] == v)
        {
            wyn = v;
            break;
        }
        v = rep[v];
    }
    v = x;
    while (true)
    {
        if (rep[v] == v)
            break;
        parent = rep[v];
        rep[v] = wyn;
        v = parent;
    }
    return wyn;
}

inline void unionn(int x, int y)
{
    rep[findd(x)] = findd(y);
}

int main()
{
    // O(N lg N) Lecimy klasycznym Find and Union / DSU ;)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    ile_spojnych = n;

    for (int i = 0; i <= n; ++i)
        rep.push_back(i);

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        if (findd(a) != findd(b))
        {
            ile_spojnych--;
            unionn(a,b);
        }
        if (ile_spojnych == 1)
        {
            cout << i+1 << '\n';
            return 0;
        }
    }

    cout << "NIE ISTNIEJE" << '\n';

    return 0;
}