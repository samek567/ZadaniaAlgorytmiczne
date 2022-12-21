#include <iostream>
#include <vector>

using namespace std;

long long z = 0, s = 0, p = 0, iloczyn = 1, mod = 1073741824; // mod = 2^30, bo max p = 30.
vector<long long> fib;
vector<long long> pow_vect;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fib.push_back(1);
    fib.push_back(2);
    for (int i = 2; i <= 1e6+5; ++i)
    {
        fib.push_back((fib[i-1] + fib[i-2]) % mod);
    }

    for (int i = 0; i <= 30; ++i)
    {
        pow_vect.push_back(iloczyn);
        iloczyn *= 2;
    }

    cin >> z;
    for (int i = 0; i < z; ++i)
    {
        cin >> s >> p;
        printf("%lld\n",fib[s-1] % pow_vect[p]);
    }
    return 0;
}
