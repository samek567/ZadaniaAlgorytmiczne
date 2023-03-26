#include <iostream>

using namespace std;

int n = 0, wyn = 0, dod = 1, suma = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    if (n == 2)
    {
        cout << "-1" << '\n';
        return 0;
    }

    while(true)
    {
        suma += dod;
        if (suma > n)
            break;
        dod += 2;
        ++wyn;
    }

    if (n % 2 == 0 and wyn % 2 == 1)
        --wyn;
    else if (n % 2 == 1 and wyn % 2 == 0)
        --wyn;

    cout << wyn << '\n';

    return 0;
}