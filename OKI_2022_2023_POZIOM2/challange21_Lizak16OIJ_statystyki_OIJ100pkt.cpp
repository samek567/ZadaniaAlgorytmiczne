#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n = 0, wczytana_liczba = 0, wyn = 1e9;
unordered_map<int, vector<int>> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (auto it = stat.find(wczytana_liczba) != stat.end())
            stat[wczytana_liczba].push_back(i);
        else
            stat.insert({wczytana_liczba,{i}});
    }

    for (auto it = stat.begin(); it != stat.end(); ++it)
    {
        int SIZE = it->second.size();
        for (int i = 0; i < SIZE-2; ++i)
            wyn = min(wyn, it->second[i+2] - it->second[i] + 1);
    }

    if (wyn == 1e9)
        cout << "NIE" << '\n';
    else
        cout << wyn << '\n';

    return 0;
}