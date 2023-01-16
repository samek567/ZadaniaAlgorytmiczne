#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0;
vector<int> stat_wystapien(1e6+1,0);
vector<int> ile(1e6+1,0);
vector<int> liczby;

int main()
{
    // O(n log n)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        ile[wczytana_liczba]++;
    }
    for (int i = 1; i <= 1e6; ++i)
    {
        if (ile[i] != 0)
        {
            stat_wystapien[i] += ile[i] - 1;
            for (int j = i + i; j <= 1e6; j += i)
                stat_wystapien[j] += ile[i];
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%d ",(n-1) - stat_wystapien[liczby[i]]);

    return 0;
}
