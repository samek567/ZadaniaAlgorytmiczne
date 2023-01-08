#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

int n = 0, k = 0, wczytana_liczba = 0;
ll wyn = 0;
vector<int> liczby;
unordered_map<int,int> stat; // A_i, ile wystapien

int main()
{
    // O(n log n)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    for (int i = 0; i < k; ++i)
    {
        if (auto it = stat.find(liczby[i]) != stat.end())
            stat[liczby[i]]++;
        else
            stat[liczby[i]] = 1;
    }

    for (int i = k; i < n; ++i)
    {
        if (auto it = stat.find(liczby[i]) != stat.end())
            stat[liczby[i]]++;
        else
            stat[liczby[i]] = 1;
        wyn += stat[liczby[i-k]] - 1;
        stat[liczby[i-k]]--;
    }

    for (int i = n-k; i < n; ++i)
    {
        wyn += stat[liczby[i]] - 1;
        stat[liczby[i]]--;
    }

    printf("%lld",wyn);

    return 0;
}