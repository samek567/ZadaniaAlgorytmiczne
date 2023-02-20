#include <iostream>

using namespace std;
typedef long long ll;

int n = 0, wczytana_liczba = 0, ile_zer = 0;
ll wyn = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba == 0)
            ile_zer++;
        else
            wyn += ile_zer;
    }

    cout << wyn << '\n';

    return 0;
}