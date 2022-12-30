#include <iostream>
#include <vector>

using namespace std;

struct Element
{
    int wartosc;
    int kolor;
};

int n = 0, wczytana_liczba = 0, wyn = 0;
Element max_1_parzyste = {0,0}, max_2_parzyste = {0,0}, max_1_nieparzyste = {0,0}, max_2_nieparzyste = {0,0};
vector<int> stat_parzyste;
vector<int> stat_nieparzyste;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    stat_nieparzyste.assign(n+1,0);
    stat_parzyste.assign(n+1,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (i % 2 == 0)
            stat_parzyste[wczytana_liczba]++;
        else
            stat_nieparzyste[wczytana_liczba]++;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (max_1_parzyste.wartosc == -1)
        {
            max_1_parzyste = {stat_parzyste[i], i};
            max_2_parzyste = {stat_parzyste[i], i};
        }
        else if (stat_parzyste[i] > max_1_parzyste.wartosc)
        {
            if (max_1_parzyste.wartosc > max_2_parzyste.wartosc)
            {
                max_2_parzyste = max_1_parzyste;
            }
            max_1_parzyste = {stat_parzyste[i],i};
        }
        else if (stat_parzyste[i] > max_2_parzyste.wartosc)
        {
            max_2_parzyste = {stat_parzyste[i], i};
        }

        if (max_1_nieparzyste.wartosc == -1)
        {
            max_1_nieparzyste = {stat_nieparzyste[i], i};
            max_2_nieparzyste = {stat_nieparzyste[i], i};
        }
        else if (stat_nieparzyste[i] > max_1_nieparzyste.wartosc)
        {
            if (max_1_nieparzyste.wartosc > max_2_nieparzyste.wartosc)
            {
                max_2_nieparzyste = max_1_nieparzyste;
            }
            max_1_nieparzyste = {stat_nieparzyste[i],i};
        }
        else if (stat_nieparzyste[i] > max_2_nieparzyste.wartosc)
        {
            max_2_nieparzyste = {stat_nieparzyste[i], i};
        }
    }
    if (max_1_parzyste.kolor == max_1_nieparzyste.kolor)
    {
        wyn = max(max_1_parzyste.wartosc + max_2_nieparzyste.wartosc, max_1_nieparzyste.wartosc + max_2_parzyste.wartosc);
    }
    else
        wyn = max_1_parzyste.wartosc + max_1_nieparzyste.wartosc;

    printf("%d",n - wyn);

    return 0;
}
