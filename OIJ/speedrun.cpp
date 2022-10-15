#include <iostream>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int aktualna_liczba = 0;
    int stopien_cyklu = 0;
    int j = 0;
    long long suma = 0;
    long long t_suma = LLONG_MAX;
    bool czy_pierwszy_raz;
    bool czy_pierwszy_raz_k;
    bool czy_koniec_cyklu;

    cin >> n;

    int liczby[n+1];
    int cykle[n+1] = {0};

    for (int i = 1; i <= n; ++i)
    {
        cin >> aktualna_liczba;
        liczby[i] = aktualna_liczba;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (cykle[i] != 0)
        {
            continue;
        }
        stopien_cyklu++;
        j = i;
        suma = 0;
        czy_pierwszy_raz = true;
        czy_pierwszy_raz_k = true;
        czy_koniec_cyklu = false;

        while(true)
        {
            if (cykle[j] == 0)
            {
                cykle[j] = stopien_cyklu;
            }
            else if (cykle[j] == stopien_cyklu) // Znalezlismy cykl! Teraz tylko sumujemy cykl.
            {
                for (int k = j; liczby[k] != liczby[j] || czy_pierwszy_raz_k == true;) // Tu jest blad
                {
                    czy_pierwszy_raz_k = false;
                    suma += liczby[k];
                    k = liczby[k];
                }
                if (suma < t_suma)
                {
                    t_suma = suma;
                }
                //cout << "Breakujemy i: " << i << endl;
                //cout << "Suma: " << suma << endl;
                break; // Odtwarzamy droge
            }
            else // Znalezlismy inny cykl, Wiec nie idziemy, bo zawsze bedzie tak duzej.
            {
                break;
            }
            j = liczby[j];
        }
    }

    printf("%lld",t_suma);
    return 0;
}