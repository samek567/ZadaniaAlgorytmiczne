#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n = 0;
    long long k = 0;
    long long aktualna_liczba = 0;
    long long szukana = 0;
    vector<long long> liczby_podzielne_k;

    cin >> n >> k;

    szukana = k;

    for (int i = 0; i < n; ++i)
    {
        cin >> aktualna_liczba;
        if (aktualna_liczba % k == 0)
        {
            liczby_podzielne_k.push_back(aktualna_liczba);
        }
    }

    sort(liczby_podzielne_k.begin(),liczby_podzielne_k.end());

    for (int i = 0; i < liczby_podzielne_k.size(); ++i)
    {
        if (szukana == liczby_podzielne_k[i])
        {
            szukana += k;
        }
        else
        {
            printf("%lld",szukana);
            return 0;
        }
    }
    return 0;
}