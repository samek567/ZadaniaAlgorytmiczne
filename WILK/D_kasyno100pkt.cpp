#include <iostream>

using namespace std;
typedef unsigned long long ll;

int t = 0;
ll a = 0, b = 0, ile_uzupelnic = 0, iloczyn_dwojki = 0, iloczyn_trojki = 0, iloczyn = 1;

inline bool czy_pasuje()
{
    while(a > 1)
    {
        if (a % 2 == 0)
            a /= 2;
        else
            break;
    }
    while(a > 2)
    {
        if (a % 3 == 0)
            a /= 3;
        else
            break;
    }
    while(b > 1)
    {
        if (b % 2 == 0)
            b /= 2;
        else
            break;
    }
    while(b > 2)
    {
        if (b % 3 == 0)
            b /= 3;
        else
            break;
    }
    if (a == b)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if (czy_pasuje() == true)
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }
    return 0;
}