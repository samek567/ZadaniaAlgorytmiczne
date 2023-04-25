#include <iostream>

using namespace std;

int n = 0, wczytana_liczba = 0, idx_1 = -1, idx_2 = -1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba == 1)
        {
            if (idx_1 == -1)
                idx_1 = i + 1;
            else
                idx_2 = i + 1;
        }
    }

    if (idx_1 == -1)
        cout << "2" << '\n' << "2" << '\n' << "1 2" << '\n';
    else if (idx_2 == -1)
        cout << "1" << '\n' << "2" << '\n' << "1 2" << '\n';
    else
        cout << "0" << '\n' << "2" << '\n' << "1" << ' ' << "2" << '\n';

    return 0;
}