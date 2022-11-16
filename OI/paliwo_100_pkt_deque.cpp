#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct Stacja
{
    int x;
    int cena;
};

struct Elemen_stosu
{
    int ile_wystapien;
    int cena;
};

int p = 0, n = 0, c_i = 0, d_i = 0, ile_do_usuniecia = 0, wynik = 0, ile_jest_na_stosie = 0;
vector<Stacja> stacje;
deque<Elemen_stosu> S;

void wypisz_stacje()
{
    cout << "Wypisuje stacje: " << endl;
    for (int i = 0; i <= n; ++i)
    {
        cout << "X: " << stacje[i].x << " Cena: " << stacje[i].cena << endl;
    }
    cout << endl;
}

int main()
{
    // Zadanie Paliwo 3 etap IV OI, na kolejke monotonniczna.
    // Algorytm jest liniowy. Kazdy element razy dodamy i maksymalnie raz zdejmiemy z stosu.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> n;
    stacje.assign(n+1, {0,0});

    for (int i = 1; i <= n; ++i)
    {
        cin >> c_i >> d_i;
        stacje[i].x = stacje[i-1].x + d_i;
        stacje[i-1].cena = c_i;
    }
    p = min(p,stacje[n].x);

    //wypisz_stacje();

    for (int i = 0; i < n; ++i)
    {
        if (S.empty())
        {
            S.push_front({p,stacje[i].cena});
            ile_jest_na_stosie = p;
        }
        else
        {
            // Idziemy od konca i usuwamy wszystkie wieksze.
            while (!S.empty())
            {
                if (S.back().cena >= stacje[i].cena)
                {
                    ile_jest_na_stosie -= S.back().ile_wystapien;
                    S.pop_back();
                }
                else
                {
                    break;
                }
            }
            S.push_back({p - ile_jest_na_stosie,stacje[i].cena});
            ile_jest_na_stosie = p;
        }

        ile_do_usuniecia = stacje[i+1].x - stacje[i].x;
        ile_jest_na_stosie -= ile_do_usuniecia;
        while(ile_do_usuniecia > 0)
        {
            Elemen_stosu spr = S.front();
            if (ile_do_usuniecia - spr.ile_wystapien >= 0)
            {
                ile_do_usuniecia -= spr.ile_wystapien;
                wynik += spr.ile_wystapien * spr.cena;
                S.pop_front();
            }
            else
            {
                wynik += ile_do_usuniecia * S.front().cena;
                S.front().ile_wystapien -= ile_do_usuniecia;
                ile_do_usuniecia = 0;
            }
        }
    }

    cout << wynik << '\n';

    return 0;
}
