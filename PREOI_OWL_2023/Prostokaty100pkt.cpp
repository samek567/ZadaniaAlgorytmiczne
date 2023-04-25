#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

struct Element_seta
{
    ll dlugosc;
    int srodek_y;
    int srodek_x;
    mutable ll ile;
    bool operator < (const Element_seta &element_seta) const
    {
        if (dlugosc == element_seta.dlugosc)
        {
            if (srodek_x == element_seta.srodek_x)
                return srodek_y < element_seta.srodek_y;
            return srodek_x < element_seta.srodek_x;
        }
        return dlugosc < element_seta.dlugosc;
    }
};

struct Punkt
{
    int y;
    int x;
};

int n = 0, x = 0, y = 0, srod_y = 0, srod_x = 0, wyn = 0;
ll dl = 0;
vector<Punkt> punkty;
set<Element_seta> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    punkty.assign(n,{});
    for (int i = 0; i < n; ++i)
        cin >> punkty[i].x >> punkty[i].y;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            dl = (punkty[i].x - punkty[j].x) * (punkty[i].x - punkty[j].x) + (punkty[i].y - punkty[j].y) * (punkty[i].y - punkty[j].y);
            srod_y = (punkty[i].y + punkty[j].y);
            srod_x = (punkty[i].x + punkty[j].x);
            auto it = S.find({dl, srod_y, srod_x});
            if (it != S.end())
                it->ile++;
            else
                S.insert({dl, srod_y, srod_x,1});
        }
    }

    for (auto it = S.begin(); it != S.end(); ++it)
        if (it->ile != 1)
            wyn += (it->ile - 1) * it->ile / 2;

    cout << wyn << '\n';

    return 0;
}