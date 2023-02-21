#include <iostream>

using namespace std;

int z = 0, a = 0, b = 0;

int main()
{
    // O(1), korzystamy z obserwacji, ze b = a * k
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> z;
    while(z--)
    {
        cin >> a >> b;
        if (b % a == 0)
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }

    return 0;
}