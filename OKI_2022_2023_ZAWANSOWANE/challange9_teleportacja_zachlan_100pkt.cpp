#include <iostream>

using namespace std;

long long n = 0, sum = 0, wyn = 0, iloczyn = 1, ile_brakuje = 0;

int main()
{
    // Zachlan
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    while(sum+iloczyn <= n)
    {
        sum += iloczyn;
        iloczyn *= 2;
        wyn++;
    }
    iloczyn /= 2;
    ile_brakuje = n-sum;

    while (ile_brakuje > 0)
    {
        while(ile_brakuje >= iloczyn)
        {
            ile_brakuje -= iloczyn;
            wyn++;
        }
        iloczyn /= 2;
    }

    cout << wyn << '\n';

    return 0;
}