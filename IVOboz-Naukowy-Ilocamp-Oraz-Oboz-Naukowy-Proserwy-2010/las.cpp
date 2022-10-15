#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int wczytana_grubosc = 0;
    int wczytana_ID = 0;
    bool stat[1000001] {false};
    int wynik = 0;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_grubosc >> wczytana_ID;
        stat[wczytana_ID] = true;
    }

    for (int i = 1; i <= 1000000; ++i)
    {
        if (stat[i])
        {
            wynik++;
        }
    }

    cout << wynik;
    return 0;
}