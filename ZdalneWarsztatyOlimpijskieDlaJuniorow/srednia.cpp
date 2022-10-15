#include <iostream>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    long long wczytany_klocek = 0;
    long double k = 0;

    cin >> n >> k;
    long long klocki[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_klocek;
        klocki[i] = wczytany_klocek;
    }

    long double min_roznica = 100000000000;
    long double srednia = 0;
    long long suma = 0;
    int poczatek = 0;
    int koniec = 0;
    int poczatek_wynik = 0;
    int koniec_wynik = 0;

    for (int i = 0; i < n; ++i)
    {
        if (abs(k - klocki[i]) < min_roznica)
        {
            min_roznica = abs(k - klocki[i]);
            poczatek = i;
            koniec = i;
        }
    }

    poczatek_wynik = poczatek;
    koniec_wynik = koniec;
    srednia = klocki[poczatek];
    suma = klocki[poczatek];

    while (poczatek > -1 && koniec < n)
    {
        if (srednia == k)
        {
            poczatek_wynik = poczatek;
            koniec_wynik = koniec;
            break;
        }

        else if (srednia > k)
        {
            poczatek--;
            suma += klocki[poczatek];
        }
        else if (srednia < k)
        {
            koniec++;
            suma += klocki[koniec];
        }
        srednia = (long double)suma / (long double)(koniec-poczatek+1);
        if (abs(k-srednia) < min_roznica)
        {
            min_roznica = abs(k-srednia);
            poczatek_wynik = poczatek;
            koniec_wynik = koniec;
            if (poczatek == -1)
            {
                poczatek_wynik++;
            }
            if (koniec == n)
            {
                koniec_wynik--;
            }
        }
    }

    cout << poczatek_wynik+1 << " " << koniec_wynik+1;
    return 0;
}