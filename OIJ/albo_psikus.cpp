#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n = 0;
    long long wartosc = 0;
    long long wynik = 0;
    long long suma = 0;
    long long parz = 1;
    long long nie_parz = 0;
    vector<long long> liczby;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> wartosc;
        liczby.push_back(wartosc);
        // cout << liczby[i] << " ";
    }

    for (int i = 0; i < n; i++)
    {
        suma += liczby[i];
        if (suma % 2 == 0)
        {
            wynik+=parz;
            parz++;
        }
        else
        {
            wynik += nie_parz;
            nie_parz++;
        }
    }

    cout << wynik;

    return 0;
}