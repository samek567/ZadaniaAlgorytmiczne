#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0;
long long wyn = 0;
vector<int> liczby;

int main()
{
    // Dzielniki 2014 1 gwiazdka
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            if (liczby[i] == liczby[j])
            {
                wyn += 2;
            }
            else if (liczby[i] > liczby[j] && liczby[i] % liczby[j] == 0)
            {
                wyn++;
            }
            else if (liczby[i] < liczby[j] && liczby[j] % liczby[i] == 0)
            {
                wyn++;
            }
        }
    }

    cout << wyn << '\n';

    return 0;
}