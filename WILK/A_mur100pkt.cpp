#include <iostream>

using namespace std;

int n = 0, h = 0, wyn = 0, wczytana_liczba = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h;
    for (int i = 0; i < n+1; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba > h)
            wyn += 2;
        else
            ++wyn;
    }

    cout << wyn << '\n';

    return 0;
}