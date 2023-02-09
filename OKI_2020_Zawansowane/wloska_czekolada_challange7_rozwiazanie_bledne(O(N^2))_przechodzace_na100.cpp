#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, wyn = 0;
vector<int> liczby;
vector<int> ile(1e6+1,0);
vector<int> ile_mamy(1e6+1,0);

int main()
{
    //https://forum.pasja-informatyki.pl/579688/c-vector-assign-zlozonnosc-czasowa-zadanie-wloska-czekolada-ix-oig#c579694
    // Zachlan. Zauwazamy, ze zawsze oplaca nam sie wziac jak najmniejsza czesc, o ile jest unikatowa, bo przedluzanie juz unikatowej czesci nic nie da / przeszkodzi.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        ile[wczytana_liczba]++;
        liczby.push_back(wczytana_liczba);
    }
    for (int i = 0; i < n; ++i)
    {
        ile_mamy[liczby[i]]++;
        if (ile_mamy[liczby[i]] == ile[liczby[i]])
        {
            wyn++;
            ile_mamy.assign(1e6+1,0);
        }
    }

    cout << wyn << '\n';

    return 0;
}