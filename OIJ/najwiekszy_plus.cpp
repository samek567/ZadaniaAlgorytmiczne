#include <iostream>

using namespace std;

bool czy_istnieje (int rozmiar_plusa, int rozmiar_tablicy, int tablica[])
{
    int licznik = 0;
    for (int i = 0; i < rozmiar_tablicy; ++i)
    {
        if (licznik != rozmiar_plusa)
        {
            if (tablica[i] >= rozmiar_plusa+1)
            {
                licznik++;
            }
            else
            {
                licznik = 0;
            }
        }
        else
        {
            if (tablica[i] >= 2 * rozmiar_plusa + 1)
            {
                licznik++;
            }
            else
            {
                if (tablica[i] < rozmiar_plusa+1)
                {
                    licznik = 0;
                }
            }
        }
        if (rozmiar_tablicy - licznik < (2 * rozmiar_plusa + 1) - licznik)
        {
            return false;
        }
        else if (licznik == 2 * rozmiar_plusa + 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    int n = 0;
    int liczba = 0;
    int k = 0;
    int p = -1;
    int s = 0;

    cin >> n;

    int filary[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> liczba;
        filary[i] = liczba;
    }

    k = (n - 1) / 2 + 1; // Zastanow sie czy nie trzeba +1.


    while (k - p != 1)
    {
        s = (p + k) / 2;
        if (czy_istnieje(s,n,filary))
        {
            p = s;
        }
        else
        {
            k = s;
        }
    }

/*
    if (czy_istnieje(p+1,n,filary))
    {
        printf("%d", p+1);
        return 0;
    }
*/

    printf("%d", k-1);

    return 0;
}