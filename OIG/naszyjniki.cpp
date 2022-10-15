#include <iostream>
#include <string>
#include <climits>

using namespace std;

struct Grupa
{
    int liczba_elementow;
    string rodzaj;
};

string wyznaczanie_kierunku (char znak)
{
    string wyswietlany_rodzaj;
    if (isupper(znak))
    {
        if (znak == 'A' || znak == 'E' || znak == 'I' || znak == 'O' || znak == 'U' || znak == 'Y')
        {
            wyswietlany_rodzaj = "JASNE";
        }
        else
        {
            wyswietlany_rodzaj = "CIEMNE";
        }
    }
    else
    {
        if (znak == 'a' || znak == 'e' || znak == 'i' || znak == 'o' || znak == 'u' || znak == 'y')
        {
            wyswietlany_rodzaj = "jasne";
        }
        else
        {
            wyswietlany_rodzaj = "ciemne";
        }
    }
    return wyswietlany_rodzaj;
}

Grupa aktualizowanie_maxa (Grupa aktualny_max, string sprawdzany_kierunek, int liczba_elementow)
{
    if (liczba_elementow > aktualny_max.liczba_elementow)
    {
        aktualny_max.liczba_elementow = liczba_elementow;
        aktualny_max.rodzaj = sprawdzany_kierunek;
    }
    else if (liczba_elementow == aktualny_max.liczba_elementow)
    {
        if (aktualny_max.rodzaj == "CIEMNE")
        {
            if (sprawdzany_kierunek == "JASNE")
            {
                aktualny_max.rodzaj = sprawdzany_kierunek;
            }
        }
        else if (aktualny_max.rodzaj == "jasne")
        {
            if (sprawdzany_kierunek == "JASNE" || sprawdzany_kierunek == "CIEMNE")
            {
                aktualny_max.rodzaj = sprawdzany_kierunek;
            }
        }
        else if (aktualny_max.rodzaj == "ciemne")
        {
            aktualny_max.rodzaj = sprawdzany_kierunek;
        }
    }
    return aktualny_max;
}

Grupa aktualizowanie_mina (Grupa aktualny_min, string sprawdzany_kierunek, int liczba_elementow)
{
    if (liczba_elementow < aktualny_min.liczba_elementow)
    {
        aktualny_min.liczba_elementow = liczba_elementow;
        aktualny_min.rodzaj = sprawdzany_kierunek;
    }
    else if (liczba_elementow == aktualny_min.liczba_elementow)
    {
        if (aktualny_min.rodzaj == "CIEMNE")
        {
            if (sprawdzany_kierunek == "JASNE")
            {
                aktualny_min.rodzaj = sprawdzany_kierunek;
            }
        }
        else if (aktualny_min.rodzaj == "jasne")
        {
            if (sprawdzany_kierunek == "JASNE" || sprawdzany_kierunek == "CIEMNE")
            {
                aktualny_min.rodzaj = sprawdzany_kierunek;
            }
        }
        else if (aktualny_min.rodzaj == "ciemne")
        {
            aktualny_min.rodzaj = sprawdzany_kierunek;
        }
    }
    return aktualny_min;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int liczba_elementow = 0;
    int licznik_elementow = 0;
    int elementy_poczatek = 0;
    string ciag;
    string poczatkowy_kierunek;
    string sprawdzany_kierunek;
    string koncowy_kierunek;
    string kierunek_wybor;
    int od_kad_sprawdzamy = 0;
    bool czy_sprawdzamy = false;
    bool czy_rozwazamy = true;
    bool czy_dodajemy = true;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {


        liczba_elementow = 0;
        licznik_elementow = 0;
        elementy_poczatek = 0;
        od_kad_sprawdzamy = 0;
        czy_sprawdzamy = false;
        czy_rozwazamy = true;
        czy_dodajemy = true;

        Grupa Max_grupa;
        Grupa Min_grupa;

        Max_grupa.liczba_elementow = 0;
        Min_grupa.liczba_elementow = INT_MAX;


        cin >> ciag;

        poczatkowy_kierunek = wyznaczanie_kierunku(ciag[0]);
        kierunek_wybor = poczatkowy_kierunek;

        liczba_elementow = 0;

        for (int j = 0; j < ciag.size(); ++j)
        {
            sprawdzany_kierunek = wyznaczanie_kierunku(ciag[j]);
            od_kad_sprawdzamy = j;
            if (sprawdzany_kierunek == poczatkowy_kierunek)
            {
                liczba_elementow++;
                if (j == ciag.size()-1)
                {
                    czy_rozwazamy = false;
                }
            }
            else
            {
                elementy_poczatek = j;
                koncowy_kierunek = poczatkowy_kierunek;
                break;
            }
        }

        poczatkowy_kierunek = sprawdzany_kierunek;

        if (czy_rozwazamy)
        {
            liczba_elementow = 0;

            for (int k = od_kad_sprawdzamy; k < ciag.size(); ++k)
            {
                sprawdzany_kierunek = wyznaczanie_kierunku(ciag[k]);
                if (sprawdzany_kierunek == poczatkowy_kierunek)
                {
                    liczba_elementow++;
                    if (k == ciag.size()-1)
                    {
                        czy_sprawdzamy = true;
                    }
                }
                else
                {
                    Max_grupa = aktualizowanie_maxa(Max_grupa,poczatkowy_kierunek,liczba_elementow);
                    Min_grupa = aktualizowanie_mina(Min_grupa,poczatkowy_kierunek,liczba_elementow);
                    poczatkowy_kierunek = sprawdzany_kierunek;
                    liczba_elementow = 1;
                    if (sprawdzany_kierunek == poczatkowy_kierunek)
                    {
                        if (k == ciag.size()-1)
                        {
                            czy_sprawdzamy = true;
                        }
                    }
                }
            }

            if (czy_sprawdzamy)
            {
                if (poczatkowy_kierunek == koncowy_kierunek)
                {
                    liczba_elementow += elementy_poczatek;
                    czy_dodajemy = false;
                }
                Min_grupa = aktualizowanie_mina(Min_grupa,poczatkowy_kierunek,liczba_elementow);
                Max_grupa = aktualizowanie_maxa(Max_grupa,poczatkowy_kierunek,liczba_elementow);
            }
            if (czy_dodajemy)
            {
                Min_grupa = aktualizowanie_mina(Min_grupa,kierunek_wybor,od_kad_sprawdzamy);
                Max_grupa = aktualizowanie_maxa(Max_grupa,kierunek_wybor,od_kad_sprawdzamy);
            }
        }
        else
        {
            Min_grupa.liczba_elementow = liczba_elementow;
            Min_grupa.rodzaj = kierunek_wybor;
            Max_grupa.liczba_elementow = liczba_elementow;
            Max_grupa.rodzaj = kierunek_wybor;
        }


        cout << Max_grupa.liczba_elementow << " " << Max_grupa.rodzaj << endl;
        cout << Min_grupa.liczba_elementow << " " << Min_grupa.rodzaj << endl;
    }
    return 0;
}