#include <iostream>
#include <vector>

using namespace std;

long long n = 0, wczytana_liczba = 0, max_a_i = 0;
long long wyn = 0;
vector<long long> liczby;
vector<long long> stat;

int main()
{
    // Zadanie dzielniki 2014 1 gwiazdka
    // O(n log n)
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
    for (long long i = 0; i < n; ++i)
    {
        stat[liczby[i]]++;
    }

    for (long long i = 1; i <= max_a_i; ++i)
    {
        wyn += stat[i] * (stat[i]-1);
        for (long long j = i+i; j <= max_a_i; j+=0)
        {
            wyn += stat[i] * stat[j];
            j += i;
        }
    }

    cout << wyn << '\n';

    return 0;
}
