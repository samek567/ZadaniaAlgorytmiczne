#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, k = 447, wczytana_liczba = 0;
ll wyn = 0;
vector<bool> stat;
vector<int> przedzialy_suma_lewo;
vector<int> przedzialy_suma_prawo;
vector<int> przedzialy_ile_elementow;

int main()
{
    // O(N * sqrt(N)). Dekompozycja Pierwiastkowa. k = około pierwiastek z N.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    stat.assign(n,false);
    przedzialy_ile_elementow.assign(n / k + 1, 0);
    przedzialy_suma_lewo.assign(n / k + 1, 0);
    przedzialy_suma_prawo.assign(n / k + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        wczytana_liczba--;
        wyn = 0;

        stat[wczytana_liczba] = true;
        for (int j = wczytana_liczba-1; j >= 0 && j / k == wczytana_liczba / k; --j)
            if (stat[j] == true)
                wyn += wczytana_liczba - j;
        for (int j = wczytana_liczba+1; j < n && j / k == wczytana_liczba / k; ++j)
            if (stat[j] == true)
                wyn += j - wczytana_liczba;

        int odl = wczytana_liczba - (wczytana_liczba / k * k);
        przedzialy_suma_lewo[wczytana_liczba / k] += k - odl;
        for (int j = wczytana_liczba / k - 1; j >= 0; --j)
        {
            wyn += przedzialy_suma_lewo[j] + przedzialy_ile_elementow[j] * odl;
            odl += k;
        }

        odl = (wczytana_liczba / k * k + k - 1) - wczytana_liczba;
        przedzialy_suma_prawo[wczytana_liczba / k] += k - odl;
        int ile = n / k;
        if (n % k != 0)
            ile++;
        for (int j = wczytana_liczba / k + 1; j < ile; ++j)
        {
            wyn += przedzialy_suma_prawo[j] + przedzialy_ile_elementow[j] * odl;
            odl += k;
        }

        przedzialy_ile_elementow[wczytana_liczba / k]++;

        printf("%lld\n",wyn);
    }
    return 0;
}