#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, suma = 0, a_i = 0, b_i = 0, wyn = 0;
vector<int> liczby;
vector<int> stat;
vector<int> liczby_pasujace;
vector<vector<int>> sumy_prefiksowe;

int main()
{
    // O(n*sqrt(n) + z*sqrt(n))
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    stat.assign(n+1,0);
    sumy_prefiksowe.assign(n+1,{});
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        if (wczytana_liczba <= n)
            stat[wczytana_liczba]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (stat[i] >= i)
        {
            liczby_pasujace.push_back(i);
            suma = 0;
            for (int j = 0; j < n; ++j)
            {
                if (liczby[j] == i)
                    suma++;
                sumy_prefiksowe[i].push_back(suma);
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        a_i--;
        b_i--;
        wyn = 0;
        for (int j = 0; j < liczby_pasujace.size(); ++j)
        {
            if (a_i == 0)
            {
                if (sumy_prefiksowe[liczby_pasujace[j]][b_i] == liczby_pasujace[j])
                    wyn++;
            }
            else
            {
                if (sumy_prefiksowe[liczby_pasujace[j]][b_i] - sumy_prefiksowe[liczby_pasujace[j]][a_i-1] == liczby_pasujace[j])
                    wyn++;
            }

        }
        printf("%d\n",wyn);
    }
    return 0;
}
