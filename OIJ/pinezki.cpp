#include <iostream>
#include <string>

using namespace std;

int n = 0;
unsigned long long q = 0;

unsigned long long int potega( int x, int y )
{
    unsigned long long int wynik = 1ULL;
    for (int i=0; i<y; i++) {
        wynik *= x;
    }
    return wynik;
}

string policz_pozycje (unsigned long long p) {

    unsigned long long s = 0;
    unsigned long long aktualna_liczba = 0;
    unsigned long long liczba_pinezek = potega(2,n+1);
    unsigned long long poczatek = 0;
    unsigned long long koniec = potega(3, n);
    unsigned long long pozycja = 0;

    if(p > liczba_pinezek)
    {
        return "NIE";
    }
    else
    {

        for (int i = n; i > 0; i--)
        {
            if (i == 1)
            {
                pozycja = poczatek + (p - s) - 1;
                break;
            }
            else if (p - s > (potega(2,i + 1)) / 2)
            {
                poczatek += (koniec - poczatek) * 2/3;
                s+= potega(2,i);
            }
            else
            {
                koniec -= (koniec - poczatek) * 2/3;
            }
        }
        return to_string(pozycja);
    }
}

int main() {

    cin >> n;
    cin >> q;

    unsigned long long p;

    for (int i = 0; i < q; i++)
    {
        cin >> p;
        cout << policz_pozycje(p) << endl;
    }

    return 0;
}