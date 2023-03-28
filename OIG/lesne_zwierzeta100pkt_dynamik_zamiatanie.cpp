#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, m = 0, c = 0, a = 0, b = 0, cena = 0;
ll wyn = 0, sum = 0;
vector<ll> dp;
vector<ll> zamiatanie_poczatek;
vector<ll> zamiatanie_koniec;
vector<ll> sumy_poczatki;

int main()
{
    // dp[i] - max wynik jaki mozna uzyskac, przy kupnie dzialki konczacej sie w i. dp[i] to min z dwoch:
    // zaczynamy klasc nowa dzialke: c - koszty dzialek jakie przechodza przez dany punkt (zamiatanie, zmienna sum)
    // dokladamy do dzialki o koncu w i-1: dp[i-1] + c - dzialki, ktore zaczynaja sie w punkcie i,
    // (dlatego tylko te, bo te co zaczynaja sie wczesniej juz policzylismy)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> c;

    sumy_poczatki.assign(n+1,0);
    dp.assign(n+1,0);
    zamiatanie_poczatek.assign(n+1,0);
    zamiatanie_koniec.assign(n+1,0);

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> cena;
        sumy_poczatki[a] += cena;
        zamiatanie_poczatek[a] += cena;
        zamiatanie_koniec[b] += cena;
    }

    sum = zamiatanie_poczatek[1];
    dp[1] = c - sum;
    wyn = max(wyn, dp[1]);
    for (int i = 2; i <= n; ++i)
    {
        sum -= zamiatanie_koniec[i-1];
        sum += zamiatanie_poczatek[i];
        dp[i] = max(c - sum, dp[i-1] + c - zamiatanie_poczatek[i]);
        wyn = max(wyn, dp[i]);
    }

    cout << wyn << '\n';

    return 0;
}