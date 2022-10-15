#include <iostream>
#include <algorithm>

using namespace std;

long long znajdz_p(long long a, long long skok)
{
    if (skok == 1 || (a-1) % skok == 0)
    {
        return a;
    }
    if (a % skok == 0)
    {
        return a+1;
    }

    long long mod = a % skok;
    if (mod < 0) // Musi byc bo modula w c++ daje wartosci ujemne dla a<0.
    {
        mod += skok;
    }
    long long wyn = a - mod + skok + 1;
    return wyn;
}

long long znajdz_k(long long a, long long skok)
{
    if (skok == 1)
    {
        return a;
    }
    if (a % skok == 0)
    {
        return a - skok + 1;
    }
    long long mod = a % skok;
    if (mod < 0) // Musi byc bo modula w c++ daje wartosci ujemne dla a<0.
    {
        mod += skok;
    }
    long long wyn = a - mod + 1;
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n = 0;
    long long m = 0;
    long long x_1 = 0;
    long long y_1 = 0;
    long long x_2 = 0;
    long long y_2 = 0;
    long long wczytana = 0;

    long long gcd_x = 0;
    long long gcd_y = 0;

    cin >> n >> m >> x_1 >> y_1 >> x_2 >> y_2;

    cin >> gcd_x;
    for (int i = 0; i < n-1; ++i)
    {
        cin >> wczytana;
        gcd_x = __gcd(gcd_x,wczytana);
    }

    cin >> gcd_y;
    for (int i = 0; i < m-1; ++i)
    {
        cin >> wczytana;
        gcd_y = __gcd(gcd_y,wczytana);
    }

    long long wyn_x = 0;
    long long wyn_y = 0;

    long long p_x = znajdz_p(x_1,gcd_x);
    long long k_x = znajdz_k(x_2,gcd_x);
    if (k_x < p_x)
    {
        cout << "0";
        return 0;
    }
    wyn_x = (k_x - p_x) / gcd_x + 1;


    long long p_y = znajdz_p(y_1,gcd_y);
    long long k_y = znajdz_k(y_2,gcd_y);
    if (k_y < p_y)
    {
        cout << "0";
        return 0;
    }
    wyn_y = (k_y - p_y) / gcd_y + 1;

    cout << wyn_x * wyn_y;
    return 0;
}