#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct Przedmiot
{
    ll masa;
    int waga;
};

int n = 0;
ll m = 0, sum = 0, wyn = 0;
vector<Przedmiot> przedmioty;
vector<ll> dp;

int main()
{
    // Janek Myszkaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa rozwalil to zadanie w 5 minut!
    // Zakladamy, ze jeden element wpychamy na max-a, reszta plecakiem.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    przedmioty.assign(n,{});
    for (int i = 0; i < n; ++i)
        cin >> przedmioty[i].waga >> przedmioty[i].masa;

    for (int i = 0; i < n; ++i)
        sum += przedmioty[i].waga;

    dp.assign(sum+1,0);

    for (int i = 0; i < n; ++i)
        for (int j = przedmioty[i].waga; j <= sum; ++j)
            dp[j] = max(dp[j], dp[j-przedmioty[i].waga] + przedmioty[i].masa);

    for (int i = 0; i < n; ++i)
        wyn = max(wyn,(m / przedmioty[i].waga) * przedmioty[i].masa + dp[m % przedmioty[i].waga]);

    cout << wyn << '\n';

    return 0;
}
