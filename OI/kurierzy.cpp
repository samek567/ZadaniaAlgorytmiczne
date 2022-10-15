#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Element
{
    int wartosc;
    int liczba_powtorzen;
};

Element polacz (Element& pierwszy, Element& drugi)
{
    Element wynik = pierwszy;
    if (pierwszy.wartosc == drugi.wartosc)
    {
        wynik = {pierwszy.wartosc,pierwszy.liczba_powtorzen+drugi.liczba_powtorzen};
    }
    else
    {
        if (pierwszy.liczba_powtorzen > drugi.liczba_powtorzen)
        {
            wynik = {pierwszy.wartosc,pierwszy.liczba_powtorzen-drugi.liczba_powtorzen};
        }
        else if (pierwszy.liczba_powtorzen < drugi.liczba_powtorzen)
        {
            wynik = {drugi.wartosc,drugi.liczba_powtorzen-pierwszy.liczba_powtorzen};
        }
        else
        {
            wynik = {0,0};
        }
    }
    return wynik;
}

Element query (int p, int k, Element drzewo_przedzialowe[])
{
    Element wynik = {0,0};
    while (p/2 != k/2)
    {
        if (p % 2 == 0)
        {
            wynik = polacz(wynik,drzewo_przedzialowe[p+1]);
        }
        if (k % 2 == 1)
        {
            wynik = polacz(wynik,drzewo_przedzialowe[k-1]);
        }
        p/=2;
        k/=2;
    }
    return wynik;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int m = 0;
    int wczytana_przesylka = 0;
    int poczatek = 0;
    int koniec = 0;

    cin >> n >> m;
    int licznik_pasujacych = 0;
    int rozmiar_drzewa = pow(2,ceil((double)log2(n))) * 2;
    int base = rozmiar_drzewa / 2;
    int base_zapytania = base-1;
    Element drzewo_przedzialowe[rozmiar_drzewa];
    vector<int> Statystyki[n+1];

    for (int i = 0; i <= base; ++i)
    {
        if (i >= n)
        {
            drzewo_przedzialowe[base+i] = {0,0};
        }
        else
        {
            cin >> wczytana_przesylka;
            Statystyki[wczytana_przesylka].push_back(i+1);
            drzewo_przedzialowe[base+i] = {wczytana_przesylka,1};
        }
    }

    base = base / 2;
    while (base > 0) // Ustawiamy drzewo
    {
        for (int j = base; j < base*2; ++j)
        {
            drzewo_przedzialowe[j] = polacz(drzewo_przedzialowe[j*2],drzewo_przedzialowe[j*2+1]);
        }
        base = base / 2;
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> poczatek >> koniec;
        int kandydat_na_lidera = query(poczatek+base_zapytania-1,koniec+base_zapytania+1,drzewo_przedzialowe).wartosc;
        licznik_pasujacych = 0;

        int p = -1;
        int k = Statystyki[kandydat_na_lidera].size();
        int s = 0;
        int pierwszy_pasujacy = 0;

        while (k- p != 1)
        {
            s = (p + k) / 2;
            if (Statystyki[kandydat_na_lidera][s] >= poczatek)
            {
                k = s;
            }
            else
            {
                p = s;
            }
        }
        pierwszy_pasujacy = k;


        p = -1;
        k = Statystyki[kandydat_na_lidera].size();
        s = 0;
        int ostatni_pasujacy = 0;

        while (k - p != 1)
        {
            s = (p + k) / 2;
            if (Statystyki[kandydat_na_lidera][s] <= koniec)
            {
                p = s;
            }
            else
            {
                k = s;
            }
        }
        ostatni_pasujacy = p;
        licznik_pasujacych = ostatni_pasujacy - pierwszy_pasujacy + 1;


        if (licznik_pasujacych > (koniec-poczatek+1) / 2)
        {
            cout << kandydat_na_lidera << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }

    return 0;
}