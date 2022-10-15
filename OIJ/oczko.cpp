#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int zamiana (char c)
{
    int wartosc = 0;
    switch (c) {
        case '1':
            wartosc = 1;
            break;
        case '2':
            wartosc = 2;
            break;
        case '3':
            wartosc = 3;
            break;
        case '4':
            wartosc = 4;
            break;
        case '5':
            wartosc = 5;
            break;
        case '6':
            wartosc = 6;
            break;
        case '7':
            wartosc = 7;
            break;
        case '8':
            wartosc = 8;
            break;
        case '9':
            wartosc = 9;
            break;
        case 'T':
            wartosc = 10;
            break;
        case 'J':
            wartosc = 10;
            break;
        case 'Q':
            wartosc = 10;
            break;
        case 'K':
            wartosc = 10;
            break;
        case 'A':
            wartosc = 1;
            break;
        default:
            wartosc = 0;
    }
    return wartosc;
}

int punkty_gracza (string karty)
{
    bool czy_as = false;
    int punkty = 0;
    for (int i = 0; i < karty.size(); i++)
    {
        char c = karty[i];
        if (c == 'A')
        {
            czy_as = true;
        }
        punkty += zamiana(c);
    }
    if (czy_as && punkty + 10 < 22)
    {
        punkty += 10;
    }
    if (punkty > 21)
    {
        punkty = 0;
    }
    return punkty;
}

struct Gracz {
    int numer;
    int punkty;
    bool operator < (const Gracz& gracz) const {
        if (punkty != gracz.punkty)
        {
            return punkty < gracz.punkty;
        }
        else
        {
            return numer > gracz.numer;
        }
    }
    void wyswietl() const {
        cout << "Gracz numer: " << numer << " punkty: " << punkty << endl;
    }
};

void pokaz_graczy(vector<Gracz> gracze)
{
    cout << "Aktualni gracze: " << endl;
    for (int i = 0; i<gracze.size(); i++)
    {
        gracze[i].wyswietl();
    }
}

int main() {

    int liczba_graczy = 0;
    string karty_gracza;
    int suma_punkty_karty;

    vector<Gracz> gracze;

    cin >> liczba_graczy;

    // Wpisywanie kart do wektora karty_graczy.
    for (int i = 0; i<liczba_graczy; i++)
    {
        cin >> karty_gracza;
        suma_punkty_karty = punkty_gracza(karty_gracza);
        gracze.push_back(Gracz{i+1,suma_punkty_karty});
        //cout << "Nowy gracz: " << gracze[i].numer << " karty: " << karty_gracza << " punkty: " << gracze[i].punkty << endl;
    }

    //pokaz_graczy(gracze);

    sort(gracze.begin(), gracze.end());
    reverse(gracze.begin(), gracze.end());

    //pokaz_graczy(gracze);

    int max = 0;
    int liczba_wygranych = 0;
    for (int i = 0; i<gracze.size(); i++)
    {
        if (gracze[i].punkty > 0 && max == 0)
        {
            max = gracze[i].punkty;
        }
        if (max > 0 && gracze[i].punkty == max)
        {
            liczba_wygranych++;
        }
    }
    cout << liczba_wygranych << endl;

    bool wypisalem_wygranego = false;
    for (int i = 0; i<gracze.size(); i++)
    {
        if (max > 0 && gracze[i].punkty == max)
        {
            if (wypisalem_wygranego)
            {
                cout << " ";
            }
            cout << gracze[i].numer;
            //gracze[i].wyswietl();
            wypisalem_wygranego = true;
        }
    }


    return 0;
}