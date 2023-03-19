#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, base = (1 << 15), rozmiar_drzewa = base * 2, wczytana_liczba = 0, sum = 0;
string ciag;
vector<int> nawiasy;
vector<int> tree;
vector<int> tree2;

inline void update_min(int l_zap, int p_zap, int l_kontrolowane, int p_kontrolowane, int v, int val)
{
    if (p_zap < l_kontrolowane or l_zap > p_kontrolowane)
        return;
    else if (l_kontrolowane >= l_zap and p_kontrolowane <= p_zap)
    {
        tree[v] += val;
        tree2[v] += val;
    }
    else if (l_kontrolowane != p_kontrolowane)
    {
        if (tree2[v] != 0)
        {
            tree[v*2] += tree2[v];
            tree[v*2+1] += tree2[v];
            tree2[v*2] += tree2[v];
            tree2[v*2+1] += tree2[v];
            tree2[v] = 0;
        }
        update_min(l_zap, p_zap, l_kontrolowane, l_kontrolowane + (p_kontrolowane - l_kontrolowane + 1 - 2) / 2,v*2, val);
        update_min(l_zap, p_zap, l_kontrolowane + (p_kontrolowane - l_kontrolowane + 1) / 2, p_kontrolowane, v*2+1, val);
        tree[v] = min(tree[v*2], tree[v*2+1]);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tree.assign(rozmiar_drzewa,1e9);
    tree2.assign(rozmiar_drzewa,0);

    cin >> n >> ciag;
    nawiasy.assign(n+1,0);
    for (int i = 1; i <= n; ++i)
    {
        if (ciag[i-1] == '(')
        {
            nawiasy[i] = 1;
            ++sum;
        }
        else
        {
            nawiasy[i] = -1;
            --sum;
        }
        tree[base+i-1] = sum;
    }

    for (int i = base-1; i >= 1; --i)
        tree[i] = min(tree[i*2], tree[i*2+1]);

    cin >> m;
    while(m--)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba == 0)
        {
            if (tree[1] == 0 and sum == 0)
                cout << "TAK" << '\n';
            else
                cout << "NIE" << '\n';
        }
        else if (nawiasy[wczytana_liczba] == 1)
        {
            sum -= 2;
            update_min(wczytana_liczba,base,1,base,1,-2);
            nawiasy[wczytana_liczba] = -1;
        }
        else
        {
            sum += 2;
            update_min(wczytana_liczba,base,1,base,1,2);
            nawiasy[wczytana_liczba] = 1;
        }
    }

    return 0;
}