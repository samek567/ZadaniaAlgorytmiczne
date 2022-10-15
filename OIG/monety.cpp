#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    unsigned long long aktualna_liczba = 0;
    unsigned long long wynik = 0;
    vector<unsigned long long> statystyki;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> aktualna_liczba;
        if (aktualna_liczba > n)
        {
            statystyki.push_back(n);
        }
        else
        {
            statystyki.push_back(aktualna_liczba);
        }
    }

    sort(statystyki.begin(),statystyki.end());

    wynik = statystyki[0];

    for (int i = 1; i < n; ++i)
    {
        wynik = wynik * (statystyki[i] - i);
        wynik = wynik % (1000000000+7);
    }

    cout << wynik;
    return 0;
}