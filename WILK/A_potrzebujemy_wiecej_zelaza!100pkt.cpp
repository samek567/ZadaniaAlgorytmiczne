#include <iostream>

using namespace std;
typedef long long ll;

ll n = 0, m = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    cout << min(m*2/3, n) << '\n';

    return 0;
}