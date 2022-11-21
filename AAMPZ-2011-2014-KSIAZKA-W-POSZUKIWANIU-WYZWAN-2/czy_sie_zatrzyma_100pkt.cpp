#include <iostream>

using namespace std;
long long n = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (long long i = 1; i <= n; i+=0)
    {
        if (i == n)
        {
            cout << "TAK" << '\n';
            return 0;
        }
        i *= 2;
    }

    cout << "NIE" << '\n';

    return 0;
}
