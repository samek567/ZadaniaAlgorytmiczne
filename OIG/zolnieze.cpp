#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n = 0;
    unsigned long long wczytany_zolnierz = 0;
    vector<unsigned long long> zolnierze;
    vector<unsigned long long> grupy;
    vector<char> znaki;
    unsigned long long licznik = 1;
    unsigned long long wynik = 1;
    bool czy_bylo_wieksze = false;
    unsigned long long wynik_do_sprawdzania = 1;
    string ciag;
    string wynik_napis;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_zolnierz;
        zolnierze.push_back(wczytany_zolnierz);
    }

    sort (zolnierze.begin(),zolnierze.end());

    for (int i = 0; i < n-1; ++i)
    {
        if (zolnierze[i] != zolnierze[i+1])
        {
            grupy.push_back(licznik);
            licznik = 1;
        }
        else
        {
            licznik++;
        }
    }
    grupy.push_back(licznik);

    for (int i = 0; i < grupy.size(); ++i)
    {
        for (int j = 1; j <= grupy[i]; ++j)
        {
            wynik *= j;
            if (czy_bylo_wieksze == false)
            {
                wynik_do_sprawdzania *= j;
                if (wynik_do_sprawdzania >= 1000)
                {
                    czy_bylo_wieksze = true;
                }
            }
            wynik = wynik % 10000;
        }
    }

    if (grupy.size() != 1)
    {
        wynik *= 2;
        wynik = wynik % 10000;
        if (czy_bylo_wieksze == false)
        {
            wynik_do_sprawdzania *= 2;
            if (wynik_do_sprawdzania >= 1000)
            {
                czy_bylo_wieksze = true;
            }
        }
    }

    if (czy_bylo_wieksze == true)
    {
        ciag = to_string(wynik);
        if (ciag.size() < 4)
        {
            for (int i = 0; i < 4-ciag.size(); ++i)
            {
                cout << "0";
            }
            cout << wynik;
        }
        else
        {
            cout << wynik;
        }
    }

    else
    {
        cout << wynik;
    }

    return 0;
}