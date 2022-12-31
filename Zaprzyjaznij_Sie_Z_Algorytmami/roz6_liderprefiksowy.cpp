#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n = 0, wczytana_liczba = 0, max_wystapien = 0, max_val = 0, ile_wystapien = 0;
vector<int> kandydaci_na_lidera;
unordered_map<int,int> stat;

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
            stat[wczytana_liczba]++;
        else
            stat.insert({wczytana_liczba,1});
        if (stat[wczytana_liczba] > max_wystapien)
        {
            max_wystapien = stat[wczytana_liczba];
            max_val = wczytana_liczba;
        }
        if (max_wystapien > (i+1) / 2)
            kandydaci_na_lidera.push_back(max_val);
    }

    sort(kandydaci_na_lidera.begin(),kandydaci_na_lidera.end());
    if (kandydaci_na_lidera.empty())
        printf("NIE");
    else
    {
        ile_wystapien = 1;
        for (int i = 1; i < kandydaci_na_lidera.size(); ++i)
        {
            if (kandydaci_na_lidera[i] == kandydaci_na_lidera[i-1])
            {
                ile_wystapien++;
            }
            else
            {
                if (ile_wystapien > n / 2)
                {
                    printf("%d",kandydaci_na_lidera[i-1]);
                    return 0;
                }
                ile_wystapien = 1;
            }
        }
        if (ile_wystapien > n / 2)
        {
            printf("%d",kandydaci_na_lidera[kandydaci_na_lidera.size()-1]);
        }
        else
            printf("NIE");
    }

    return 0;
}
