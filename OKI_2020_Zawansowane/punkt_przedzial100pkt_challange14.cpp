#include <iostream>
#include <vector>

using namespace std;

int q = 0, a = 0, b = 0, c = 0, base = (1 << 18), rozmiar_drzewa = base * 2;
vector<int> drzewo_przedzialowe(rozmiar_drzewa,0);

int querry(int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    int wyn = 0;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            wyn = max(wyn,drzewo_przedzialowe[l+1]);
        if (p % 2 == 1)
            wyn = max(wyn,drzewo_przedzialowe[p-1]);
        l /= 2;
        p /= 2;
    }
    return wyn;
}

void update(int v, int val)
{
    v += base;
    drzewo_przedzialowe[v] = val;
    v /= 2;
    while(v > 0)
    {
        drzewo_przedzialowe[v] = max(drzewo_przedzialowe[v * 2], drzewo_przedzialowe[v * 2 + 1]);
        v /= 2;
    }
}
int main()
{
    // O(N lg N) - zaimplementuj drzewo punkt - przedzial
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--)
    {
        cin >> a >> b >> c;
        if (a == 0)
            update(b,c);
        else
            cout << querry(b,c) << '\n';
    }

    return 0;
}