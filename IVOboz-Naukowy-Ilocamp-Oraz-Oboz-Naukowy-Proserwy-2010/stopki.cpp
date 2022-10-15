#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long x = 0;
    long long k = 0;
    long long a = 0;

    cin >> x >> k >> a;

    if (x % (k+a) == 0)
    {
        cout << "1";
    }
    else
    {
        if (x % (k+a) < k)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }

    return 0;
}