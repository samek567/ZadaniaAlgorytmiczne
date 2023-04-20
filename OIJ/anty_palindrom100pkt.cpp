#include <iostream>

using namespace std;
typedef long long ll;

int poczatek = 0;
string ciag;
ll wyn = 0;

int main()
{
    // O(N), korzystamy z tego, ze wystarczy sprawdzac czy wystepuje palindom dlugosci 2 lub 3.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag;

    for(int i = 0; i < ciag.size(); ++i)
    {
        if (i >= 1 and ciag[i] == ciag[i-1])
            poczatek = i;
        else if (i >= 2 and ciag[i-2] == ciag[i])
            poczatek = i-1;
        wyn += i - poczatek + 1;
    }

    cout << wyn << '\n';

    return 0;
}
