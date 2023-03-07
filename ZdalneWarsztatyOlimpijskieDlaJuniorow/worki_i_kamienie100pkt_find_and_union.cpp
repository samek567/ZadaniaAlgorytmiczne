#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, a = 0, b = 0, c = 0;
vector<int> rep;

inline int findd(int x)
{
    int res = 0, parent = 0, v = 0;
    v = x;
    while(true)
    {
        if (rep[v] == v)
        {
            res = v;
            break;
        }
        v = rep[v];
    }

    v = x;
    while(true)
    {
        if (rep[v] == v)
            break;
        parent = rep[v];
        rep[v] = res;
        v = parent;
    }

    return res;
}

inline void unionn(int x, int y)
{
    rep[findd(x)] = findd(y);
}

int main()
{
    // Implementacja find and union.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    rep.assign(n+1,-1);
    for (int i = 1; i <= n; ++i)
        rep[i] = i;

    while (m--)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            if (findd(b) == findd(c))
                cout << "TAK" << '\n';
            else
                cout << "NIE" << '\n';
        }
        else
            unionn(b,c);
    }
    return 0;
}