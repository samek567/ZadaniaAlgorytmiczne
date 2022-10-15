#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n = 0;
    long long suma = 0;
    long long wynik = 0;
    string ciag;
    string ciag_tworzony;
    bool czy_jest_pierwsze = true;
    cin >> n >> ciag;

    for (long long i = 0; i < n; i++)
    {
        if (ciag[i] == '0' || ciag[i] == '1' || ciag[i] == '2' || ciag[i] == '3' || ciag[i] == '4' || ciag[i] == '5' || ciag[i] == '6' || ciag[i] == '7' || ciag[i] == '8' || ciag[i] == '9')
        {
            if (czy_jest_pierwsze == true && ciag[i] == 0)
            {
            }
            else
            {
                ciag_tworzony += ciag[i];
            }
        }
        else
        {
            czy_jest_pierwsze = true;
            if (ciag_tworzony.size() > 0)
            {
                wynik = stoll(ciag_tworzony);
                suma += wynik;
            }
            ciag_tworzony = "";
        }
    }
    if (ciag_tworzony.size() > 0)
    {
        wynik = stoll(ciag_tworzony);
        suma += wynik;
    }

    cout << suma;
    return 0;
}