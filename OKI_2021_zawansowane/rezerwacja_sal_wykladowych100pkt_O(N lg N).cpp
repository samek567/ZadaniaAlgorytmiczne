#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Wyklad
{
    int poczatek;
    int koniec;
    bool operator < (const Wyklad &wyklad) const
    {
        return koniec < wyklad.koniec;
    }
};

int n = 0, a = 0, b = 0, poczatek = 0, koniec = 0, srodek = 0;
vector<Wyklad> wyklady;
vector<int> dp;

int main()
{
    // Sortowanie, Dynamik z wyszukiwaniem binarnym
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dp.assign(n,-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        wyklady.push_back({a,b});
    }
    sort(wyklady.begin(),wyklady.end());

    dp[0] = wyklady[0].koniec - wyklady[0].poczatek;
    for (int i = 1; i < n; ++i)
    {
        dp[i] = dp[i-1];
        poczatek = -1, koniec = n;
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (wyklady[srodek].koniec <= wyklady[i].poczatek)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        if (poczatek != -1)
            dp[i] = max(dp[i],dp[poczatek] + wyklady[i].koniec - wyklady[i].poczatek);
        else
            dp[i] = max(dp[i],wyklady[i].koniec - wyklady[i].poczatek);
    }

    cout << dp[n-1] << '\n';

    return 0;
}