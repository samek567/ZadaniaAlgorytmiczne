#include <iostream>

using namespace std;

int n = 0, w = 0, wczytana_liczba = 0, suma = 0, wyn = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        suma += wczytana_liczba;
        if (suma >= w)
        {
            wyn++;
            suma = 0;
        }
    }

    printf("%d",wyn);

    return 0;
}
