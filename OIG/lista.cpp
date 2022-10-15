#include <iostream>

using namespace std;

long long f (long long n, long long k, long long i)
{
    if (i <= k)
    {
        return n - k + i;
    }
    else
    {
        return i - k;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n = 0;
    long long k = 0;
    long long b = 0;
    long long e = 0;

    cin >> n >> k >> b >> e;
    if (e <= k || b >= k+1)
    {
        long long wynik = (f(n, k, b) + f(n, k, e)) * (e - b + 1) / 2;
        cout << wynik;
        return 0;
    }
    else
    {
        //cout << "s1: " << (f(n, k, b) + f(n, k, k)) * (k - b) / 2 << endl;
        long long wynik = ((f(n, k, b) + f(n, k, k)) * (k - b + 1) / 2) + ((f(n, k, k+1) + f(n, k, e)) * (e - k - 1 + 1) / 2);
        cout << wynik;
        return 0;
    }

    return 0;
}