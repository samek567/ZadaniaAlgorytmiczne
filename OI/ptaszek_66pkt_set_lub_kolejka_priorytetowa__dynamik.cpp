#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

struct Element_seta
{
    int dp;
    int wartosc;

    bool operator < (const Element_seta &element_seta) const
    {
        if (dp != element_seta.dp)
        {
            return dp < element_seta.dp;
        }
        return wartosc > element_seta.wartosc;
    }
};

int n = 0, q = 0, wczytana_liczba = 0, zapytanie = 0;
vector<int> liczby;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    cin >> q;

    for (int z = 0; z < q; ++z)
    {
        cin >> zapytanie;

        vector<int> dp;
        dp.assign(n,0);
        multiset<Element_seta> dp_set;

        for (int i = 1; i < n; ++i)
        {
            dp_set.insert({dp[i-1],liczby[i-1]});
            if (i - zapytanie > 0)
            {
                dp_set.erase(dp_set.lower_bound({dp[i - zapytanie - 1],liczby[i - zapytanie - 1]}));
            }
            auto it = dp_set.begin();
            dp[i] = it->dp;
            if (it->wartosc <= liczby[i])
            {
                dp[i]++;
            }
        }

        cout << dp[n-1] << "\n";
    }

    return 0;
}
