#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, ile_mamy = 0;
vector<int> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    stat.assign(n+1,0);
    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;

        if (stat[wczytana_liczba] == 0)
        {
            stat[wczytana_liczba] = 1;
            ile_mamy++;
        }

        if (ile_mamy == n)
        {
            printf("%d",i+1);
            return 0;
        }
    }

    printf("-1");

    return 0;
}
