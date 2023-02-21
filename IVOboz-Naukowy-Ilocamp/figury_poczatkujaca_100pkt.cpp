#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0;
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

    for (int i = 0; i < n-3; ++i)
    {
        if (liczby[i] != liczby[i+1] && liczby[i] != liczby[i+2] && liczby[i+1] != liczby[i+2])
        {
            cout << "TAK" << '\n';
            return 0;
        }
    }

    cout << "NIE" << '\n';

    return 0;
}