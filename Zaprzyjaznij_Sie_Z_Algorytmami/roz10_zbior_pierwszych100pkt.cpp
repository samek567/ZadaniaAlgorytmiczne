#include <iostream>
#include <algorithm>

using namespace std;

int z = 0, f = 0, s = 0;

inline bool czy_nalezy(int a, int b)
{
    while(__gcd(a,b) != 1)
        a /= __gcd(a,b);
    if (a == 1)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> z;
    while(z--)
    {
        cin >> f >> s;
        if (czy_nalezy(f,s) == true)
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }

    return 0;
}