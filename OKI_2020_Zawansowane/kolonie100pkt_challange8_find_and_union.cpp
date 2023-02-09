#include <iostream>
#include <vector>

using namespace std;

int n = 0, masa = 0, iq = 0, a = 0, b = 0;
vector<int> rep;
vector<int> rep_iq_min;
vector<int> rep_iq_max;
vector<int> rep_masa_suma;
string ciag;

int findd(int s)
{
    int wyn = 0, v = s;
    while(true)
    {
        if (v == rep[v])
        {
            wyn = v;
            break;
        }
        v = rep[v];
    }
    v = s;
    while(true)
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
    x = findd(x);
    y = findd(y);
    rep[x] = y;
    rep_iq_max[y] = max(rep_iq_max[x], rep_iq_max[y]);
    rep_iq_min[y] = min(rep_iq_min[x], rep_iq_min[y]);
    rep_masa_suma[y] = rep_masa_suma[x] + rep_masa_suma[y];
}

int main()
{
    // O(N lg N) Find and Union
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    rep_iq_max.assign(n+1,0);
    rep_iq_min.assign(n+1,0);
    rep_masa_suma.assign(n+1,0);
    for (int i = 0; i <= n; ++i)
        rep.push_back(i);
    for (int i = 1; i <= n; ++i)
    {
        cin >> masa >> iq;
        rep_iq_min[i] = iq;
        rep_iq_max[i] = iq;
        rep_masa_suma[i] = masa;
    }

    while(true)
    {
        if (!(cin >> ciag).good())
            break;
        if (ciag == "JOIN")
        {
            cin >> a >> b;
            if (findd(a) != findd(b))
                unionn(a,b);
        }
        else
        {
            cin >> a;
            if (ciag == "IQ_MAX")
                cout << rep_iq_max[findd(a)] << '\n';
            else if (ciag == "IQ_MIN")
                cout << rep_iq_min[findd(a)] << '\n';
            else if (ciag == "MASA")
                cout << rep_masa_suma[findd(a)] << '\n';
        }
    }

    return 0;
}