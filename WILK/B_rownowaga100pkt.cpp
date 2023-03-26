#include <iostream>

using namespace std;
typedef long long ll;

ll n = 0, a = 0, b = 0, c = 0, suma_a = 0, suma_b = 0, suma_c = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        suma_a += a, suma_b += b, suma_c += c;
    }

    if (suma_a == 0 and suma_b == 0 and suma_c == 0)
        cout << "TAK" << '\n';
    else
        cout << suma_a * (-1) << ' ' << suma_b * (-1) << ' ' << suma_c * (-1) << '\n';

    return 0;
}