#include <iostream>
#include <algorithm>

using namespace std;

long long a = 0, b = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    printf("%lld",__gcd(a,b));

    return 0;
}