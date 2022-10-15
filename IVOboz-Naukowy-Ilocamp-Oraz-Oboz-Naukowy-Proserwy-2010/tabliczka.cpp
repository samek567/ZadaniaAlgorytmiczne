#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a = 0;
    long long b = 0;

    cin >> a >> b;

    a % 2 == 0 || b % 2 == 0 ? cout << "0" : cout << min(a,b);
    return 0;
}