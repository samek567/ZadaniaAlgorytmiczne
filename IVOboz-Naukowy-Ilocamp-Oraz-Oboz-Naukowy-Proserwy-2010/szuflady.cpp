#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;

    cin >> n;
    int liczby[n];
    int licznik = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> liczby[i];
    }

    for (int i = n-1; i > 0; --i)
    {
        if (liczby[i-1] >= liczby[i])
        {
            liczby[i-1] = liczby[i]-1;
            licznik++;
        }
    }
    if (liczby[0] < 1)
    {
        cout << "-1";
    }
    else
    {
        cout << licznik;
    }

    return 0;
}