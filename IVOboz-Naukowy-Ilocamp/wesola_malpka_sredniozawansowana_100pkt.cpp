#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll z = 0, n = 0, m = 0;

int main()
{
    // O(Z * log(N*M))
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> z;
    while(z--)
    {
        cin >> n >> m;
        cout << n / __gcd(n,m) << '\n';
    }
    return 0;
}