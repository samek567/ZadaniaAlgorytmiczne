#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, q = 0, x = 0, wczytana_liczba = 0, a = 0, b = 0;
ll wyn = 0;
vector<int> liczby;
vector<ll> dp;

int main()
{
    // O(N*Q) - 66pkt, szukanie najdluzszego podciagu rosnacego.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> x;
    dp.assign(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    dp[0] = liczby[0] - x;
    wyn = max(wyn,dp[0]);
    for (int i = 1; i < n; ++i)
    {
        dp[i] = max((ll)liczby[i],liczby[i] + dp[i-1]) - x;
        wyn = max(wyn,dp[i]);
    }
    cout << wyn << ' ';

    while(q--)
    {
        cin >> a >> b;
        liczby[a-1] = b;
        wyn = 0;
        dp[0] = liczby[0] - x;
        wyn = max(wyn,dp[0]);
        for (int i = 1; i < n; ++i)
        {
            dp[i] = max((ll)liczby[i],liczby[i] + dp[i-1]) - x;
            wyn = max(wyn,dp[i]);
        }
        cout << wyn << ' ';
    }
    return 0;
}