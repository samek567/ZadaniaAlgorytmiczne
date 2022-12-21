#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0;
vector<int> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    stat.assign(n+1,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba > n)
        {
            printf("NIE");
            return 0;
        }
        stat[wczytana_liczba]++;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (stat[i] == 0)
        {
            printf("NIE");
            return 0;
        }
    }

    printf("TAK");

    return 0;
}
