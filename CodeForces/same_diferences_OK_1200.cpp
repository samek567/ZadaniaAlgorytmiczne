#include <iostream>
#include <unordered_map>

using namespace std;

long long t = 0, n = 0, wczytana_liczba = 0, wyn = 0;
unordered_map<long long,long long> stat_przesuniecia;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        wyn = 0;
        stat_przesuniecia.clear();
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytana_liczba;
            if (auto it = stat_przesuniecia.find(wczytana_liczba - j) != stat_przesuniecia.end())
                stat_przesuniecia[wczytana_liczba - j]++;
            else
                stat_przesuniecia[wczytana_liczba - j] = 0;
        }
        for (auto it = stat_przesuniecia.begin(); it != stat_przesuniecia.end(); ++it)
            wyn += it->second * (it->second+1) / 2;
        printf("%lld\n",wyn);
    }
    return 0;
}