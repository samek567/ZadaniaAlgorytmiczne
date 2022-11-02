#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long n = 0, q = 0, rozmiar_drzewa = 0, base = 0, wczytana_liczba = 0, a = 0, b = 0, CONST_MAX = 10e16;
vector<long long> drzewo_przedzialowe;

int queryy(int l_zap, int p_zap)
{
    int l = l_zap - 1;
    int p = p_zap + 1;
    long long wyn = CONST_MAX;

    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
        {
            wyn = min(wyn,drzewo_przedzialowe[l+1]);
        }
        if (p % 2 == 1)
        {
            wyn = min(wyn,drzewo_przedzialowe[p-1]);
        }
        l /= 2;
        p /= 2;
    }

    return wyn;
}

int main()
{
    // Zadanie Range Minimum Querry z SPOJ-a
    // O(q * log n)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    // Wierzcholki numerujemy od 1 do 2^n - 1, zeby miec latwy dostep do synow kolejno: x * 2, x * 2 + 1
    rozmiar_drzewa = pow(2,ceil(log2(n))) * 2;
    base = rozmiar_drzewa / 2;
    drzewo_przedzialowe.assign(rozmiar_drzewa,0);


    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        drzewo_przedzialowe[base + i] = wczytana_liczba;
    }
    for (int i = base-1; i > 0; --i)
    {
        drzewo_przedzialowe[i] = min(drzewo_przedzialowe[i * 2], drzewo_przedzialowe[i * 2 + 1]);
    }

    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        cin >> a >> b;
        cout << queryy(base+a,base+b) << "\n";
    }

    return 0;
}
