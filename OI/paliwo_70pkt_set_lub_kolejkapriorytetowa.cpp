#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Stacja
{
    long long jednostka_paliwa;
    long long pozycja;
};

struct Element_seta
{
    long long wartosc;
    mutable long long liczba_wystapien;

    bool operator < (const Element_seta & element_seta) const
    {
        return wartosc > element_seta.wartosc;
    }
};

long long p = 0, n = 0, dlugosc_trasy = 0, d_i, suma_na_secie = 0, wynik = 0;
vector<Stacja> stacje;
set<Element_seta> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> n;

    stacje.assign(n+1,{});
    stacje[0].pozycja = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> stacje[i].jednostka_paliwa >> d_i;
        if (i < n - 1)
        {
            stacje[i+1].pozycja = stacje[i].pozycja + d_i;
        }

        dlugosc_trasy += d_i;
    }

    p = min(p,dlugosc_trasy);
    stacje[n] = {-1,dlugosc_trasy};

    for (int i = 0; i < n; ++i)
    {
        if (S.size() == 0)
        {
            S.insert({stacje[i].jednostka_paliwa,p});
            suma_na_secie = p;
        }
        else
        {
            // Usuwamy wszystkie wieksze niz ma stacja[i]. jednostka, dodajemy tyle ile brakuje do sumy. Korzystamy z tego, że zawsze lepiej nawet nam napełnić cały bak paliwem o jednostce 2 niż mieć nawet kilka o jednostce 3,5,6,10,100 itd.
            vector<Element_seta> do_usuniecia;
            for (auto j : S)
            {
                if (j.wartosc >= stacje[i].jednostka_paliwa)
                {
                    do_usuniecia.push_back(j);
                    suma_na_secie -= j.liczba_wystapien;
                }
                else
                {
                    break;
                }
            }

            for (auto j : do_usuniecia)
            {
                S.erase(j);
            }
            if (suma_na_secie != p)
            {
                S.insert({stacje[i].jednostka_paliwa,p - suma_na_secie});
            }
            suma_na_secie = p;
        }

        // Aktualizujemy koszt drogi do kolejnej stacji.
        suma_na_secie -= stacje[i+1].pozycja - stacje[i].pozycja;
        long long ile_zostalo_do_usuniecia = stacje[i+1].pozycja - stacje[i].pozycja;
        vector<Element_seta> usuniecie;
        for (auto it = S.rbegin(); it != S.rend(); ++it)
        {
            if (ile_zostalo_do_usuniecia <= 0)
            {
                break;
            }
            if (ile_zostalo_do_usuniecia >= it->liczba_wystapien)
            {
                wynik += it->wartosc * it->liczba_wystapien;
                usuniecie.push_back(*it);
                ile_zostalo_do_usuniecia -= it->liczba_wystapien;
            }
            else
            {
                wynik += ile_zostalo_do_usuniecia * it->wartosc;
                it->liczba_wystapien -= ile_zostalo_do_usuniecia;
                ile_zostalo_do_usuniecia -= ile_zostalo_do_usuniecia;
            }
        }

        for (auto j : usuniecie)
        {
            S.erase(j);
        }

    }

    cout << wynik << "\n";

    return 0;
}
