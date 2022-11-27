#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, dlugosc_zapytania = 0, wczytana_liczba = 0, idx_ostatniego = -1;
vector<int> elementy[1000005];

int binaryy_search ()
{
    // Szukamy idx-u pierwszego elementu > idx_ostatniego.
    int p = -1;
    int k = elementy[wczytana_liczba].size();
    int s = 0;

    while (k-p != 1)
    {
        s = (k+p) / 2;
        if (elementy[wczytana_liczba][s] <= idx_ostatniego)
        {
            p = s;
        }
        else
        {
            k = s;
        }
    }
    if (k == elementy[wczytana_liczba].size())
    {
        return -1;
    }
    else
    {
        return elementy[wczytana_liczba][k];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        elementy[wczytana_liczba].push_back(i);
    }

    cin >> m;

    for (int z = 0; z < m; ++z)
    {
        cin >> dlugosc_zapytania;
        idx_ostatniego = -1;
        bool czy_istnieje = true;
        for (int i = 0; i < dlugosc_zapytania; ++i)
        {
            cin >> wczytana_liczba;
            idx_ostatniego = binaryy_search();
            if (idx_ostatniego == -1)
            {
                czy_istnieje = false;
            }
        }
        if (czy_istnieje == true)
        {
            cout << "TAK" << endl;
        }
        else
        {
            cout << "NIE" << endl;
        }
    }

    return 0;
}