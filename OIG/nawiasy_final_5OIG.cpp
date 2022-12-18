#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n = 0, bilans = 0;
long long wyn = 0;
string ciag;
stack<int> S;
stack<int> S_ile_wystapien;

int main()
{
    /*
    Zadanie nawiasy z finalu V OIG-a. O(n).
    Jak chcemy sprawdzic czy dane wyrazenie nawiasowe jest poprawne, to mozemy to zrobic zmienna bilans i jesli nawias[i] = '(', to bilans++,
    nawias[i] = ')' to bilans--, gdzie nawias to wyrazenie nawiasowe. I teraz zeby wyrazenie bylo poprawne, to musza byc spelnione 2 warunki:
    1 - zmienna bilans na koniec musi byc rowna 0.
    2 - zmienna bilans nigdy nie moze byc mniejsza od 0.
    Na tej podstawie mozna konstruowac rozwiazanie w czasie O(n^2) szukajac nawiasu od kazdego elementu wyrazenia 2 petlami for.
    My musimy to zrobic szybciej bo n <= 2*10^6. Stos zalatwia nam sprawe.
    Zauwazmy, ze nasze rozwiazanie sie amortyzuje do O(n), bo kazdy element maksymalnie raz dodamy i usuniemy z stosu.

    Stos S przechowuje wartosci zmiennej bilans, a i-ty element stosu S_ile_wystapien mowi ile jest wystapien i-tego elementu stosu S.
    Dzieki stosowi S_ile_wystapien mozemy przy aktualizowaniu wyniku wiedziec ile mamy dodac, bo sam stos S nie daje nam takiej informacji.
    Mozna alternatywnie zamiast stosu S_ile_wystapien zrobic tylko jeden stos (strukture: wartosc, ile wystapien).

    Mozna zamiast 2 stosu zrobic mapa, jednak wtedy O(n log n), co jest zawolne. Wchodzi na okolo 70%
    Mozna tez zamiast S_ile_wystapien miec tablice o rozmiarze 2*n+1, gdzie trzymamy wartosci. Nie przejmujac sie ujemnymi wartosciami zmiennej bilans,
    bo mozna to obejsc stosujac konwencje ze element o bilansie 0 jest na pozycji 10^6, bilans 5 na pozycji 10^6 + 5 itd, bilans = -5 na pozycji 10^6 - 5 itd.
    W obu rozwiazaniach (z stosem i tablica) otrzymujemy rozwiazanie w zlozonnosci O(n).
     */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;
    S.push(0);
    S_ile_wystapien.push(1);
    for (int i = 0; i < n; ++i)
    {
        if(ciag[i] == '(')
            bilans++;
        else
            bilans--;

        while(!S.empty())
        {
            if (S.top() > bilans)
            {
                S.pop();
                S_ile_wystapien.pop();
            }
            else
                break;
        }
        if (!S.empty())
        {
            if (S.top() == bilans)
                wyn += S_ile_wystapien.top();
            if (S.top() == bilans)
            {
                S_ile_wystapien.top()++;
            }
            else
            {
                S.push(bilans);
                S_ile_wystapien.push(1);
            }
        }
        else
        {
            S.push(bilans);
            S_ile_wystapien.push(1);
        }
    }

    printf("%lld",wyn);

    return 0;
}