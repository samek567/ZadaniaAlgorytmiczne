#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int n = 0, m = 0, z = 0, wczytana_liczba = 0, a = 0, b = 0, wyn = 0;
const unsigned long long SIZE = 1e6+1;
string decyzja;
vector<bitset<SIZE>> czy_mamy;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    czy_mamy.assign(n,{});

    for (int i = 0; i < n; ++i)
    {
        cin >> z;
        while(z--)
        {
            cin >> wczytana_liczba;
            czy_mamy[i].set(wczytana_liczba);
        }
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> decyzja >> a >> b;
        a--, b--;
        if (decyzja == "INTERSECTION")
            cout << (czy_mamy[a] & czy_mamy[b]).count() << '\n';
        else
            cout << (czy_mamy[a] | czy_mamy[b]).count() << '\n';
    }

    return 0;
}