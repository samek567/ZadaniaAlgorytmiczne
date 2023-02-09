#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, wczytana_liczba = 0, suma = 0;
vector<int> liczby;
vector<int> dzielniki;
vector<int> wyn;

vector<int> szukaj_dzielnikow(int x)
{
    vector<int> wyn;
    for (int i = 1; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            wyn.push_back(i);
            if (i != x / i)
                wyn.push_back(x / i);
        }
    }
    return wyn;
}

inline bool czy_pasuje(int ile_pot) // Czy da sie podzielic na x czesci.
{
    int ile_potrzeba = ile_pot, ile_mamy = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ile_mamy + liczby[i] > ile_potrzeba)
            return false;
        else if (ile_mamy + liczby[i] == ile_potrzeba)
            ile_mamy = 0;
        else
            ile_mamy += liczby[i];
    }
    return true;
}

int main()
{
    // O(N * sqrt(N))
    // Ograniczamy liczbe kandydatow do pierwiastka, korzystajac z tego, ze zastanawiamy sie czy mozemy podzielic na x osob,
    // to x musi byc podzielne przez sume.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        suma += wczytana_liczba;
    }
    vector<int> dzielniki = szukaj_dzielnikow(suma);
    for (int i = 0; i < dzielniki.size(); ++i)
        if(czy_pasuje(suma / dzielniki[i]) == true)
            wyn.push_back(suma / dzielniki[i]);
    sort(wyn.begin(),wyn.end());
    for (int i = 0; i < wyn.size(); ++i)
        cout << wyn[i] << ' ';

    return 0;
}