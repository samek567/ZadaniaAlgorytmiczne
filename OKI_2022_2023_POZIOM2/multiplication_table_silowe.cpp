#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
vector<long long> liczby;

int main()
{
    // O(n^2)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        long long suma = 0;
        for (int j = 0; j < n; ++j)
        {
            suma += i;
            liczby.push_back(suma);
        }
    }

    sort(liczby.begin(),liczby.end());

    cout << liczby[n * n / 2] << "\n";

    return 0;
}
