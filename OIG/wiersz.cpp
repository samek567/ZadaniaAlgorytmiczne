#include <iostream>

using namespace std;

int n = 0, k = 0, wyn = 0;
string wyraz_a,wyraz_b;

string usun_spacje(string &ciag)
{
    // Funkcja usujaca spacje.
    // Iterujemy po tekscie i dodajemy do wyniku tylko wtedy, gdy nie jest to spacja.
    // Mozna to zrobic tez przy pomocy funkcji erase oraz remove z biblioteki STL.
    string wyn;
    for (int i = 0; i < ciag.size(); ++i)
    {
        if (ciag[i] != ' ')
        {
            wyn += ciag[i];
        }
    }
    return wyn;
}

int licz_samogloski(string &ciag) // Mozemy podac referencje (wskazanie na miejsce w pamieci), bo nie modyfikujemy wyrazu.
{
    // Iterujemy po wyrazie i liczymy samogloski.
    int wynik = 0;
    for (int i = 0; i < ciag.size(); ++i)
    {
        if (ciag[i] == 'a' || ciag[i] == 'e' || ciag[i] == 'i' || ciag[i] == 'o' || ciag[i] == 'u' || ciag[i] == 'y')
        {
            wynik++;
        }
    }
    return wynik;
}

bool czy_pasuje(string &ciag1, string &ciag2)
{
    // Sprawdzamy czy wyrazy maja ostatnie k znakow takie same.

    if (ciag1.size() < k || ciag2.size() < k)
    {
        return false;
    }

    int wskaznik_ciag_1 = ciag1.size() - 1, wskaznik_ciag_2 = ciag2.size() - 1;

    for (int i = 0; i < k; ++i)
    {
        if (ciag1[wskaznik_ciag_1] != ciag2[wskaznik_ciag_2])
        {
            return false;
        }
        wskaznik_ciag_1--;
        wskaznik_ciag_2--;
    }

    return true;
}

int main()
{
    // Przyspieszamy wejscie i wyjscie.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    // Musimy getline, bo cin wczytuje jedynie do spacji.
    getline(cin,wyraz_a); // Opuszczamy jedna linie (ta co wpisujemy n,k)
    for (int i = 0; i < n; ++i)
    {
        getline(cin,wyraz_a); // Wczytujemy wyraz a (i spacje też)
        getline(cin,wyraz_b); // Wczytujemy wyraz b (i spacje tez)
        // Funkcja usujace spacje.
        wyraz_a = usun_spacje(wyraz_a);
        wyraz_b = usun_spacje(wyraz_b);
        if (licz_samogloski(wyraz_a) == licz_samogloski(wyraz_b) && czy_pasuje(wyraz_a,wyraz_b) == true) // Jeśli te warunki spełnione, to wyn++.
        {
            wyn++;
        }
    }

    cout << wyn;
    return 0;
    // O(n*x) - gdzie x to suma wszystkich znakow na wejsciu / n. -> O(y), gdzie y to liczba wszystkich znakow na wejsciu.
    // Dlatego taka zlozonnosc, bo wszystkie funkcje dzialaja jedynie w czasie liniowym do dlugosci napisu, wiec otrzymujemy
    // Maksymalnie O(3*y). Takie rozwiazanie daje 100pkt z duzym zapasem.
}