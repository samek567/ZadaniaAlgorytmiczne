#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, m = 0, z = 0, a = 0, b = 0, c = 0, base = (1 << 16), rozmiar_drzewa = base * 2;
vector<ll> tree;
vector<ll> tree2;

inline void update(int l_zap, int p_zap, int l_kontrolowana, int p_kontrolowana, int v, ll val)
{
    if (p_kontrolowana < l_zap or l_kontrolowana > p_zap)
        return;
    else if (l_kontrolowana >= l_zap and p_kontrolowana <= p_zap)
    {
        tree[v] += val;
        tree2[v] += val;
    }
    else if (l_kontrolowana != p_kontrolowana)
    {
        tree[v*2] += tree2[v];
        tree[v*2+1] += tree2[v];
        tree2[v*2] += tree2[v];
        tree2[v*2+1] += tree2[v];
        tree2[v] = 0;
        update(l_zap, p_zap, l_kontrolowana, l_kontrolowana + (p_kontrolowana - l_kontrolowana + 1 - 2) / 2, v*2, val);
        update(l_zap, p_zap, l_kontrolowana + (p_kontrolowana - l_kontrolowana + 1) / 2, p_kontrolowana, v*2+1, val);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

inline ll query(int l_zap, int p_zap, int l_kontrolowana, int p_kontrolowana, int v)
{
    if (p_kontrolowana < l_zap or l_kontrolowana > p_zap)
        return 0;
    if (l_kontrolowana >= l_zap and p_kontrolowana <= p_zap)
        return tree[v];
    else if (l_kontrolowana != p_kontrolowana)
    {
        if (tree2[v] != 0)
        {
            tree2[v*2] += tree2[v];
            tree2[v*2+1] += tree2[v];
            tree[v*2] += tree2[v];
            tree[v*2+1] += tree2[v];
            tree2[v] = 0;
        }
        return max(query(l_zap, p_zap, l_kontrolowana, l_kontrolowana + (p_kontrolowana - l_kontrolowana + 1 - 2) / 2, v*2), query(l_zap, p_zap, l_kontrolowana + (p_kontrolowana - l_kontrolowana + 1) / 2, p_kontrolowana, v*2+1));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> z;
    tree.assign(rozmiar_drzewa,0);
    tree2.assign(rozmiar_drzewa,0);

    while(z--)
    {
        cin >> a >> b >> c;
        if (query(a,b-1,1,base,1) + c <= m)
        {
            cout << "T" << '\n';
            update(a,b-1,1,base,1,c);
        }
        else
            cout << "N" << '\n';
    }

    return 0;
}