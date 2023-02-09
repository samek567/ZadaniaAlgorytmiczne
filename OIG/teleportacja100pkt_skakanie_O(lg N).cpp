#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll ile_brakuje = 1, pow = 1, wyn = 1;

int main()
{
    // O(log N)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ile_brakuje;
    ile_brakuje--;
    while(true)
    {
        if (pow * 2 <= ile_brakuje)
        {
            pow *= 2;
            wyn++;
            ile_brakuje -= pow;
        }
        else
            break;
    }
    while(ile_brakuje > 0)
    {
        if (ile_brakuje >= pow)
        {
            wyn++;
            ile_brakuje -= pow;
        }
        else
            pow /= 2;
    }
    cout << wyn;
    return 0;
}