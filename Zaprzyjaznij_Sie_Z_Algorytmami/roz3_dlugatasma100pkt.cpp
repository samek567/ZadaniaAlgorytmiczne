#include <iostream>

using namespace std;

int n = 0, wczytana_liczba = 0, min_wyn = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        min_wyn = min(min_wyn,wczytana_liczba);
    }

    printf("%d.00",min_wyn);

    return 0;
}
