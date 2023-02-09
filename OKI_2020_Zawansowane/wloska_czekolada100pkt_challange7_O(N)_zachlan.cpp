#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, wyn = 0, wsk_zaczecia = 0;
vector<int> liczby;
vector<int> ile(1e6+1,0);
vector<int> ile_mamy(1e6+1,0);

int main()
{
    // https://forum.pasja-informatyki.pl/579688/c-vector-assign-zlozonnosc-czasowa-zadanie-wloska-czekolada-ix-oig
    // O(N), wykonamy 2N operacji. Bo petla j lacznie wykona sie N razy.
    // Wchodzi zachlan. Zawsze oplaca nam sie wziac najmniejszy fragment, ktory jest unitakowy, bo bez sensu kompletnie robic go jeszcze dluzszym.
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
            for (int j = wsk_zaczecia; j <= i; ++j)
                ile_mamy[liczby[j]]--; // Usuwamy to co dodalismy
            wsk_zaczecia = i+1;
        }
    }

    cout << wyn << '\n';

    return 0;
}