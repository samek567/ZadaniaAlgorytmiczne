#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, ile_zolniezy_lacznie = 0;
vector<int> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    stat.assign(1e6+5,0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> wczytana_liczba;
            stat[wczytana_liczba]++;
            if (wczytana_liczba != 0)
                ile_zolniezy_lacznie++;
        }
    }
    for (int i = 1; i <= 1e6; ++i)
    {
        if (stat[i] > ile_zolniezy_lacznie / 2)
        {
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}