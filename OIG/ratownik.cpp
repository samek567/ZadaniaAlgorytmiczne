#include <iostream>
#include <cmath>

using namespace std;
long double odleglosc (pair <int,int> a, pair<int,int> b) // Funkcja liczaca odleglosc miedzy dwoma punktami.
{
    return (long double)sqrt((long double)pow(((long double)a.first - (long double)b.first),2) + (long double)pow(((long double)a.second - (long double)b.second),2));
}

int main()
{
    // Przyspieszamy wejscie,wyjscie
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0, k = 0, wyn = 0;
    pair<int,int> ratownik , dziecko; // x1,y1

    cin >> n >> k >> ratownik.first >> ratownik.second;

    for (int i = 0; i < n; ++i)
    {
        // Liczymy odleglosc miedzy kazdymi dwoma punktami (ratownik,i-te dziecko) i jesli odegosc > zasieg ratownika to wyn++ (dziecko nie moze czuc sie bezpiecznie)
        cin >> dziecko.first >> dziecko.second;
        long double odl = odleglosc(ratownik,dziecko);

        if (odl > k)
        {
            wyn++;
        }
    }

    cout << wyn;
    return 0;
    //O(n),bo odleglosc liczymy w O(1) - funkcja odleglosc. A ją wywołujemy jedynie n razy.
}