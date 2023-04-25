#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <iomanip>

using namespace std;
typedef long double ld;
typedef long long ll;

ll y_poczatkowy = 0, x_poczatkowy = 0;

struct Punkt
{
    ll y;
    ll x;
    ll idx;
    bool operator < (const Punkt &inny) const
    {
        if ((y - y_poczatkowy) * (inny.x - x_poczatkowy) == (inny.y - y_poczatkowy) * (x - x_poczatkowy))
            return (y - y_poczatkowy) * (y - y_poczatkowy) + (x - x_poczatkowy) * (x - x_poczatkowy) < (inny.y - y_poczatkowy) * (inny.y - y_poczatkowy) + (inny.x - x_poczatkowy) * (inny.x - x_poczatkowy);
        return (y - y_poczatkowy) * (inny.x - x_poczatkowy) < (inny.y - y_poczatkowy) * (x - x_poczatkowy);
    }
};

struct Element_seta
{
    ll y;
    ll x;
    ll idx;
    bool operator < (const Element_seta &element_seta) const
    {
        if (y == element_seta.y)
            return x < element_seta.x;
        return y < element_seta.y;
    }
};

int k = 0;
ll n = 0;
ll iloczyn_vectorowy = 0;
ld wyn = 0;
vector<Punkt> punkty;
vector<Punkt> dod;
vector<Punkt> otoczka_wypukla;
Punkt poczatkowy = {1000000000000,1000000000000,-1};
set<Element_seta> S;

inline ll iloczyn_vect(Punkt p1, Punkt p2, Punkt p3)
{
    p2.x -= p1.x, p3.x -= p1.x, p2.y -= p1.y, p3.y -= p1.y;
    return p2.x * p3.y - p3.x * p2.y;
}

inline ll iloczyn_skal(Punkt p1, Punkt p2, Punkt p3)
{
    p2.x -= p1.x, p3.x -= p1.x, p2.y -= p1.y, p3.y -= p1.y;
    return p2.x * p3.x + p2.y * p3.y;
}

int main()
{
    // Sortowanie katowe za pomoca iloczynu wektorowego, iloczyn skalarny, otoczka wypukla z algorytmem Grahama, spoko zadanko.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    while(k--)
    {
        cin >> n;
        punkty.assign(n,{});
        dod.clear(), iloczyn_vectorowy = 0, S.clear(), otoczka_wypukla.clear(), poczatkowy = {1000000000000,1000000000000,-1}, wyn = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> punkty[i].x >> punkty[i].y;
            punkty[i].idx = i;
            auto it = S.find({punkty[i].y, punkty[i].x});
            if (it == S.end())
                S.insert({punkty[i].y, punkty[i].x,i});
        }

        for (auto it = S.begin(); it != S.end(); ++it)
            dod.push_back({it->y, it->x, it->idx});

        punkty = dod;
        for (int i = 0; i < punkty.size(); ++i)
        {
            if (punkty[i].y < poczatkowy.y)
                poczatkowy = punkty[i];
            else if (punkty[i].y == poczatkowy.y and punkty[i].x < poczatkowy.x)
                poczatkowy = punkty[i];
        }
        y_poczatkowy = poczatkowy.y, x_poczatkowy = poczatkowy.x;

        dod.clear();
        for (int i = 0; i < punkty.size(); ++i)
            if (punkty[i].idx != poczatkowy.idx)
                dod.push_back(punkty[i]);
        punkty = dod;
        sort(punkty.begin(), punkty.end());

        for (int i = 0; i < punkty.size(); ++i)
            punkty[i].y -= y_poczatkowy, punkty[i].x -= x_poczatkowy;

        poczatkowy.y = 0, poczatkowy.x = 0;
        otoczka_wypukla.push_back(poczatkowy);
        for (int i = 0; i < punkty.size(); ++i)
        {
            if (otoczka_wypukla.size() <= 1)
                otoczka_wypukla.push_back(punkty[i]);
            else
            {
                while(otoczka_wypukla.size() >= 2)
                {
                    iloczyn_vectorowy = iloczyn_vect(otoczka_wypukla[otoczka_wypukla.size()-2],otoczka_wypukla[otoczka_wypukla.size()-1],punkty[i]);
                    if (iloczyn_vectorowy <= 0)
                        otoczka_wypukla.pop_back();
                    else
                        break;
                }
                otoczka_wypukla.push_back(punkty[i]);
            }
        }

        for (int i = 0; i < otoczka_wypukla.size(); ++i)
        {
            int idx = 0;
            if (i == otoczka_wypukla.size()-1)
                idx = 0;
            else
                idx = i+1;
            ld odl = (ld)sqrt((otoczka_wypukla[i].y - otoczka_wypukla[idx].y) * (otoczka_wypukla[i].y - otoczka_wypukla[idx].y) + (otoczka_wypukla[i].x - otoczka_wypukla[idx].x) * (otoczka_wypukla[i].x - otoczka_wypukla[idx].x));
            wyn += odl;
        }

        cout << fixed << setprecision(2) << wyn << '\n';
        for (int i = 0; i < otoczka_wypukla.size(); ++i)
            cout << otoczka_wypukla[i].idx + 1 << ' ';
        cout << '\n';
    }
    return 0;
}