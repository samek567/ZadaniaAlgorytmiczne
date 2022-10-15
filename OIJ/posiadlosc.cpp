#include <iostream>

using namespace std;

unsigned long long suma_cyfr (unsigned long long liczba)
{
    unsigned long long suma = 0;
    while (liczba != 0)
    {
        suma += liczba % 10;
        liczba = liczba / 10;
    }
    return suma;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long a = 0;
    unsigned long long b = 0;
    unsigned long long szukana = 0;
    unsigned long long sprawdzana = 1;
    cin >> a >> b;

    if (a == b)
    {
        cout << suma_cyfr(a);
        return 0;
    }

    while (a / sprawdzana != b / sprawdzana)
    {
        sprawdzana *= 10;
    }

    sprawdzana /= 10;

    //cout << sprawdzana << endl;
    szukana = b / sprawdzana;

    szukana = szukana * sprawdzana;
    szukana -= 1;

    if (suma_cyfr(b) > suma_cyfr(szukana))
    {
        cout << suma_cyfr(b);
    }
    else
    {
        cout << suma_cyfr(szukana);
    }

    return 0;
}