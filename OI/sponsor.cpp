#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Element_vectora
{
    double wartosc;
    int idx;

    bool operator < (const Element_vectora &element_vectora) const
    {
        if (wartosc == element_vectora.wartosc)
        {
            return idx > element_vectora.idx;
        }
        return wartosc > element_vectora.wartosc;
    }
};

int n = 0, max_wyn = 0, base = 0, rozmiar_drzewa = 0;
double wczytana_liczba = 0;
vector<double> liczby;
vector<Element_vectora> do_sorta;
vector<int> jaki_idx;
vector<int> drzewo_przedzialowe;
vector<int> ile_na_lewo_te_same;

int querry(int p, int k)
{
    int poczatek = p - 1 + base;
    int koniec = k + 1 + base;
    int wynik = 0;

    while (poczatek / 2 != koniec / 2)
    {
        if (poczatek % 2 == 0)
        {
            wynik = max(wynik,drzewo_przedzialowe[poczatek+1]);
        }
        if (koniec % 2 == 1)
        {
            wynik = max(wynik,drzewo_przedzialowe[koniec-1]);
        }
        poczatek /= 2;
        koniec /= 2;
    }
    return wynik;
}

void update(int gdzie, int wartosc)
{
    int v = gdzie + base;
    drzewo_przedzialowe[v] = wartosc;
    v /= 2;

    while (v > 0)
    {
        drzewo_przedzialowe[v] = max(drzewo_przedzialowe[v*2],drzewo_przedzialowe[v*2+1]);
        v /= 2;
    }
}

void wypisz_stan_drzewa()
{
    for (int i = base; i < rozmiar_drzewa; ++i)
    {
        cout << drzewo_przedzialowe[i] << " ";
    }
    cout << endl;
}

int main()
{
    /*
     Dynamik z drzewami przedzialowymi.
     https://forum.pasja-informatyki.pl/575473/zadanie-sponsor-oi
     https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
     Dzieki za pomoc Whistleroosh!
     */

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    jaki_idx.assign(n,0);
    ile_na_lewo_te_same.assign(n,0);

    rozmiar_drzewa = pow(2,ceil((double)log2(n))) * 2;
    base = rozmiar_drzewa / 2;
    drzewo_przedzialowe.assign(rozmiar_drzewa,0);

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        do_sorta.push_back({wczytana_liczba,i});
        liczby.push_back(wczytana_liczba);
    }
    sort(do_sorta.begin(),do_sorta.end());

    for (int i = 0; i < n; ++i)
    {
        jaki_idx[do_sorta[i].idx] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        int licznik = 1;
        for (int j = i+1; j < n; ++j)
        {
            if (do_sorta[i].wartosc == do_sorta[j].wartosc)
            {
                licznik++;
            }
            else
            {
                break;
            }
        }
        int ile_uzupelniamy = 0;
        for (int j = 0; j < licznik; ++j)
        {
            ile_na_lewo_te_same[i+j] = ile_uzupelniamy;
            ile_uzupelniamy++;
        }
        i += licznik-1;
    }

    for (int i = 0; i < n; ++i)
    {
        if (jaki_idx[i] == 0 || ile_na_lewo_te_same[jaki_idx[i]] == jaki_idx[i])
        {
            update(jaki_idx[i],1);
        }
        else
        {
            update(jaki_idx[i],querry(0,jaki_idx[i]-ile_na_lewo_te_same[jaki_idx[i]])+1);
        }
    }

    printf("%d00", querry(0,base-1));

    return 0;
}