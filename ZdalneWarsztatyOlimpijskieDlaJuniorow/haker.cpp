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
    long long aktualna_liczba = 0;
    vector<long long> przelewy;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aktualna_liczba;
        if (aktualna_liczba != 0)
        {
            przelewy.push_back(aktualna_liczba);
        }
    }

    sort(przelewy.begin(),przelewy.end());

    for (int i = 0; i < przelewy.size(); i++)
    {
        long long szukana_liczba = 2 * przelewy[i];
        long long poczatek = i;
        long long koniec = przelewy.size();
        int srodek = 0;

        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;

            if (przelewy[srodek] >= szukana_liczba)
            {
                koniec = srodek;
            }
            else
            {
                poczatek = srodek;
            }
        }

        if (przelewy[koniec] == szukana_liczba)
        {
            cout << "TAK";
            return 0;
        }
    }
    cout << "NIE";
    return 0;
}