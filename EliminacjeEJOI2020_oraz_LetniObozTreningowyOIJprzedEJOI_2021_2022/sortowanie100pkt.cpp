#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n = 0, wczytana_liczba = 0, ile_zmian = 0;
vector<int> elementy;
unordered_map<int,pair<int,int>> stat; // Wartosc, ile parzystych, ile nieparzystych.

int main()
{
    // O(n log n), na pomysl, ze na idx-ach parzystych mozemy dowolnie permutowac, i dowolnie na idx-ach nieparzystych mozna dowolnie permutowac.
    // Dzieki! https://forum.pasja-informatyki.pl/577887/zadanie-sortowanie?show=577887#q577887
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        elementy.push_back(wczytana_liczba);
        if (auto it = stat.find(wczytana_liczba) == stat.end())
            stat.insert({wczytana_liczba,{0,0}});
        if (i % 2 == 0)
            stat[wczytana_liczba].first++;
        else
            stat[wczytana_liczba].second++;
    }
    sort(elementy.begin(),elementy.end());
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            if (stat[elementy[i]].first > 0)
                stat[elementy[i]].first--;
            else
                ile_zmian++;
        }
        else
        {
            if (stat[elementy[i]].second > 0)
                stat[elementy[i]].second--;
            else
                ile_zmian++;
        }
    }
    printf("%d",ile_zmian / 2);
    return 0;
}