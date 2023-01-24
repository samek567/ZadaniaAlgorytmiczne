#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int n = 0, k = 0, wczytana_liczba = 0, wyn_min = 0, wyn_max = 0;
ll wyn = 0;
map<int,int> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while(n--)
    {
        cin >> k;
        while(k--)
        {
            cin >> wczytana_liczba;
            if (auto it = stat.find(wczytana_liczba) != stat.end())
                stat[wczytana_liczba]++;
            else
                stat.insert({wczytana_liczba,1});
        }
        wyn_max = stat.rbegin()->first;
        if (stat[wyn_max] == 1)
            stat.erase(wyn_max);
        else
            stat[wyn_max]--;

        wyn_min = stat.begin()->first;
        if (stat[wyn_min] == 1)
            stat.erase(wyn_min);
        else
            stat[wyn_min]--;

        wyn += wyn_max - wyn_min;
    }
    printf("%lld",wyn);
    return 0;
}
