#include <iostream>

using namespace std;

int n = 0, wczytana_liczba = 0, max_wartosc = 0, wyn = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        max_wartosc = max(max_wartosc,wczytana_liczba);
        wyn = max(wyn,max_wartosc - wczytana_liczba);
    }
    printf("%d",wyn);

    return 0;
}
