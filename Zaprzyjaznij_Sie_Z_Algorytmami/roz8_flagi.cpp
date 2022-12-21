#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0;
vector<int> liczby;
vector<int> idxy_szczytow;

inline bool czy_da_sie_ulozyc(int k)
{
    int wsk1 = 0;
    int wsk2 = 1;
    int ile_ulozylismy = 1;

    while(true)
    {
        if (idxy_szczytow[wsk2] - idxy_szczytow[wsk1] >= k)
        {
            ile_ulozylismy++;
            wsk1 = wsk2;
            wsk2++;
        }
        else
        {
            wsk2++;
        }
        if (wsk2 == idxy_szczytow.size())
            break;
    }
    if (ile_ulozylismy >= k)
        return true;
    else
        return false;
}

int main()
{
    /*
    O(n log n) Binary search po wyniku.
    Typowy motyw w zadaniach olimpijskich.
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    for (int i = 1; i < n-1; ++i)
    {
        if (liczby[i] > liczby[i-1] && liczby[i] > liczby[i+1])
            idxy_szczytow.push_back(i);
    }

    if (idxy_szczytow.size() == 0 || idxy_szczytow.size() == 1)
    {
        printf("%d",idxy_szczytow.size());
        return 0;
    }

    poczatek = -1;
    koniec = n;
    while(koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_da_sie_ulozyc(srodek) == true)
            poczatek = srodek;
        else
            koniec = srodek;
    }

    printf("%d",poczatek);

    return 0;
}
