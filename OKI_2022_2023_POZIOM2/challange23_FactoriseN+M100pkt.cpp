#include <iostream>

using namespace std;

int n = 0, wczytana_liczba = 0, t = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba == 2)
            cout << "2" << '\n';
        else
            cout << wczytana_liczba << '\n';
    }

    return 0;
}