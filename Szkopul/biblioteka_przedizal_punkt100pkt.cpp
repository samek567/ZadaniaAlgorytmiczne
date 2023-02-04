#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n = 0, wczytana_liczba = 0, base = (1 << int(ceil(double(log2(400011))))), rozmiar_drzewa = base * 2, lewy_wsk = 200005, prawy_wsk = 200005;
char wczytany_znak;
vector<int> drzewo_przedzialowe;
vector<int> jaki_idx_w_drzewie_przedzialowym;

void update(int v, int val)
{
    v += base;
    drzewo_przedzialowe[v] = val;
    v /= 2;
    while(v > 0)
    {
        drzewo_przedzialowe[v] = drzewo_przedzialowe[v * 2] + drzewo_przedzialowe[v * 2 + 1];
        v /= 2;
    }
}

int querry(int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    int wyn_zap = 0;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            wyn_zap += drzewo_przedzialowe[l+1];
        if (p % 2 == 1)
            wyn_zap += drzewo_przedzialowe[p-1];
        l /= 2;
        p /= 2;
    }
    return wyn_zap;
}

int main()
{
    // O(N lg N)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    drzewo_przedzialowe.assign(rozmiar_drzewa,0);
    jaki_idx_w_drzewie_przedzialowym.assign(200001,-1);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak >> wczytana_liczba;
        if (wczytany_znak == 'L')
        {
            if (lewy_wsk == prawy_wsk && lewy_wsk == 200005)
                prawy_wsk++;
            update(lewy_wsk,1);
            jaki_idx_w_drzewie_przedzialowym[wczytana_liczba] = lewy_wsk;
            lewy_wsk--;
        }
        else if (wczytany_znak == 'R')
        {
            if (lewy_wsk == prawy_wsk && lewy_wsk == 200005)
                lewy_wsk--;
            update(prawy_wsk,1);
            jaki_idx_w_drzewie_przedzialowym[wczytana_liczba] = prawy_wsk;
            prawy_wsk++;
        }
        else
            cout << min(querry(1,jaki_idx_w_drzewie_przedzialowym[wczytana_liczba]),querry(jaki_idx_w_drzewie_przedzialowym[wczytana_liczba],400010)) - 1 << '\n';
    }
    return 0;
}
