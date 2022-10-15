#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long z = 0;
    long long s = 0;
    long long p = 0;
    long long fib[1000001];

    fib[0] = 1;
    fib[1] = 1;
    long long mod = pow(2,30);
    for (int i = 2; i <= 1000000; ++i)
    {
        fib[i] = (fib[i-1] + fib[i-2]) % mod;
    }

    cin >> z;

    for (int i = 0; i < z; ++i)
    {
        cin >> s >> p;
        long long mod = pow(2,p);
        cout << (fib[s] % mod) << endl;
    }
    return 0;
}