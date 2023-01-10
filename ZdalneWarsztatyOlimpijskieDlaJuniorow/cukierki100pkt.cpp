#include <iostream>

using namespace std;

inline int ile_dzielnikow(int x)
{
    if (x == 1)
        return 1;
    int wynn = 0;
    for (int i = 1; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            wynn++;
            if (x / i != i)
                wynn++;
        }
    }
    return wynn;
}

int n = 0, wczytana_liczba = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        printf("%d\n", ile_dzielnikow(wczytana_liczba));
    }
    return 0;
}