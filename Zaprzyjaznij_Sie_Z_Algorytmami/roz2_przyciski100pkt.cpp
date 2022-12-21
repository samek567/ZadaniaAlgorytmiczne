#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, akt_max = 0,t_max = 0;
vector<int> stat;

int main()
{
    // O(n+m)
    /*
     Zadanie z 2 etapu VI OIG na zliczanie.
     t_max - total max (max po aktualizacji n+1)
     akt_max max ktory nie zostal jeszcze podmieniony, ale bedzie t_maxem przy aktualizacji. Nie
     mozemy go mylic z t_max.
     */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    stat.assign(n+1,0);
    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba == n+1)
        {
            t_max = akt_max;
        }
        else
        {
            if (stat[wczytana_liczba] < t_max)
                stat[wczytana_liczba] = t_max;
            stat[wczytana_liczba]++;
            akt_max = max(akt_max,stat[wczytana_liczba]);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        printf("%d ",max(stat[i],t_max));
    }

    return 0;
}
