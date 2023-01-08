#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n = 0, k = 0, wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0;
long long wyn = 0;
unordered_map<int,vector<int>> stat; // Jakie idx-y ma okreslone a_i

int main()
{
    // O(n * log n * log n)
    // Binary search z statystykami.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        stat[wczytana_liczba].push_back(i);
    }

    for (auto it = stat.begin(); it != stat.end(); ++it)
    {
        for (int i = 0; i < it->second.size(); ++i)
        {
            poczatek = i, koniec = it->second.size();
            while (koniec - poczatek > 1)
            {
                srodek = (poczatek + koniec) / 2;
                if (it->second[srodek] <= it->second[i] + k)
                    poczatek = srodek;
                else
                    koniec = srodek;
            }
            wyn += poczatek - i;
        }
    }
    printf("%lld",wyn);
    return 0;
}