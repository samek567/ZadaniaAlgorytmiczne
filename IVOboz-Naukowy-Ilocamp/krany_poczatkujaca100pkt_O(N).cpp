#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, w = 0, wczytana_liczba = 0, suma = 0;
vector<int> liczby;

int main()
{
    // O(N)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba <= 0)
            continue;
        liczby.push_back(wczytana_liczba);
        suma += wczytana_liczba;
    }

    sort(liczby.begin(), liczby.end());

    if (suma >= w * liczby.size())
    {
        cout << "0" << '\n';
        return 0;
    }

    for (int i = 0; i < liczby.size() - 1; ++i)
    {
        suma -= liczby[i];
        if (suma >= w * (liczby.size()-i-1))
        {
            cout << i+1 << '\n';
            return 0;
        }
    }

    cout << "NIE" << '\n';

    return 0;
}