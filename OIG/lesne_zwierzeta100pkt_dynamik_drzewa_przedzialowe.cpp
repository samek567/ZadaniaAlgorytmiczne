#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, m = 0, c = 0, base = (1 << 20), rozmiar_drzewa = base * 2, a = 0, b = 0, cena = 0;
ll wyn = 0;
vector<ll> dp;
vector<ll> drzewo_przedzialowe;
vector<ll> sumy_poczatki;

inline void update (int l, int p, int val)
{
    l = l + base - 1, p = p + base + 1;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            drzewo_przedzialowe[l+1] += val;
        if (p % 2 == 1)
            drzewo_przedzialowe[p-1] += val;
        l /= 2;
        p /= 2;
    }
}

inline ll querry(int v)
{
    v += base;
    ll res = 0;
    while(v > 0)
    {
        res += drzewo_przedzialowe[v];
        v /= 2;
    }
    return res;
}

int main()
{
    // dp[i] - max wynik jaki mozna uzyskac, przy kupnie dzialki konczacej sie w i. dp[i] to min z dwoch:
    // zaczynamy klasc nowa dzialke: c - koszty dzialek jakie przechodza przez dany punkt (drzewo przedzialowe)
    // dokladamy do dzialki o koncu w i-1: dp[i-1] + c - dzialki, ktore zaczynaja sie w punkcie i,
    // (dlatego tylko te, bo te co zaczynaja sie wczesniej juz policzylismy)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> c;

    sumy_poczatki.assign(n+1,0);
    dp.assign(n+1,0);
    drzewo_przedzialowe.assign(rozmiar_drzewa,0);

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> cena;
        update(a,b,cena);
        sumy_poczatki[a] += cena;
    }

    dp[1] = c - querry(1);
    wyn = max(wyn, dp[1]);
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = max(c - querry(i), dp[i-1] + c - sumy_poczatki[i]);
        wyn = max(wyn, dp[i]);
    }

    cout << wyn << '\n';

    return 0;
}