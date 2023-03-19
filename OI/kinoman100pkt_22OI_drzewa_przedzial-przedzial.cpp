#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int n = 0, m = 0, base = 0, rozmiar_drzewa = 0, dod_update = 0, l_zap = 0;
ll suma = 0, wyn = 0, ile_dod = 0;
vector<int> liczby;
vector<vector<int>> wystapienia;
vector<int> koszty;
vector<int> wystapienia_wsk;
vector<ll> tree;
vector<ll> tree2;

inline void update (int l_kontrolowane, int p_kontrolowane, int v)
{
    if (l_kontrolowane > base or p_kontrolowane < l_zap)
        return;
    else if (l_kontrolowane >= l_zap and p_kontrolowane <= base)
    {
        tree[v] += dod_update;
        tree2[v] += dod_update;
    }
    else if (l_kontrolowane != p_kontrolowane)
    {
        if (tree2[v] != 0)
        {
            tree2[v*2+1] += tree2[v];
            tree2[v*2] += tree2[v];
            tree[v*2+1] += tree2[v];
            tree[v*2] += tree2[v];
            tree2[v] = 0;
        }
        update(l_kontrolowane,l_kontrolowane + (p_kontrolowane - l_kontrolowane + 1 - 2) / 2,v*2);
        update(l_kontrolowane + (p_kontrolowane - l_kontrolowane + 1) / 2,p_kontrolowane,v*2+1);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

int main()
{
    // Drzewa przedzial-przedzial
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    base = (1 << int(ceil(log2(n+1))));
    rozmiar_drzewa = base * 2;

    tree.assign(rozmiar_drzewa,0);
    tree2.assign(rozmiar_drzewa,0);

    liczby.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];

    wystapienia.assign(1e6+1,{});
    wystapienia_wsk.assign(1e6+1,0);
    for (int i = 0; i < n; ++i)
        wystapienia[liczby[i]].push_back(i);

    koszty.assign(m+1,-1);
    for (int i = 1; i <= m; ++i)
        cin >> koszty[i];

    for (int i = 0; i < n; ++i)
    {
        if (wystapienia_wsk[liczby[i]] == 0)
            suma += koszty[liczby[i]];
        else if (wystapienia_wsk[liczby[i]] == 1)
            suma -= koszty[liczby[i]];
        wystapienia_wsk[liczby[i]]++;
        tree[base+i] = suma;
    }

    for (int i = base-1; i >= 1; --i)
        tree[i] = max(tree[i*2], tree[i*2+1]);

    for (int i = 0; i < n; ++i)
    {
        wyn = max(wyn, tree[1] + ile_dod);
        int val = liczby[i];

        if (wystapienia_wsk[val] == wystapienia[val].size())
            wystapienia_wsk[val] = 0;

        if (wystapienia_wsk[val] + 1 == wystapienia[val].size())
            ile_dod += -koszty[val];
        else if (wystapienia_wsk[val] + 2 == wystapienia[val].size())
        {
            ile_dod += -koszty[val];
            dod_update = 2 * koszty[val];
            l_zap = wystapienia[val][wystapienia_wsk[val]+1]+1;
            update(1,base,1);
        }
        else
        {
            ile_dod += -koszty[val];

            dod_update = 2 * koszty[val];
            l_zap = wystapienia[val][wystapienia_wsk[val]+1]+1;
            update(1,base,1);

            dod_update = -koszty[val];
            l_zap = wystapienia[val][wystapienia_wsk[val]+2]+1;
            update(1,base,1);
        }
        wystapienia_wsk[val]++;
    }

    cout << wyn << '\n';

    return 0;
}