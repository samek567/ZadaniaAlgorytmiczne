#include <iostream>

using namespace std;

int d = 0, a = 0, b = 0;

int main()
{
    // O(1), zauwazamy, ze mozemy odleglosc zmodulowac przez a+b
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> d >> a >> b;
    d = d % (a+b);
    if (d < a)
        cout << "1" << '\n';
    else
        cout << "0" << '\n';

    return 0;
}