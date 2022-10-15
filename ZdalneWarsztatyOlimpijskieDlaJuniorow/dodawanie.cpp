#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n = 0;
    unsigned long long x = 0;

    cin >> n >> x;

    unsigned long long p = 0;
    unsigned long long k = x/n+1;
    unsigned long long s = 0;
    unsigned long long suma = 0;

    while (k-p != 1)
    {
        s = (p+k) / 2;
        suma = (s+s+n-1) * n / 2;
        if (suma < x)
        {
            p = s;
        }
        else
        {
            k = s;
        }
    }
    unsigned long long pyt_wyn = (k+k+n-1) * n / 2;
    if (pyt_wyn == x)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << k+i << " ";
        }
    }
    else
    {
        cout << "NIE";
    }
    return 0;
}