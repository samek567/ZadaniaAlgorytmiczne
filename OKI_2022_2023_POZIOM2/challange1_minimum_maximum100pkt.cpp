#include <iostream>
#include <vector>

using namespace std;

int z = 0, n = 0, ile_wystapien = 0;
long long wczytana_liczba = 0, min_val = 0;
vector<long long> liczby;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> z;
    for (int i = 0; i < z; ++i)
    {
        liczby.clear();
        ile_wystapien = 0;
        min_val = 1e15;
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytana_liczba;
            min_val = min(min_val,wczytana_liczba);
            liczby.push_back(wczytana_liczba);
        }
        for (int j = 0; j < n; ++j)
            if (liczby[j] == min_val)
                ile_wystapien++;
        printf("%lld\n",(n-ile_wystapien) * min_val);
    }
    return 0;
}
