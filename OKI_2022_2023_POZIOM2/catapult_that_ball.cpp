#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n = 0, m = 0, a = 0, b = 0, a_zap = 0, b_zap = 0, wynik = 0;
long long rozmiar_drzewa = 0, base = 0, wczytana_liczba = 0;
vector<long long> drzewo_przedzialowe;

long long querry(int l_zap, int p_zap)
{
    long long wyn = 0;
    int l = l_zap - 1;
    int p = p_zap + 1;

    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
        {
            wyn = max(wyn,drzewo_przedzialowe[l + 1]);
        }
        if (p % 2 == 1)
        {
            wyn = max(wyn,drzewo_przedzialowe[p - 1]);
        }
        l /= 2;
        p /= 2;
    }

    return wyn;
}

int main()
{
    // Zadanie Catapult That Ball z SPOJ-a.
    // O(m * log n)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    rozmiar_drzewa = pow(2,ceil(log2(n))) * 2;
    base = rozmiar_drzewa / 2;
    drzewo_przedzialowe.assign(rozmiar_drzewa,0);

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        drzewo_przedzialowe[base+i] = wczytana_liczba;
    }
    for (int i = base-1; i > 0; --i)
    {
        drzewo_przedzialowe[i] = max(drzewo_przedzialowe[i * 2], drzewo_przedzialowe[i * 2 + 1]);
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        a_zap = min(a,b);
        b_zap = max(a,b);
        if (drzewo_przedzialowe[base + a - 1] >= querry(base + a_zap,base + b_zap - 2)) // Chcemy miec maksa pomiedzy a i b nie wliczajac a i b.
        {
            wynik++;
        }
    }

    cout << wynik << "\n";

    return 0;
}
