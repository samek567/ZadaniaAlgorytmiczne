#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll n = 0;
vector<bool> sito;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    sito.assign(n+1,false);
    for (ll i = 2; i <= n; ++i)
    {
        if (sito[i] == false)
            printf("%lld ",i);
        for (ll j = i * i; j <= n; j += i)
            sito[j] = true;
    }
    return 0;
}
