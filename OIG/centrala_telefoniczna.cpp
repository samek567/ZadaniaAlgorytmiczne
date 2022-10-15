#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Wielokat
{
    long long nagroda;
    long long potrzebny_promien;

    bool operator < (const Wielokat&wielokat) const
    {
        return potrzebny_promien < wielokat.potrzebny_promien;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int k = 0;
    int wczytana_nagroda = 0;
    int wczytana_liczba_wierzcholkow = 0;
    long long wczytane_x = 0;
    long long wczytane_y = 0;
    double min_promien = 0;
    double odleglosc = 0;
    long long max_zysk = 0;
    long long zysk = 0;
    long long zasieg = 0;
    long long poprzednia_suma = 0;
    vector<Wielokat> wielokaty;

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba_wierzcholkow >> wczytana_nagroda;
        min_promien = 0;

        for (int j = 0; j < wczytana_liczba_wierzcholkow; ++j)
        {
            cin >> wczytane_x >> wczytane_y;
            odleglosc = sqrt(pow(wczytane_x,2) + pow(wczytane_y,2));
            min_promien = max(min_promien,odleglosc);
        }
        wielokaty.push_back({wczytana_nagroda,ceil(min_promien)});
    }

    sort(wielokaty.begin(),wielokaty.end());

    for (int i = 0; i < n; ++i)
    {
        zysk = poprzednia_suma + wielokaty[i].nagroda;

        if (wielokaty[i].potrzebny_promien % k != 0)
        {
            zasieg = (wielokaty[i].potrzebny_promien / k) * k + k;
        }
        else
        {
            zasieg = wielokaty[i].potrzebny_promien;
        }
        long long ile_razy_zwiekszyc = zasieg / k;
        long long koszt_utrzymania = (ile_razy_zwiekszyc-1) * (ile_razy_zwiekszyc) / 2; // Suma ciagu od 0 do ile_razy_zwiekszyc -1

        zysk -= koszt_utrzymania;

        max_zysk = max(max_zysk,zysk);
        poprzednia_suma += wielokaty[i].nagroda;
    }
    cout << max_zysk;
    return 0;
}