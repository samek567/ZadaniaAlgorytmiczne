#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

int main()
{
    int n = 0;
    int poczatek = 0;
    int koniec = 1;
    int min_wynik = INT_MAX;
    long long aktualna_liczba = 0;
    unordered_map<long long, int> gasienica;

    cin >> n;

    long long segmenty[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> aktualna_liczba;
        segmenty[i] = aktualna_liczba;
    }

    if (n < 3)
    {
        printf("NIE");
        return 0;
    }

    gasienica.insert({segmenty[0],1});

    if (gasienica.find(segmenty[1]) != gasienica.end())
    {
        gasienica[segmenty[0]]++;
    }
    else
    {
        gasienica.insert({segmenty[1],1});
    }

    bool czy_przesuwamy_poczatek = false;
    while (koniec < n || czy_przesuwamy_poczatek)
    {
        if (czy_przesuwamy_poczatek)
        {
            gasienica[segmenty[poczatek]]--;
            poczatek++;
            if (gasienica[segmenty[poczatek-1]] == 2)
            {
                czy_przesuwamy_poczatek = false;
            }
            else
            {
                if (koniec - poczatek + 1 < min_wynik)
                {
                    min_wynik = koniec - poczatek + 1;
                }
            }

        }
        else
        {
            koniec++;
            if (gasienica.find(segmenty[koniec]) != gasienica.end())
            {
                gasienica[segmenty[koniec]]++;
            }
            else
            {
                gasienica.insert({segmenty[koniec],1});
            }
            if (gasienica[segmenty[koniec]] == 3)
            {
                if (koniec - poczatek + 1 < min_wynik)
                {
                    min_wynik = koniec - poczatek + 1;
                }
                czy_przesuwamy_poczatek = true;
            }
        }
    }

    if (min_wynik == INT_MAX)
    {
        printf("NIE");
    }
    else
    {
        printf("%d",min_wynik);
    }
    return 0;
}