#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    int B;
    int ile;
    bool operator < (const Element &element) const
    {
        return B > element.B;
    }
};

int n = 0, wczytana_liczba = 0, zap = 0, INF = 100000000;
const int MAX_SIZE = 20000;
vector<Element> elementy;
int jaki_idx[20001] = {0};
vector<int> dp(20001, INF);
vector<int> idx_poprzedniej(20001,-1);
vector<int> wyn;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    wyn.assign(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        elementy.push_back({wczytana_liczba,-1});
        jaki_idx[wczytana_liczba] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        elementy[i].ile = wczytana_liczba;
    }
    sort(elementy.begin(), elementy.end());

    dp[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < elementy[i].ile; ++j)
        {
            for (int k = MAX_SIZE; k >= 0; --k)
            {
                if (k + elementy[i].B <= MAX_SIZE)
                {
                    if (dp[k] != INF && dp[k] + 1 < dp[k+elementy[i].B])
                    {
                        dp[k+elementy[i].B] = dp[k] + 1;
                        idx_poprzedniej[k+elementy[i].B] = k;
                    }
                }
            }
        }
    }

    cin >> zap;
    cout << dp[zap] << '\n';
    int odtw = zap;
    while(true)
    {
        if (idx_poprzedniej[zap] == -1)
            break;
        wyn[jaki_idx[zap - idx_poprzedniej[zap]]]++;
        zap = idx_poprzedniej[zap];
    }

    for (int i = 0; i < n; ++i)
        cout << wyn[i] << ' ';

    return 0;
}