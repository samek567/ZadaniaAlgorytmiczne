#include <iostream>
#include <queue>

using namespace std;

struct Skok
{
    int x;
    int y;
};

Skok dodaj (Skok Skok1,Skok Skok2)
{
    return {Skok1.x + Skok2.x,Skok1.y + Skok2.y};
}

void wypisz (int wysokosc,int szerokosc,int* adres)
{
    int* wskazywany = adres;
    for (int i = 0; i < wysokosc; i++)
    {
        for (int j = 0; j < szerokosc; j++)
        {
            cout << *wskazywany << " ";
            wskazywany++;
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int szerokosc = 0;
    int wysokosc = 0;
    char wartosc_znaku;
    queue<Skok> skoki;

    cin >> wysokosc >> szerokosc;

    int szachownica [wysokosc][szerokosc];
    Skok przypadki[8];
    przypadki[0] = {2,1};
    przypadki[1] = {2,-1};
    przypadki[2] = {-2,1};
    przypadki[3] = {-2,-1};
    przypadki[4] = {1,2};
    przypadki[5] = {1,-2};
    przypadki[6] = {-1,2};
    przypadki[7] = {-1,-2};

    Skok aktualne_pole;

    for (int i = 0; i < wysokosc; i++)
    {
        for (int j = 0; j < szerokosc; j++)
        {
            cin >> wartosc_znaku;
            if (wartosc_znaku == '.')
            {
                szachownica[i][j] = 0;
            }
            else if (wartosc_znaku == 'x')
            {
                szachownica[i][j] = -1;
            }
            else if (wartosc_znaku == 'z')
            {
                szachownica[i][j] = 0;
                skoki.push({j,i});
            }
            else if (wartosc_znaku == 'n')
            {
                szachownica[i][j] = -3;
            }
        }
    }

    //wypisz(wysokosc,szerokosc,&szachownica[0][0]);
    //cout << endl;

    while (true)
    {
        //cout << skoki.size() << endl;
        //wypisz(wysokosc,szerokosc,&szachownica[0][0]);
        //cout << endl;
        for (int i = 0; i < 8; i++)
        {
            aktualne_pole = dodaj(przypadki[i],skoki.front());
            if (aktualne_pole.x < szerokosc && aktualne_pole.y < wysokosc && aktualne_pole.x >= 0 && aktualne_pole.y >= 0)
            {
                if (szachownica[aktualne_pole.y][aktualne_pole.x] != -1)
                {
                    if (szachownica[aktualne_pole.y][aktualne_pole.x] == -3)
                    {
                        cout << szachownica[skoki.front().y][skoki.front().x] + 1;
                        return 0;
                    }
                    if (szachownica[aktualne_pole.y][aktualne_pole.x] == 0)
                    {
                        szachownica[aktualne_pole.y][aktualne_pole.x]+= szachownica[skoki.front().y][skoki.front().x] + 1;
                        skoki.push(aktualne_pole);
                        //cout << "Dodajemy: " << aktualne_pole.x << " " << aktualne_pole.y << endl;
                    }
                }
            }
        }
        skoki.pop();
        if (skoki.empty())
        {
            cout << "NIE";
            return 0;
        }
    }
    return 0;
}