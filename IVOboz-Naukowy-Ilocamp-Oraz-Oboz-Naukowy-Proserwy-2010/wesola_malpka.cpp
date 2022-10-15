#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long z = 0;
    long long n = 0;
    long long d = 0;

    cin >> z;

    for (long long i = 0; i < z; i++)
    {
        cin >> n >> d;
        cout << n / (__gcd(n,d)) << endl;
    }
    return 0;
}