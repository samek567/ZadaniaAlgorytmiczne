#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll n = 0, wczytana_liczba = 0, MOD = 1e9+7, sum = 0, akt_sum = 0, wyn = 0;
vector<ll> stat(5e5+5,0);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        akt_sum = (sum - stat[wczytana_liczba] + 1 + MOD + MOD + MOD) % MOD;
        stat[wczytana_liczba] = (stat[wczytana_liczba] + akt_sum) % MOD;
        sum = (sum + akt_sum) % MOD;
    }
    printf("%lld",sum);
    return 0;
}