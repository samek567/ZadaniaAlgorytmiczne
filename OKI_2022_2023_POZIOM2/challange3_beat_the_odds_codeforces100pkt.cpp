#include <iostream>
#include <vector>

using namespace std;

int t = 0, n = 0, wczytana_liczba = 0, licznik_parzystych = 0, licznik_nieparzystych = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        licznik_parzystych = 0;
        licznik_nieparzystych = 0;
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytana_liczba;
            if (wczytana_liczba % 2 == 0)
                licznik_parzystych++;
            else
                licznik_nieparzystych++;
        }
        printf("%d\n",min(licznik_parzystych,licznik_nieparzystych));
    }
    return 0;
}