#include <iostream>
#include <unordered_map>

using namespace std;

int n = 0, wczytana_liczba = 0, wyn = 0;
unordered_map<int,int> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n;
    while(n--)
    {
        cin >> wczytana_liczba;
        if (auto it = stat.find(wczytana_liczba) != stat.end())
        {
            if (stat[wczytana_liczba] == 0)
            {
                stat[wczytana_liczba] = 1;
                wyn++;
            }
            else
            {
                stat[wczytana_liczba] = 0;
                wyn--;
            }
        }
        else
        {
            stat[wczytana_liczba] = 1;
            wyn++;
        }
    }

    cout << wyn << '\n';

    return 0;
}