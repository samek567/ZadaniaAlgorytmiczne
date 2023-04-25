#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, k = 0, a_i = 0, b_i = 0, ile_spojnych = 0, wyn = 1e7;
vector<int> rep(1e5+5,0);
vector<pair<int,int>> krawedzie(2e5+5,{1,1});

int findd(int s)
{
    int wyn = 0, v = s;
    while (true)
    {
        if (v == rep[v])
        {
            wyn = v;
            break;
        }
        v = rep[v];
    }
    v = s;
    while (true)
    {
        if (v == rep[v])
            break;
        int syn = rep[v];
        rep[v] = wyn;
        v = syn;
    }
    return wyn;
}

void unionn(int x, int y)
{
    rep[findd(x)] = findd(y);
}

int main()
{
    // DSU
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        rep[i] = i;
    ile_spojnych = n;
    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        krawedzie[i] = {a_i, b_i};
    }

    for (int i = m-1; i >= 0; --i)
    {
        a_i = krawedzie[i].first, b_i = krawedzie[i].second;
        if (findd(a_i) != findd(b_i))
            ile_spojnych--;
        if (ile_spojnych == k)
            wyn = min(wyn,i+1);
        unionn(a_i,b_i);
    }

    printf("%d\n",wyn);

    return 0;
}