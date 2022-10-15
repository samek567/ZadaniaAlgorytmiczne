#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct Liczba
{
    int identyfikator;
    int wartosc;
    bool operator<(const Liczba& o) const
    {
        if (wartosc != o.wartosc)
        {
            return wartosc < o.wartosc;
        }
        else
        {
            return identyfikator < o.identyfikator;
        }
    }
    bool operator==(const Liczba& o) const
    {
        return identyfikator == o.identyfikator;
    }
};

set<Liczba> liczby;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int aktualna_liczba = 0;
    int b = 0;
    int e = 0;
    int u = 1; // liczba usuwanych
    int suma = 0;

    cin >> n;


    cin >> aktualna_liczba;
    e += aktualna_liczba + 1;
    suma += aktualna_liczba + 1;
    //cout << "e: " << e << endl;

    while(e<n)
    {
        for (int i = b+1; i <= e; i++)
        {
            cin >> aktualna_liczba;
            liczby.insert({i,aktualna_liczba});
            //cout << "dodaje: " << aktualna_liczba << endl;
            b++;
        }
        auto le = liczby.end();
        le--;
        auto al = *le;
        e += al.wartosc + 1;
        suma += al.wartosc + 1;
        //cout << "wartosc: " << al.wartosc << " suma: " << suma << endl;
        liczby.erase(le);
        //cout << "e: " << e << endl;
        u++;
    }

    //cout << "suma: " << suma << " set len: " << liczby.size() << endl;


    while(suma < n)
    {
        if (liczby.size()>0)
        {
            auto le = liczby.end();
            le--;
            auto al = *le;
            suma += al.wartosc + 1;
            //cout << "suma: " << suma << endl;
            liczby.erase(le);
            u++;
        }
    }

    cout << u;

    return 0;
}