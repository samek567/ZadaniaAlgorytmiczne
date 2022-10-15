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

    for (int i = 0; i < n; ++i)
    {
        cin >> liczby[i];
    }

    for (int i = 0; i < n - 2; ++i)
    {
        int stat[3] {0};
        stat[liczby[i]] = 1;
        stat[liczby[i+1]] = 1;
        stat[liczby[i+2]] = 1;
        if (stat[0] == 1 && stat[1] == 1 && stat[2] == 1)
        {
            cout << "TAK";
            return 0;
        }
    }
    cout << "NIE";
    return 0;
}