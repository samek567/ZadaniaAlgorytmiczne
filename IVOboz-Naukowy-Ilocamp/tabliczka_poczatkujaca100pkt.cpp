#include <iostream>

using namespace std;
typedef long long ll;

ll a = 0, b = 0, wyn1 = 0, wyn2 = 0;

int main()
{
    // O(1), sprawdzamy gdzie lepiej nam przeciac tabliczke, i bierzemy ta opcje, gdzie roznica jest minimalna, tego szukamy w zadaniu.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    wyn1 = abs((a/2 * b) - (a * b - (a/2 * b)));
    wyn2 = abs((b/2 * a) - (a * b - (b/2 * a)));

    cout << min(wyn1,wyn2);

    return 0;
}