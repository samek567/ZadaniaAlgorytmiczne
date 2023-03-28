#include <iostream>

using namespace std;
typedef long long ll;

int t = 0, a = 0, b = 0;
ll wyn = 0;

int main()
{
    // O(T)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        wyn = (ll)a / (ll)2 * (ll)b;
        if (a % 2 == 1)
        {
            if (b % 2 == 0)
                wyn += b / 2;
            else
                wyn += b / 2 + 1;
        }
        cout << wyn << '\n';
    }

    return 0;
}