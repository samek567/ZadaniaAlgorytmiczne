#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

int n = 0, base = 0, rozmiar_drzewa = 0;
long long wyn = 0;
string ciag1, ciag2;
vector<int> drzewo_przedzialowe;
unordered_map<char,vector<int>> stat; // Jaki znak na jakich idx-ach wystepuja.
unordered_map<char,int> wsk_stat; // Jaki znak, na jakim idx-ie jestesmy.

void update(int l, int p, int val)
{
    l = l + base - 1;
    p = p + base + 1;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            drzewo_przedzialowe[l+1] += val;
        if (p % 2 == 1)
            drzewo_przedzialowe[p-1] += val;
        l /= 2;
        p /= 2;
    }
}

int querry(int v)
{
    v += base;
    int wyn = 0;
    while (v > 0)
    {
        wyn += drzewo_przedzialowe[v];
        v /= 2;
    }
    return wyn;
}

int main()
{
    // O(n log n) Mozna przejsc z mapa na tablice i indeksowac od 0 do 27 i robic char - 48, ale to i tak bardzo nie przyspieszy, bo size mapa to maks 27.
    // Drzewa przedzialowe przedzial - punkt.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag1 >> ciag2;
    base = (1 << int(ceil((double)log2(n))));
    rozmiar_drzewa = base * 2;
    drzewo_przedzialowe.assign(rozmiar_drzewa,0);
    for (int i = 0; i < n; ++i)
        drzewo_przedzialowe[base + i] = i;
    for (char i = 'A'; i <= 'Z'; ++i)
    {
        wsk_stat.insert({i,0});
        stat.insert({i,{}});
    }
    for (int i = 0; i < n; ++i)
        stat[ciag1[i]].push_back(i);

    for (int i = 0; i < n; ++i)
    {
        wyn += querry(stat[ciag2[i]][wsk_stat[ciag2[i]]]) - i;
        update(0,stat[ciag2[i]][wsk_stat[ciag2[i]]],1);
        wsk_stat[ciag2[i]]++;
    }

    printf("%lld",wyn);

    return 0;
}
