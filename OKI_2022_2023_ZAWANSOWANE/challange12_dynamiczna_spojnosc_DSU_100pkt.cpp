#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, a_i = 0, b_i = 0, c_i = 0;
vector<int> rep(5e5+5);

int findd(int v)
{
    int wyn = 0;
    while (true)
    {
        if (v == rep[v])
        {
            wyn = v;
            break;
        }
        v = rep[v];
    }
    while (true)
    {
        if (v == rep[v])
            break;
        rep[v] = wyn;
    }
    return wyn;
}

void unionn(int x, int y)
{
    rep[findd(x)] = findd(y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        rep[i] = i;
    while(m--)
    {
        cin >> a_i >> b_i >> c_i;
        if (a_i == 1)
            unionn(b_i,c_i);
        else
        {
            if (findd(b_i) == findd(c_i))
                printf("TAK\n");
            else
                printf("NIE\n");
        }
    }
    return 0;
}