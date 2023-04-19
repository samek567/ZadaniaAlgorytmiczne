#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n = 0, m = 0, wczytana_liczba = 0;
ll ile_zawodnikow = 0;
vector<bool> czy_jest_paczka(1e6+5,false);
vector<bool> czy_zabrane(1e6+5,false);
vector<int> stat(1e6+5,0);
vector<ll> wyn;
vector<bool> czy_jest_w_wyn;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        czy_jest_paczka[wczytana_liczba] = true;
    }

    cin >> m;
    while(m--)
    {
        cin >> wczytana_liczba;
        int ile_do_wziecia = wczytana_liczba, ile = 0;
        while(ile_do_wziecia > 0)
        {
            stat[wczytana_liczba] += wczytana_liczba;
            if (stat[wczytana_liczba] > 1e6)
                break;
            if (czy_zabrane[stat[wczytana_liczba]] == true)
                continue;
            czy_zabrane[stat[wczytana_liczba]] = true;
            ile_do_wziecia--;
            ile++;
            if (czy_jest_paczka[stat[wczytana_liczba]] == true)
            {
                czy_jest_paczka[stat[wczytana_liczba]] = false;
                wyn.push_back(ile_zawodnikow + ile);
            }
        }
        ile_zawodnikow += wczytana_liczba;
    }



    cout << wyn.size() << '\n';
    sort(wyn.begin(), wyn.end());
    for (int i = 0; i < wyn.size(); ++i)
        cout << wyn[i] << '\n';

    return 0;
}