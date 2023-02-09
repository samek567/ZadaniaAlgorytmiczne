#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, a_i = 0, b_i = 0;
vector<vector<int>> sumy_prefiksowe;
vector<int> kandydaci_na_lidera;
vector<int> stat;
vector<int> liczby;

int main()
{
    // O(N^sqrt(N)) Kandydatow na lidera bedzie maksymalnie pierwiastek,
    // z wzoru X * (X+1) / 2 = N (przy zalozeniu ze bierzemy najmniejsze, gdybysmy brali wieksze, to wiadomo, ze liczba kandydatow bedzie mniejsza / taka sama.
    // Zeby rownosc X * (X+1) / 2 = N byla prawdziwa X musi byc okolo pierwiastek z N.
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
        if (wczytana_liczba > n)
            continue;
        stat[wczytana_liczba]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (stat[i] >= i)
        {
            kandydaci_na_lidera.push_back(i);
            int s = 0;
            for (int j = 0; j < n; ++j)
            {
                if (liczby[j] == i)
                    s++;
                sumy_prefiksowe[i].push_back(s);
            }
        }
    }

    while(m--)
    {
        cin >> a_i >> b_i;
        a_i--;
        b_i--;
        int wyn = 0;
        for (int i = 0; i < kandydaci_na_lidera.size(); ++i)
        {
            int suma_na_przedziale = 0;
            if (a_i == 0)
                suma_na_przedziale = sumy_prefiksowe[kandydaci_na_lidera[i]][b_i];
            else
                suma_na_przedziale = sumy_prefiksowe[kandydaci_na_lidera[i]][b_i] - sumy_prefiksowe[kandydaci_na_lidera[i]][a_i-1];
            if (suma_na_przedziale == kandydaci_na_lidera[i])
                wyn++;
        }
        cout << wyn << '\n';
    }
    return 0;
}