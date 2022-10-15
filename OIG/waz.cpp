#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pole
{
    int wartosc;
    bool czy_jest;
};

struct pozycja
{
    int y;
    int x;
    string kierunek;
};

long long wysokosc = 0;
long long szerokosc = 0;
long long liczba_ruchow = 0;
char kierunek;
char znak;
vector<char> kierunki_ruchow;
queue<pozycja> droga_weza;
pozycja aktualna_pozycja;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> wysokosc >> szerokosc >> liczba_ruchow >> kierunek;

    pole szachownica[wysokosc][szerokosc];

    for (int i = 0; i < wysokosc; i++)
    {
        for (int j = 0; j < szerokosc; j++)
        {
            cin >> znak;
            if (znak == '.')
            {
                szachownica[i][j] = {0,false};
            }
            else if (znak == 'J')
            {
                szachownica[i][j] = {1,false};
            }
            else if (znak == 'W')
            {
                szachownica[i][j] = {0,true};
                aktualna_pozycja.x = j;
                aktualna_pozycja.y = i;
                droga_weza.push(aktualna_pozycja);
            }
        }
    }

    for (int i = 0; i < liczba_ruchow; i++)
    {
        cin >> znak;
        kierunki_ruchow.push_back(znak);
    }

    if (kierunek == 'N')
    {
        aktualna_pozycja.kierunek = "gora";
    }
    else if (kierunek == 'E')
    {
        aktualna_pozycja.kierunek = "prawo";
    }
    else if (kierunek == 'S')
    {
        aktualna_pozycja.kierunek = "dol";
    }
    else if (kierunek == 'W')
    {
        aktualna_pozycja.kierunek = "lewo";
    }


    for (int i = 0; i < liczba_ruchow; i++)
    {

        //cout << "x: " << aktualna_pozycja.x << "y: " << aktualna_pozycja.y << endl;

        if (aktualna_pozycja.kierunek == "prawo")
        {
            if (kierunki_ruchow[i] == 'N')
            {
                aktualna_pozycja.x++;
            }
            else if (kierunki_ruchow[i] == 'P')
            {
                aktualna_pozycja.y++;
                aktualna_pozycja.kierunek = "dol";
            }
            else // L
            {
                aktualna_pozycja.y--;
                aktualna_pozycja.kierunek = "gora";
            }
        }
        else if (aktualna_pozycja.kierunek == "lewo")
        {
            if (kierunki_ruchow[i] == 'N')
            {
                aktualna_pozycja.x--;
            }
            else if (kierunki_ruchow[i] == 'P')
            {
                aktualna_pozycja.y--;
                aktualna_pozycja.kierunek = "gora";
            }
            else // L
            {
                aktualna_pozycja.y++;
                aktualna_pozycja.kierunek = "dol";
            }
        }
        else if (aktualna_pozycja.kierunek == "gora")
        {
            if (kierunki_ruchow[i] == 'N')
            {
                aktualna_pozycja.y--;
            }
            else if (kierunki_ruchow[i] == 'P')
            {
                aktualna_pozycja.x++;
                aktualna_pozycja.kierunek = "prawo";
            }
            else // L
            {
                aktualna_pozycja.x--;
                aktualna_pozycja.kierunek = "lewo";
            }
        }
        else if (aktualna_pozycja.kierunek == "dol")
        {
            if (kierunki_ruchow[i] == 'N')
            {
                aktualna_pozycja.y++;
            }
            else if (kierunki_ruchow[i] == 'P')
            {
                aktualna_pozycja.x--;
                aktualna_pozycja.kierunek = "lewo";
            }
            else // L
            {
                aktualna_pozycja.x++;
                aktualna_pozycja.kierunek = "prawo";
            }
        }
        //sprawdzamy czy wychodzimy poza plansze
        if (aktualna_pozycja.x < 0 || aktualna_pozycja.x > szerokosc - 1 || aktualna_pozycja.y < 0 || aktualna_pozycja.y > wysokosc - 1)
        {
            cout << i + 1;
            return 0;
        }
        //sprawdzamy czy nie zderzylismy sie ze soba samym
        if (szachownica[aktualna_pozycja.y][aktualna_pozycja.x].czy_jest == true)
        {
            cout << i + 1;
            return 0;
        }
        else
        {
            if (szachownica[aktualna_pozycja.y][aktualna_pozycja.x].wartosc == 1)
            {
                droga_weza.push(aktualna_pozycja);
                szachownica[aktualna_pozycja.y][aktualna_pozycja.x].czy_jest = true;
                szachownica[aktualna_pozycja.y][aktualna_pozycja.x].wartosc = 0;
            }
            else
            {
                droga_weza.push(aktualna_pozycja);
                szachownica[aktualna_pozycja.y][aktualna_pozycja.x].czy_jest = true;
                szachownica[droga_weza.front().y][droga_weza.front().x].czy_jest = false;
                droga_weza.pop();
            }
        }
    }

    cout << "OK";
    return 0;
}