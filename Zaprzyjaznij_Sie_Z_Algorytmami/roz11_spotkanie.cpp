#include <iostream>
#include <vector>

using namespace std;

long long n = 0;
vector<long long> fib;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    fib.push_back(1);
    fib.push_back(1);
    for (int i = 2; i <= 60; ++i)
        fib.push_back(fib[i-1] + fib[i-2]);

    string spr1 = to_string(fib[n % 60]);
    string spr2 = to_string(fib[(n-2) % 60]);

    cout << ( ((long long)spr1[spr1.size()-1] - 48) + ((long long)spr2[spr2.size()-1] - 48) ) % 10 << endl;

    return 0;
}
