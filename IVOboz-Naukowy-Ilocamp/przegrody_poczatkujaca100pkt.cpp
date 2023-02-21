#include <iostream>

using namespace std;

int n = 0, wczytana_liczba = 0, maxx = 0, wyn = 0;

int main()
{
    // O(N)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> wczytana_liczba;
        maxx = max(maxx,wczytana_liczba);
        if (maxx == i)
            wyn++;
    }

    cout << wyn << '\n';

    return 0;
}