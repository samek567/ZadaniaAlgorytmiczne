#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

int n = 0, wczytana_liczba = 0, wyn = 0;
ll masa = 0;
vector<int> liczby;
multiset<int> do_zjedzenia;

int main()
{
    // O(N lg N), symulujemy z multisetem / kolejka priorytetowa / setem.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    for (int i = 0; i < n; ++i)
    {
        if (liczby[i] >= 0)
            masa += (ll)liczby[i];
        else
        {
            ll val = abs((ll)liczby[i]);
            masa -= val;
            do_zjedzenia.insert((ll)2 * val);
            while (masa < 0)
            {
                wyn++;
                masa += *do_zjedzenia.rbegin();
                do_zjedzenia.erase(do_zjedzenia.lower_bound(*do_zjedzenia.rbegin()));
            }
        }
    }

    cout << wyn << '\n';

    return 0;
}