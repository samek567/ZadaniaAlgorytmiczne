#include <iostream>

using namespace std;

int a = 0, b = 0, c = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;

    cout << min(a,b+c) << '\n';

    return 0;
}