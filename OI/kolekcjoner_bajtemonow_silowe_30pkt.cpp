#include <iostream>
#include <map>
#include "ckollib.h"

using namespace std;

int wczytana_karta = 0, l = 0, max_wartosc = 0;
map<int,int> stat;

int main()
{
    wczytana_karta = karta();
    stat[wczytana_karta] = 1;

    while (true)
    {
        wczytana_karta = karta();
        if (wczytana_karta == 0)
        {
            break;
        }
        if (auto it = stat.find(wczytana_karta) != stat.end()) // Znalezlismy
        {
            stat[wczytana_karta]++;
        }
        else
        {
            stat[wczytana_karta] = 1;
        }
    }

    if (stat.size() == 1)
    {
        odpowiedz(stat.begin()->first);
    }

    for (auto i : stat)
    {
        max_wartosc = max(max_wartosc,i.second);
        l++;
        if (l == 2)
        {
            break;
        }
    }

    for (auto i : stat)
    {
        if (i.second < max_wartosc)
        {
            odpowiedz(i.first);
        }
    }

    return 0;
}