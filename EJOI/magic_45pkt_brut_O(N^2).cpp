#include <iostream>
#include <vector>

using namespace std;

int n = 0, przesuniecie = 65, k = 0, ile_max = 0, ile_ma_maxa = 0, wyn = 0;
string ciag;
vector<int> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;

    stat.assign(200,0);
    for (int i = 0; i < n; ++i)
        stat[ciag[i]-przesuniecie]++;

    for (int i = 0; i < 200; ++i)
        if (stat[i] > 0)
            k++;
    for (int i = 0; i < n; ++i)
    {
        fill(stat.begin(), stat.end(), 0);
        ile_max = 0, ile_ma_maxa = 0;
        for (int j = i; j < n; ++j)
        {
            stat[ciag[j]-przesuniecie]++;
            if (stat[ciag[j]-przesuniecie] > ile_max)
            {
                ile_max = stat[ciag[j]-przesuniecie];
                ile_ma_maxa = 0;
            }
            if (stat[ciag[j]-przesuniecie] == ile_max)
                ile_ma_maxa++;
            if (ile_ma_maxa == k)
                wyn++;
        }
    }

    cout << wyn << '\n';

    return 0;
}
