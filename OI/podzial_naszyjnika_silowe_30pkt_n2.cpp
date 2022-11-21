#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, wczytana_liczba = 0, wyn = 0, min_roznica = 1e8;
vector<int> elementy_naszyjnika;
vector<int> wyst;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    wyst.assign(k+1,0);

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        wyst[wczytana_liczba]++;
        elementy_naszyjnika.push_back(wczytana_liczba);
    }

    for (int i = 0; i < n; ++i)
    {
        int ile_roznych_ma_przedzial = 0;
        int ile_pasuje = 0;
        vector<int> stat;
        stat.assign(k+1,0);
        for (int j = 0; j < n-1; ++j)
        {
            if (stat[elementy_naszyjnika[(i+j) % n]] == 0)
            {
                ile_roznych_ma_przedzial++;
            }
            stat[elementy_naszyjnika[(i+j) % n]]++;
            if (stat[elementy_naszyjnika[(i+j) % n]] == wyst[elementy_naszyjnika[(i+j) % n]])
            {
                ile_pasuje++;
            }
            if (ile_pasuje == ile_roznych_ma_przedzial)
            {
                wyn++;
                min_roznica = min(min_roznica,abs((j+1) - (n-(j+1))));
            }
        }
    }

    cout << wyn / 2 << " " << min_roznica << '\n';

    return 0;
}
