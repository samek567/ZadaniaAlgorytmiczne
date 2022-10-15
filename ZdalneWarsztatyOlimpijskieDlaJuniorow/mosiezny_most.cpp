#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int opcja_1 = 0;
    int opcja_2 = 0;
    int opcja_3 = 0;

    cin >> n;

    int filary[n];
    int k[n]; // Tablica wynikow - dynamik

    for (int i = 0; i < n; ++i)
    {
        cin >> filary[i];
    }

    if (n == 1)
    {
        cout << filary[0];
        return 0;
    }
    else if (n == 2)
    {
        cout << (filary[0]+filary[1]);
        return 0;
    }

    k[0] = filary[0];
    k[1] = filary[0] + filary[1];

    for (int i = 2; i <= n; ++i)
    {
        opcja_1 = k[i-1];
        opcja_2 = filary[i] + filary[i-1];
        if (i-3 >= 0)
        {
            opcja_2 += k[i-3];
        }
        opcja_3 = filary[i] + k[i-2];
        k[i] = max(opcja_1,opcja_2);
        k[i] = max(k[i],opcja_3);
    }

    /*
    for (auto i : k)
    {
        cout << "Koszty: " << i << endl;
    }
    */

    cout << k[n-1];
    return 0;
}