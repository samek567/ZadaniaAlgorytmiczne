#include <iostream>

using namespace std;

long long x = 0, y = 0, s = 0, wyn = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y >> s;

    wyn = (y-x) / s;
    if ((y-x) % s != 0)
        wyn++;

    printf("%lld",wyn);

    return 0;
}
