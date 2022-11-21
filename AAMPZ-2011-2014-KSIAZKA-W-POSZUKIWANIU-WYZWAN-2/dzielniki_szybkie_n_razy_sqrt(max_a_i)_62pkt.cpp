#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, max_a_i = 0;
long long wyn = 0;
vector<int> liczby;
vector<int> stat;

int main()
{
    // Dzielniki 2014 1 gwiazdka
    // O(n * sqrt(max_a_i))
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        max_a_i = max(max_a_i,wczytana_liczba);
        liczby.push_back(wczytana_liczba);
    }
    stat.assign(max_a_i+1,0);
    for (int i = 0; i < n; ++i)
    {
        stat[liczby[i]]++;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j * j <= liczby[i]; ++j)
        {
            if (liczby[i] % j == 0)
            {
                wyn += stat[j];
                if (j != liczby[i]/j)
                {
                    wyn += stat[liczby[i]/j];
                }
            }
        }
        wyn--;
    }

    cout << wyn << '\n';

    return 0;
}