#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, k = 0, wczytana_liczba = 0, wskaznik_statystyki = 0, wartosc_statystyki = 0;
vector<int> liczby_bajtka;
vector<int> liczby_bitka;
vector<int> statystyki_poczatek;
vector<int> statystyki_koniec;
vector<bool> czy_mozna_ulozyc;
vector<vector<int>> wystapienia_bitka;

int binary_searchh(int i)
{
    int poczatek = -1;
    int koniec = wystapienia_bitka[liczby_bajtka[i]].size();
    int s = 0;

    while (koniec-poczatek != 1)
    {
        s = (poczatek + koniec) / 2;
        if (wystapienia_bitka[liczby_bajtka[i]][s] + 1 <= statystyki_poczatek[i]) // trzeba sie zastanowic nad tym warunkiem a konkretniej <= statystyki_poczatek[i.
        {
            poczatek = s;
        }
        else
        {
            koniec = s;
        }
    }

    if (poczatek == -1)
    {
        return -1;
    }
    else
    {
        return wystapienia_bitka[liczby_bajtka[i]][poczatek];
    }

}

void wypisz_statystyki()
{
    cout << "Wypisuje statystyki przod: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << statystyki_poczatek[i] << " ";
    }
    cout << endl;

    cout << "Wypisuje statystyki koniec: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << statystyki_koniec[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i <= k; ++i)
    {
        wystapienia_bitka.push_back({});
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby_bajtka.push_back(wczytana_liczba);
        statystyki_koniec.push_back(0);
        czy_mozna_ulozyc.push_back(false);
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        liczby_bitka.push_back(wczytana_liczba);
        wystapienia_bitka[wczytana_liczba].push_back(i);
    }

    for (int i = 0; i < n; ++i)
    {
        if (wskaznik_statystyki != m)
        {
            if (liczby_bajtka[i] == liczby_bitka[wskaznik_statystyki])
            {
                wartosc_statystyki++;
                wskaznik_statystyki++;
            }
        }
        statystyki_poczatek.push_back(wartosc_statystyki);
    }


    wskaznik_statystyki = m-1;
    wartosc_statystyki = 0;

    for (int i = n-1; i >= 0; --i)
    {
        if (wskaznik_statystyki != -1)
        {
            if (liczby_bajtka[i] == liczby_bitka[wskaznik_statystyki])
            {
                wartosc_statystyki++;
                wskaznik_statystyki--;
            }
        }
        statystyki_koniec[i] = wartosc_statystyki;
    }


    for (int i = 0; i < n; ++i)
    {
        int idx_znalezionej = binary_searchh(i);
        if (statystyki_koniec[i] >= m - idx_znalezionej && idx_znalezionej != -1)
        {
            czy_mozna_ulozyc[i] = true;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << czy_mozna_ulozyc[i] << " ";
    }

    return 0;
}