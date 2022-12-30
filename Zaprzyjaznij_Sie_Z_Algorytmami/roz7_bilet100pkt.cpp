#include <iostream>
#include <vector>

using namespace std;

int z = 0, n = 0;
long long wczytana_liczba = 0, max_wyn_prefix = 0, max_wyn_sufix = 0, suma = 0;
vector<long long> liczby;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> z;
    for (int g = 0; g < z; ++g)
    {
        liczby.clear();
        max_wyn_prefix = 0;
        max_wyn_sufix = 0;
        suma = 0;

        cin >> n;
        for (int i = 0; i < n-1; ++i)
        {
            cin >> wczytana_liczba;
            liczby.push_back(wczytana_liczba);
        }

        for (int i = 0; i < n-1; ++i)
        {
            suma += liczby[i];
            max_wyn_prefix = max(max_wyn_prefix,suma);
        }
        suma = 0;
        for (int i = n-2; i >= 0; --i)
        {
            suma += liczby[i];
            max_wyn_sufix = max(max_wyn_sufix,suma);
        }

        printf("%lld\n",max_wyn_prefix + max_wyn_sufix);
    }

    return 0;
}
