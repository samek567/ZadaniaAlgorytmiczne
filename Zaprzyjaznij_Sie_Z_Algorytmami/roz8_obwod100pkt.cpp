#include <iostream>

using namespace std;

long long p = 0, min_wyn = 1e18+20;

int main()
{
    // O(sqrt(p))
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> p;

    for (int i = 1; i * i <= p; ++i)
    {
        if (p % i == 0)
        {
            min_wyn = min(min_wyn,2 * i + 2 * p / i);
        }
    }

    printf("%lld", min_wyn);

    return 0;
}
