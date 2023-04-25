#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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

ll n = 0;
ll iloczyn_vectorowy = 0;
vector<Punkt> punkty;
vector<Punkt> dod;
vector<Punkt> otoczka_wypukla;
Punkt poczatkowy = {1000000000000,1000000000000,-1};
vector<ll> wyn_vect;

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    punkty.assign(n,{});
    for (int i = 0; i < n; ++i)
    {
        cin >> punkty[i].x >> punkty[i].y;
        punkty[i].idx = i;
    }

    for (int i = 0; i < punkty.size(); ++i)
    {
        if (punkty[i].y < poczatkowy.y)
            poczatkowy = punkty[i];
        else if (punkty[i].y == poczatkowy.y and punkty[i].x < poczatkowy.x)
            poczatkowy = punkty[i];
    }
    y_poczatkowy = poczatkowy.y, x_poczatkowy = poczatkowy.x;

    for (int i = 0; i < n; ++i)
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

    if (otoczka_wypukla.size() <= 2)
    {
        cout << otoczka_wypukla.size() << '\n';
        for (int i = 0; i < otoczka_wypukla.size(); ++i)
            cout << otoczka_wypukla[i].idx + 1 << '\n';
        return 0;
    }

    for (int i = 0; i < otoczka_wypukla.size(); ++i)
    {
        int idx_dalej = 0, idx_wczesniej = 0;
        if (i == otoczka_wypukla.size()-1)
            idx_dalej = 0;
        else
            idx_dalej = i+1;
        if (i == 0)
            idx_wczesniej = otoczka_wypukla.size()-1;
        else
            idx_wczesniej = i-1;
        if (iloczyn_skal(otoczka_wypukla[i],otoczka_wypukla[idx_wczesniej],otoczka_wypukla[idx_dalej]) >= 0)
            wyn_vect.push_back(otoczka_wypukla[i].idx);
    }

    cout << wyn_vect.size() << '\n';
    sort(wyn_vect.begin(), wyn_vect.end());
    for (int i = 0; i < wyn_vect.size(); ++i)
        cout << wyn_vect[i] + 1 << '\n';

    return 0;
}