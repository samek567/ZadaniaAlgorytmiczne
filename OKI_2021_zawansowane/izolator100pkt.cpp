#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n = 0, wczytana_liczba = 0;
ll wyn = 0;
vector<int> stat(10001,0);
vector<int> liczby;

int main()
{
    // O(N), sortowanie counting sort, na pomysl
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        stat[wczytana_liczba]++;
        wyn += wczytana_liczba;
    }

    for (int i = 1; i <= 10000; ++i)
        for (int j = 0; j < stat[i]; ++j)
            liczby.push_back(i);

    for (int i = 0; i < n / 2; ++i)
        wyn += liczby[n-1-i] - liczby[i];

    cout << wyn << '\n';

    return 0;
}