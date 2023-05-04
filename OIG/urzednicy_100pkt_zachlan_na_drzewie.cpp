#include <iostream>
#include <vector>

using namespace std;

int n = 0, wyn = 0, wczytana_liczba = 0;
vector<int> parent;
vector<int> ile_zapas;
vector<bool> czy_lisc;

int main()
{
    // O(N), zachlan na drzewie, nie mozna zrobic vectora vectorow krawedzie, bo zamala pamiec.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    parent.assign(n+1,0);
    for (int i = 2; i <= n; ++i)
        cin >> parent[i];

    ile_zapas.assign(n+1,0);
    czy_lisc.assign(n+1,true);
    for (int i = n; i >= 1; --i)
    {
        int v = i;
        czy_lisc[parent[v]] = false;
        if (czy_lisc[v] == true)
        {
            ile_zapas[parent[v]]++;
            continue;
        }
        if (ile_zapas[v] == 0)
            ile_zapas[parent[v]]++;
        else
        {
            ile_zapas[v]--;
            wyn++;
            ile_zapas[parent[v]] += ile_zapas[v];
        }
    }

    cout << wyn << '\n';

    return 0;
}
