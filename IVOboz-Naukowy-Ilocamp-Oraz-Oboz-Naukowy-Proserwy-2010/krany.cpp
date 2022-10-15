#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int w = 0;
    int suma = 0;
    int wczytana_liczba = 0;
    int licznik = 0;
    vector<int> liczby;

    cin >> n >> w;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba <= 0)
        {
            continue;
        }
        suma += wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    sort(liczby.begin(),liczby.end());

    if (suma >= w * liczby.size())
    {
        cout << "0";
        return 0;
    }

    for (int i = 0; i < liczby.size()-1; ++i)
    {
        suma -= liczby[i];
        licznik++;
        if (suma >= w * (liczby.size()-licznik))
        {
            cout << licznik;
            return 0;
        }
    }

    cout << "NIE";

    return 0;
}