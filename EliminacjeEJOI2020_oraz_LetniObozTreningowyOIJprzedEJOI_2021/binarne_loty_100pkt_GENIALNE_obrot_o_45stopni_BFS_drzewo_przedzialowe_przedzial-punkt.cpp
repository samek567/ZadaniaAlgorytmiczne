#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element_kolejki
{
    int wierzcholek;
    int wartosc;
};

int h = 0, w = 0, n = 0, y_i = 0, x_i = 0, y = 0, x = 0, base = (1 << 24), rozmiar_drzewa = (1 << 25), x1 = 0, x2 = 0;
vector<bool> czy_bylismy;
vector<int> drzewo_przedzialowe;
queue<Element_kolejki> Q;

inline void update(int l, int p, int val)
{
    l = l + base - 1, p = p + base + 1;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            drzewo_przedzialowe[l+1] = max(drzewo_przedzialowe[l+1], val);
        if (p % 2 == 1)
            drzewo_przedzialowe[p-1] = max(drzewo_przedzialowe[p-1], val);
        l /= 2;
        p /= 2;
    }
}

inline int querry(int v)
{
    int res = -1e9;
    v += base;
    while (v > 0)
    {
        res = max(res,drzewo_przedzialowe[v]);
        v /= 2;
    }
    return res;
}

int main()
{
    // DZIĘKI !!!! https://forum.pasja-informatyki.pl/581981/zadanie-binarne-loty-letni-oboz-treningowy-oij-2021-przed-ejoi
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w >> h;
    czy_bylismy.assign(w+1,false);
    drzewo_przedzialowe.assign(rozmiar_drzewa,-1e9);
    for (int i = 0; i < n; ++i)
    {
        cin >> x_i >> y_i;
        ++y_i; // Konwertujemy wspolrzedna y na tak jak chcemy miec
        y_i = h - y_i; // // Konwertujemy wspolrzedna y na tak jak chcemy miec
        x1 = x_i - y_i - h; // Poczatek przedzialu ktorego i-ty stalaktyt dotyka
        x2 = x_i - (h - y_i); // Koniec przedzialu ktorego i-ty stalaktyt dotyka
        if (x2 < 0)
            continue;
        x1 = max(0,x1);
        x2 = max(x1,x2);
        update(x1,x2,y_i-x_i);
    }

    Q.push({0,0});
    czy_bylismy[0] = true;
    while(!Q.empty())
    {
        Element_kolejki spr = Q.front();
        Q.pop();
        int dlugosc_skoku = querry(spr.wierzcholek), licznik = 1;
        if (dlugosc_skoku == -1e9)
            dlugosc_skoku = h;
        else
        {
            int wsp = h - dlugosc_skoku, roznica = wsp - spr.wierzcholek;
            if (roznica % 2 == 0)
                dlugosc_skoku = roznica / 2 - 1;
            else
                dlugosc_skoku = roznica / 2;
        }

        while(licznik <= dlugosc_skoku)
        {
            if (spr.wierzcholek + licznik * 2 >= w)
            {
                cout << spr.wartosc + 1 << '\n';
                return 0;
            }
            else if (czy_bylismy[spr.wierzcholek + licznik * 2] == false)
            {
                czy_bylismy[spr.wierzcholek + licznik * 2] = true;
                Q.push({spr.wierzcholek + licznik * 2, spr.wartosc + 1});
            }
            licznik *= 2;
        }
    }

    cout << "NIE" << '\n';

    return 0;
}
