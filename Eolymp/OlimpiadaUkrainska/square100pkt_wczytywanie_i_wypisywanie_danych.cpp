#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;

ld n = 0, sqrt_2 = sqrt(2);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    cout << fixed << setprecision(30) << n / sqrt_2 << '\n';

    return 0;
}