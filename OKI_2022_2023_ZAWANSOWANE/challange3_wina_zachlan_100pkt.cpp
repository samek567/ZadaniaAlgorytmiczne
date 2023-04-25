#include <iostream>

using namespace std;

int n = 0, k = 0, wczytana_liczba = 0, min_wyn = 1e8;

int main()
{
    // Zachlan.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            cin >> wczytana_liczba;
            if ((i-j) * (j+1) <= k)
            {
                min_wyn = min(min_wyn,wczytana_liczba);
            }
        }
    }

    cout << min_wyn << '\n';

    return 0;
}