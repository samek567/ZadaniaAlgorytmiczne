#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Wyklad
{
    int poczatek;
    int koniec;
};

int n = 0, a = 0, b = 0, wsk = -1;
vector<Wyklad> wyklady;
vector<int> dp;
vector<pair<int,int>> stat[30001];
vector<int> jaki_idx_wyklad(30001,-1); // Jaki wyklad konczy sie najpozniej w momencie i. Dzieki temu mozemy dla kazdego wykladu odpowiadac w czasie stalym O(1)!

int main()
{
    // O(N+K), gdzie K, to max(b), jak by K, bylo bardzo duze(tak ze nie moglibysmy zrobic tablicy vectorow,
    // to nie da sie szybciej niz O(N lg N), z binary searchem. Patrz na zadanie Wycinka drzew z 1 etapu XVI OIJ, ten sam motyw.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dp.assign(n,-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        stat[b].push_back({a,b}); // do counting sorta
    }

    // Counting sort
    for (int i = 0; i <= 30000; ++i)
        for (int j = 0; j < stat[i].size(); ++j)
            wyklady.push_back({stat[i][j].first, stat[i][j].second});

    for (int i = 0; i <= 30000; ++i)
    {
        while(true)
        {
            if (wyklady[wsk+1].koniec <= i && wsk != n-1)
                wsk++;
            else
                break;
        }
        jaki_idx_wyklad[i] = wsk;
    }

    dp[0] = wyklady[0].koniec - wyklady[0].poczatek;
    for (int i = 1; i < n; ++i)
    {
        dp[i] = dp[i-1];
        if (jaki_idx_wyklad[wyklady[i].poczatek] == -1)
            dp[i] = max(dp[i],wyklady[i].koniec - wyklady[i].poczatek);
        else
            dp[i] = max(dp[i],dp[jaki_idx_wyklad[wyklady[i].poczatek]] + wyklady[i].koniec - wyklady[i].poczatek);
    }

    cout << dp[n-1] << '\n';

    return 0;
}