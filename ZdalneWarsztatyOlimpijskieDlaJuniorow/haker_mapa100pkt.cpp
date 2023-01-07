#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n = 0, wczytana_liczba = 0, ile_zer = 0;
vector<int> liczby;
unordered_map<int,bool> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba == 0)
            ile_zer++;
        else
        {
            liczby.push_back(wczytana_liczba);
            stat[wczytana_liczba] = true;
        }
    }
    if (ile_zer > 1)
    {
        printf("TAK");
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        if (auto it = stat.find(liczby[i] * 2) != stat.end())
        {
            printf("TAK");
            return 0;
        }
    }
    printf("NIE");
    return 0;
}