#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n = 0, d = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    printf("%lld\n",n / __gcd(n,d));

    return 0;
}