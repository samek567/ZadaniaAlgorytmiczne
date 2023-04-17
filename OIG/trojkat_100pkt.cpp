#include <iostream>

using namespace std;
typedef long long ll;

ll x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    x2 -= x1, x3 -= x1, y2 -= y1, y3 -= y1;

    if (x2 * y3 - x3 * y2 < 0)
        cout << "ZGODNIE" << '\n';
    else
        cout << "PRZECIWNIE" << '\n';

    return 0;
}