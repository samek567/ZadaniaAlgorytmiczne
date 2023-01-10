#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int n = 0;
ll a = 0, b = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        printf("%lld\n",a * b / __gcd(a,b));
    }
    return 0;
}