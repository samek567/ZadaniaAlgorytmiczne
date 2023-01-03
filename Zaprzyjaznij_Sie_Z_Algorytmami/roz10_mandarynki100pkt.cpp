#include <iostream>
#include <algorithm>

using namespace std;

long long n = 0, nwd = 0;

int main()
{
    // O(log n) Korzystamy z obserwacji, ze nwd kolejnych dwoch liczb naturalnych to zawsze jeden,
    // skoro NWW(a,b) = a * b / NWD(a,b), to chcemy dzielic przez jak najmniejsza liczbe, czyli jeden zawsze pasi,
    // oraz wtedy n * (n-1) jest drugie najwieksze mozliwe po n * n.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n <= 2)
    {
        nwd = __gcd(n,n);
        printf("%lld",nwd + n * n / nwd);
    }
    else
    {
        nwd = __gcd(n,n-1);
        printf("%lld",nwd + n * (n-1) / nwd);
    }
    return 0;
}
