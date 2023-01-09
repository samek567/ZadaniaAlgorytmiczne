#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, k = 0, wczytana_liczba = 0, lewy_wsk = 0, prawy_wsk = 0;
ll wyn = 0;
vector<int> liczby;
vector<int> stat;

inline void przesuwaj_lewy()
{
    stat[liczby[lewy_wsk]]--;
    wyn += prawy_wsk - lewy_wsk + 1;
    lewy_wsk++;
    if (lewy_wsk > prawy_wsk)
        prawy_wsk = lewy_wsk;
}

int main()
{
    // O(n) - Gasienica z statystykami.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    stat.assign(1e6+1,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    stat[liczby[0]] = 1;
    while (true)
    {
        if (lewy_wsk == prawy_wsk && lewy_wsk == n-1)
        {
            wyn++;
            break;
        }
        if (prawy_wsk == n-1)
            przesuwaj_lewy();
        else if (stat[liczby[prawy_wsk+1]] + 1 <= k)
        {
            prawy_wsk++;
            stat[liczby[prawy_wsk]]++;
        }
        else
            przesuwaj_lewy();
    }
    printf("%lld",wyn);

    return 0;
}