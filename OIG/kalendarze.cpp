#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long liczba_miesiecy_arbuzani = 0;
    long long liczba_miesiecy_bananitow = 0;
    long long aktualna_wartosc = 0;
    long long liczba_zapytan = 0;
    long long zapytanie_dzien = 0;
    long long zapytanie_miesiac = 0;
    char zapytanie_znak;
    vector<long long> sumy_prefiksowe_arbuzanow;
    vector<long long> sumy_prefiksowe_bananitow;
    long long wynik = 0;
    long long suma = 0;
    long long idx = 0;
    long long numer_miesiaca = 0;
    long long numer_dnia = 0;

    cin >> liczba_miesiecy_arbuzani >> liczba_miesiecy_bananitow;

    for (long long i = 0; i < liczba_miesiecy_arbuzani; i++)
    {
        cin >> aktualna_wartosc;
        wynik += aktualna_wartosc;
        sumy_prefiksowe_arbuzanow.push_back(wynik);
    }

    wynik = 0;

    for (long long i = 0; i < liczba_miesiecy_bananitow; i++)
    {
        cin >> aktualna_wartosc;
        wynik += aktualna_wartosc;
        sumy_prefiksowe_bananitow.push_back(wynik);
    }

    /*

    for (long long i = 0; i < liczba_miesiecy_arbuzani; i++)
    {
        cout << sumy_prefiksowe_arbuzanow[i] << " ";
    }

    cout << endl;

    for (long long i = 0; i < liczba_miesiecy_bananitow; i++)
    {
        cout << sumy_prefiksowe_bananitow[i] << " ";
    }
    cout << endl;

    */

    cin >> liczba_zapytan;

    for (long long i = 0; i < liczba_zapytan; i++)
    {
        cin >> zapytanie_dzien >> zapytanie_miesiac >> zapytanie_znak;
        if (zapytanie_znak == 'A')
        {
            if (zapytanie_miesiac - 2 == -1)
            {
                suma = zapytanie_dzien;
            }
            else
            {
                suma = sumy_prefiksowe_arbuzanow[zapytanie_miesiac - 2] + zapytanie_dzien;
            }
            //cout << "SUMA: " << suma << endl;

            /*
            auto it = find_if(sumy_prefiksowe_bananitow.begin(),sumy_prefiksowe_bananitow.end(),[suma] (const long long& l)
            {
                return l >= suma;
            });
            if (it != sumy_prefiksowe_bananitow.end())
            {
                idx = it - sumy_prefiksowe_bananitow.begin();
                //cout << idx;
            }
            */

            int start_idx = -1;
            int end_idx = sumy_prefiksowe_bananitow.size();
            while(end_idx-start_idx>1)
            {
                int id = start_idx + (end_idx-start_idx)/2;
                if (sumy_prefiksowe_bananitow[id] >= suma)
                {
                    end_idx = id;
                }
                else
                {
                    start_idx = id;
                }
            }
            idx = end_idx;


            numer_miesiaca = idx + 1;
            if (idx == 0)
            {
                numer_dnia = suma;
            }
            else
            {
                numer_dnia = suma - sumy_prefiksowe_bananitow[idx - 1];
            }
            cout << numer_dnia << " " << numer_miesiaca << endl;
        }
        else
        {
            if (zapytanie_miesiac - 2 == -1)
            {
                suma = zapytanie_dzien;
            }
            else
            {
                suma = sumy_prefiksowe_bananitow[zapytanie_miesiac - 2] + zapytanie_dzien;
            }
            //cout << "SUMA: " << suma << endl;

            /*
            auto it = find_if(sumy_prefiksowe_arbuzanow.begin(),sumy_prefiksowe_arbuzanow.end(),[suma] (const long long& l)
            {
                return l >= suma;
            });

            if (it != sumy_prefiksowe_arbuzanow.end())
            {
                idx = it - sumy_prefiksowe_arbuzanow.begin();
                //cout << idx;
            }
            */

            int start_idx = -1;
            int end_idx = sumy_prefiksowe_arbuzanow.size();
            while(end_idx-start_idx>1)
            {
                int id = start_idx + (end_idx-start_idx)/2;
                if (sumy_prefiksowe_arbuzanow[id] >= suma)
                {
                    end_idx = id;
                }
                else
                {
                    start_idx = id;
                }
            }
            idx = end_idx;


            numer_miesiaca = idx + 1;
            if (idx == 0)
            {
                numer_dnia = suma;
            }
            else
            {
                numer_dnia = suma - sumy_prefiksowe_arbuzanow[idx - 1];
            }

            cout << numer_dnia << " " << numer_miesiaca << endl;
        }
        suma = 0;
        numer_miesiaca = 0;
        idx = 0;
        numer_dnia = 0;
    }

    return 0;
}