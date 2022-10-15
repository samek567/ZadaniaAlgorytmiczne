#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    int liczba = 0;
    string ciag;
    int licznik_spacji = 0;
    int licznik_palindomow = 0;
    int licznik_liczb = 0;
    int licznik_zdan = 0;
    int licznik_slow = 0;
    bool czy_liczba = false;
    bool czy_litera = false;
    string ciag_slowo;
    string ciag_palindrom;
    vector<int> kolejnosc;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> liczba;
        kolejnosc.push_back(liczba);
    }
    getline(cin,ciag);
    getline(cin,ciag);

    for (int i = 0; i < ciag.size(); i++)
    {

        if (ciag[i] == '\t')
        {
            if (ciag_slowo.size() > 0)
            {
                licznik_slow++;
                for (int i = ciag_slowo.size()-1; i >=0; i--)
                {
                    ciag_palindrom += tolower(ciag_slowo[i]);
                }
                if (ciag_slowo == ciag_palindrom)
                {
                    licznik_palindomow++;
                }
                ciag_slowo.clear();
                ciag_palindrom.clear();
            }
        }
        else if (ciag[i] == '0' || ciag[i] == '1' || ciag[i] == '2' || ciag[i] == '3' || ciag[i] == '4' || ciag[i] == '5' || ciag[i] == '6' || ciag[i] == '7' ||
                 ciag[i] == '8' || ciag[i] == '9' || ciag[i] == '.' || ciag[i] == ' ' || ciag[i] == '!' || ciag[i] == '?' || ciag[i] == ',')
        {
            if (ciag_slowo.size() > 0)
            {
                licznik_slow++;
                for (int i = ciag_slowo.size()-1; i >=0; i--)
                {
                    ciag_palindrom += tolower(ciag_slowo[i]);
                }
                if (ciag_slowo == ciag_palindrom)
                {
                    licznik_palindomow++;
                }
                ciag_slowo.clear();
                ciag_palindrom.clear();
            }
        }
        else
        {
            ciag_slowo += tolower(ciag[i]);
        }


        if (ciag[i] == ' ')
        {
            licznik_spacji++;
        }

        if (ciag[i] == '0' || ciag[i] == '1' || ciag[i] == '2' || ciag[i] == '3' || ciag[i] == '4' || ciag[i] == '5' || ciag[i] == '6' || ciag[i] == '7' || ciag[i] == '8' || ciag[i] == '9')
        {
            if (czy_liczba == false)
            {
                licznik_liczb++;
                czy_liczba = true;
            }
        }
        else
        {
            czy_liczba = false;
        }

        if (!( ciag[i] == '\t' || ciag[i] == '0' || ciag[i] == '1' || ciag[i] == '2' || ciag[i] == '3' || ciag[i] == '4' || ciag[i] == '5' || ciag[i] == '6' || ciag[i] == '7' || ciag[i] == '8' || ciag[i] == '9' || ciag[i] == '!' || ciag[i] == '?' || ciag[i] == ',' || ciag[i] == ' '))
        {
            if (ciag[i] == '.')
            {
                if (czy_litera == true)
                {
                    licznik_zdan++;
                }
                czy_litera = false;
            }
            else
            {
                czy_litera = true;
            }
        }
    }

    if (ciag_slowo.size() > 0)
    {
        licznik_slow++;
        for (int i = ciag_slowo.size()-1; i >=0; i--)
        {
            ciag_palindrom += tolower(ciag_slowo[i]);
        }
        if (ciag_slowo == ciag_palindrom)
        {
            licznik_palindomow++;
        }
        ciag_slowo.clear();
        ciag_palindrom.clear();
    }

    for (int i = 0; i < n; i++)
    {
        if (kolejnosc[i] == 1)
        {
            cout << licznik_spacji << " ";
        }
        else if (kolejnosc[i] == 2)
        {
            cout << licznik_liczb << " ";
        }
        else if (kolejnosc[i] == 3)
        {
            cout << licznik_slow << " ";
        }
        else if (kolejnosc[i] == 4)
        {
            cout << licznik_zdan << " ";
        }
        else if (kolejnosc[i] == 5)
        {
            cout << licznik_palindomow << " ";
        }
    }
    return 0;
}