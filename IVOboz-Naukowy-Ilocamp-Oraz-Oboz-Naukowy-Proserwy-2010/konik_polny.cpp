#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x = 0;
    int s = 0;
    int trasa = 0;
    int wynik = 0;

    cin >> x >> s;

    while (s != 1 && trasa < x)
    {
        wynik++;
        trasa += s;
        s /= 2;
    }
    trasa < x ? wynik += x - trasa : trasa;

    cout << wynik;
    return 0;
}