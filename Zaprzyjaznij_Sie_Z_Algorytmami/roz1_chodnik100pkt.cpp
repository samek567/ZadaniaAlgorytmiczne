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
    for (int i = 0; i < n-1; ++i)
    {
        cin >> wczytana_liczba;
        stat[wczytana_liczba]++;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (stat[i] == 0)
            printf("%d",i);
    }

    return 0;
}
