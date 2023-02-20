#include <iostream>

using namespace std;

int d = 0, s = 0, wyn = 0;

int main()
{
    // O(log d)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> d >> s;

    while(true)
    {
        wyn++;
        d -= s;
        s /= 2;
        if (s == 0)
        {
            cout << wyn + d << '\n';
            return 0;
        }

        if (d <= 0)
        {
            cout << wyn << '\n';
            return 0;
        }
    }

    return 0;
}