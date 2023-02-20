#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, wyn = 0;
vector<int> liczby;

int main()
{
    // O(N)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    for (int i = n-2; i >= 0; --i)
    {
        if (liczby[i] >= liczby[i+1])
        {
            wyn++;
            liczby[i] = liczby[i+1]-1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (liczby[i] == 0)
        {
            cout << "-1" << '\n';
            return 0;
        }
    }

    cout << wyn << '\n';

    return 0;
}