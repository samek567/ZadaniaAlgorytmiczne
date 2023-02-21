#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Grzyb_stat
{
    ll masa;
    ll przyrost;
};

int n = 0, m = 0, p = 0, d = 0;
ll suma_zbiorow = 0, suma_masa_zebranych = 0, max_wyn = -1e18, max_wyn_dzien = -1, wyn = 0;
vector<int> kandydaci;
vector<Grzyb_stat> grzyby(1e5+1,{0,0}); // 1e5, bo max d_i to 1e5

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> m >> p >> d;
        kandydaci.push_back(d);
        grzyby[d].masa += m;
        grzyby[d].przyrost += p;
        suma_masa_zebranych += m;
        suma_zbiorow += p;
    }
    sort(kandydaci.begin(), kandydaci.end());
    for (int i = 0; i < n; ++i)
    {
        int spr = kandydaci[i]; // Sprawdzany dzien x.

        if (spr != 1) // Jesli jest dzien 1, to dzien 0 nie moze byc wynikiem!
        {
            // Sprawdzamy dzien x-1.
            wyn = suma_masa_zebranych + suma_zbiorow * (spr-1);
            if (wyn > max_wyn)
            {
                max_wyn = wyn;
                max_wyn_dzien = spr-1;
            }
        }

        suma_masa_zebranych -= grzyby[spr].masa;
        suma_zbiorow -= grzyby[spr].przyrost;

        // Sprawdzamy dzien x.
        wyn = suma_masa_zebranych + suma_zbiorow * spr;
        if (wyn > max_wyn)
        {
            max_wyn = wyn;
            max_wyn_dzien = spr;
        }
        grzyby[spr] = {0,0};
    }

    cout << max_wyn_dzien << '\n';

    return 0;
}