#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long objetosc_paliwa_bajtka = 0;
    long long objetosc_paliwa_kajtka = 0;
    long long objetosc_paliwa_zajtka = 0;

    long long liczba_modolow_bajtka = 0;
    long long liczba_modolow_kajtka = 0;
    long long liczba_modolow_zajtka = 0;

    long long aktualna_wartosc_modulu = 0;

    long long wyrazenie_modulu = 0;

    double najwiekszy_modul_bajtka = -1;
    double najwiekszy_modul_kajtka = -1;
    double najwiekszy_modul_zajtka = -1;

    long double najwieksza_wartosc_modulu = 0;

    vector<long long>liczby_bajtka;
    vector<long long>liczby_kajtka;
    vector<long long>liczby_zajtka;

    cin >> objetosc_paliwa_bajtka >> objetosc_paliwa_kajtka >> objetosc_paliwa_zajtka;

    cin >> liczba_modolow_bajtka;

    wyrazenie_modulu = 0;
    for (int i = 0; i < liczba_modolow_bajtka; i++)
    {
        cin >> aktualna_wartosc_modulu;
        wyrazenie_modulu = aktualna_wartosc_modulu * objetosc_paliwa_bajtka;
        if (wyrazenie_modulu > najwiekszy_modul_bajtka)
        {
            najwiekszy_modul_bajtka = wyrazenie_modulu;
        }
        liczby_bajtka.push_back(wyrazenie_modulu);
    }

    cin >> liczba_modolow_kajtka;

    wyrazenie_modulu = 0;
    for (int i = 0; i < liczba_modolow_kajtka; i++)
    {
        cin >> aktualna_wartosc_modulu;
        wyrazenie_modulu = aktualna_wartosc_modulu * objetosc_paliwa_kajtka;
        if (wyrazenie_modulu > najwiekszy_modul_kajtka)
        {
            najwiekszy_modul_kajtka = wyrazenie_modulu;
        }
        liczby_kajtka.push_back(wyrazenie_modulu);
    }

    cin >> liczba_modolow_zajtka;

    wyrazenie_modulu = 0;
    for (int i = 0; i < liczba_modolow_zajtka; i++)
    {
        cin >> aktualna_wartosc_modulu;
        wyrazenie_modulu = aktualna_wartosc_modulu * objetosc_paliwa_zajtka;
        if (wyrazenie_modulu > najwiekszy_modul_zajtka)
        {
            najwiekszy_modul_zajtka = wyrazenie_modulu;
        }
        liczby_zajtka.push_back(wyrazenie_modulu);
    }

    najwieksza_wartosc_modulu = (najwiekszy_modul_bajtka + najwiekszy_modul_kajtka + najwiekszy_modul_zajtka) / 2;

    /*
    cout << "Liczby Bajtka: " << endl;
    for (int i = 0; i < liczby_bajtka.size(); i++)
    {
        cout << liczby_bajtka[i] << " ";
    }
    cout << endl;

    cout << "Liczby Kajtka: " << endl;
    for (int i = 0; i < liczby_kajtka.size(); i++)
    {
        cout << liczby_kajtka[i] << " ";
    }
    cout << endl;

    cout << "Liczby Zajtka: " << endl;
    for (int i = 0; i < liczby_zajtka.size(); i++)
    {
        cout << liczby_zajtka[i] << " ";
    }
    cout << endl;

    cout << "Najwiekszy modul Bajtka: " << najwiekszy_modul_bajtka << " " << endl;
    cout << "Najwiekszy modul Kajtka: " << najwiekszy_modul_kajtka << " " << endl;
    cout << "Najwiekszy modul Zajtka: " << najwiekszy_modul_zajtka << " " << endl;

    cout << "Najwieksza wartosc modulu (polowa): " << najwieksza_wartosc_modulu << " " << endl;
     */
    sort(liczby_bajtka.begin(),liczby_bajtka.end());
    sort(liczby_kajtka.begin(),liczby_kajtka.end());
    //sort(liczby_zajtka.begin(),liczby_zajtka.end(),greater<long long>());
    sort(liczby_zajtka.begin(),liczby_zajtka.end());

    int licznik_elementow = 0;

    for (int i = 0; i < liczby_bajtka.size(); i++)
    {
        if (liczby_bajtka[i] > najwieksza_wartosc_modulu) {
            licznik_elementow += (liczby_bajtka.size()-i) * liczby_kajtka.size() * liczby_zajtka.size();
            break;
        }
        for (int j = 0; j < liczby_kajtka.size(); j++)
        {
            if (liczby_bajtka[i] + liczby_kajtka[j] > najwieksza_wartosc_modulu) {
                licznik_elementow += (liczby_kajtka.size()-j) * liczby_zajtka.size();
                break;
            }
            long long val = najwieksza_wartosc_modulu - liczby_bajtka[i] - liczby_kajtka[j];
            //*
            if (liczby_zajtka[0] > val) {
                licznik_elementow += liczby_zajtka.size();
                continue;
            } else if (liczby_zajtka[liczby_zajtka.size()-1]<=val) {
                continue;
            }
            //*/
            int x = 0;
            int y = liczby_zajtka.size();
            while(y - x > 1) {
                if (liczby_zajtka[x + (y - x) / 2] > val) {
                    y -= (y - x) / 2;
                } else {
                    x += (y - x) / 2;
                }
                // cout << "x: " << x << " y: " << y << endl;
            }
            licznik_elementow += liczby_zajtka.size() - y;
            /*
            for (int k = liczby_zajtka.size()-1; k > -1; k--)
            {
                if (liczby_bajtka[i] + liczby_kajtka[j] + liczby_zajtka[k] > najwieksza_wartosc_modulu)
                {
                    licznik_elementow++;
                }
                else
                {
                    break;
                }
            }
             */
        }
    }



    cout << licznik_elementow;

    return 0;
}