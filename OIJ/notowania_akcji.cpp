#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int q = 0;
    long long aktualna_liczba = 0;
    long long licznik = 0;
    long long k = 0;
    vector<long long> liczby;
    vector<long long> spadki;
    vector<long long> indeksy_spadkow;

    cin >> n;

    int spadki_total = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        cin >> aktualna_liczba;
        liczby.push_back(aktualna_liczba);
        if (i == 0 || aktualna_liczba > liczby[i-1])
        {
            spadki.push_back(spadki_total);
        }
        else
        {
            spadki_total++;
            spadki.push_back(spadki_total);
            indeksy_spadkow.push_back(i);
        }
    }

    cin >> q;


    for (int i = 0; i < q; i++)
    {
        licznik = 0;
        cin >> k;

        if (k == 1)
        {
            cout << n << endl;
            continue;
        }

        if (indeksy_spadkow.size() == 0)
        {
            cout << (n - k + 1) << endl;
            continue;
        }

        if (k == n)
        {
            if (indeksy_spadkow.size() == 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
            continue;
        }

        if (indeksy_spadkow.size() < n / 10)
        {
            int spadki_indeks = 0;
            int spadki_indeks_lewy = 0;

            for (int j = 0; j<indeksy_spadkow.size(); j++)
            {
                if (indeksy_spadkow[j] - spadki_indeks_lewy - k + 1 > 0)
                {
                    licznik += (indeksy_spadkow[j] - spadki_indeks_lewy - k + 1);
                }
                spadki_indeks_lewy = indeksy_spadkow[j];
            }
            if (n - spadki_indeks_lewy - k + 1 > 0)
            {
                licznik += (n - spadki_indeks_lewy - k + 1);
            }

        }
        else
        {
            for (unsigned long long j = 0; j < liczby.size() - k + 1; )
            {

                unsigned long long roznica = spadki[j+k-1] - spadki[j];
                if (roznica == 0)
                {
                    licznik++;
                    j += roznica + 1;
                }
                else
                {
                    if (j+k-1+roznica < n)
                    {
                        roznica += spadki[j+k-1+roznica] - spadki[j+k-1];
                    }
                    j += roznica;
                }
            }

        }

        cout << licznik << endl;
    }

    return 0;
}