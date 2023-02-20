#include <iostream>

using namespace std;

int n = 0;

int main()
{
    // Wiemy, ze dla n >= 3, liczba n-1 nie jest jej dzielnikiem, a pierwszy jej niedzielnik mozemy wyszukac normalnie,
    // lub w czasie O(sqrt(N)) znalezc wszystkie dzielniki n, i latwo sprawdzic pierwsza liczbe, ktora nie jest jej dzielnikiem.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 2; i < n; ++i)
    {
        if (n % i != 0)
        {
            cout << i << ' ';
            break;
        }
    }
    cout << n-1 << '\n';

    return 0;
}