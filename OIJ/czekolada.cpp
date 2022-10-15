#include <iostream>

using namespace std;

int main() {
    long long a = 0;
    long long b = 0;
    long long c = 0;
    long long d = 0;
    long wieksza_liczba = 0;
    long mniejsza_liczba = 0;
    long long iloczyn_zapytania = 0;

    cin >> a >> b >> c >> d;

    iloczyn_zapytania = c * d;

    if ((a * b) < (c * d))
    {
        cout << "NIE";
        return 0;
    }

    if (a > b)
    {
        wieksza_liczba = a;
        mniejsza_liczba = b;
    }
    else
    {
        wieksza_liczba = b;
        mniejsza_liczba = a;
    }

    for (int i = mniejsza_liczba; i > 0; i--)
    {
        if (iloczyn_zapytania % i == 0)
        {
            if (iloczyn_zapytania / i <= wieksza_liczba)
            {
                cout << "TAK";
                return 0;
            }
            else
            {
                cout << "NIE";
                return 0;
            }
        }
    }

    return 0;
}