#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

int n = 0, k = 0, wczytana_liczba = 0, lewy_wsk = 0, prawy_wsk = 0;
ll wyn = 0;
unordered_map<int,vector<int>> stat; // Jakie idx-y ma okreslone a_i

void przesuwaj_lewy()
{
    wyn += prawy_wsk - lewy_wsk;
    lewy_wsk++;
    if (lewy_wsk > prawy_wsk)
        prawy_wsk = lewy_wsk;
}

int main()
{
    // O(n * log n)
    // Gasienica z statystykami.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        stat[wczytana_liczba].push_back(i);
    }

    for (auto it = stat.begin(); it != stat.end(); ++it)
    {
        lewy_wsk = 0, prawy_wsk = 0;
        while (true)
        {
            if (lewy_wsk == prawy_wsk && lewy_wsk == it->second.size()-1)
                break;
            if (prawy_wsk == it->second.size()-1)
                przesuwaj_lewy();
            else if (it->second[prawy_wsk+1] <= it->second[lewy_wsk] + k)
                prawy_wsk++;
            else
                przesuwaj_lewy();
        }
    }
    printf("%lld",wyn);
    return 0;
}