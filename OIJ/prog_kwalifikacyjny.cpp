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
    int z = 0;
    long long aktualna_liczba = 0;
    long long szukana_liczba = 0;
    long long suma = 0;
    vector<long long> liczby;
    vector<long long> sumy_prefiksowe;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> aktualna_liczba;
        liczby.push_back(aktualna_liczba);
    }

    sort(liczby.begin(),liczby.end(),greater<long long>());

    for (int i = 0; i < n; i++)
    {
        suma+= liczby[i];
        sumy_prefiksowe.push_back(suma);
    }

    cin >> z;

    for (int i = 0; i < z; i++)
    {
        cin >> szukana_liczba;

        long long poczatek = -1;
        long long koniec = n;
        long long srodek = 0;

        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (sumy_prefiksowe[srodek] >= szukana_liczba)
            {
                koniec = srodek;
            }
            else
            {
                poczatek = srodek;
            }
        }
        printf("%lld \n",koniec+1); // koniec+1, bo idx vectora w c++ sa od 0 a nie od 1.
    }
    return 0;
}