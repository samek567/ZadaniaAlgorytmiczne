#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Zdarzenie
{
    int x;
    int wysokosc;
    int ile_dodajemy;
    bool operator < (const Zdarzenie &zdarzenie) const
    {
        if (x == zdarzenie.x)
            return ile_dodajemy > zdarzenie.ile_dodajemy;
        return x < zdarzenie.x;
    }
};

struct Deska_pionowa
{
    int y1;
    int y2;
    int x;
    bool operator < (const Deska_pionowa &deska_pionowa) const
    {
        return x < deska_pionowa.x;
    }
};

struct Deska_pozioma
{
    int x1;
    int x2;
    int y;
};

int n = 0, m = 0, a = 0, b = 0, c = 0, poczatek = 0, koniec = 0, srodek = 0, wsk = 0;
vector<Zdarzenie> zdarzenia_x;
vector<Deska_pionowa> deski_y;
vector<Deska_pozioma> deski_x;
set<int> S;
unordered_map<int,int> ile;

inline bool czy_pasuje(int x)
{
    zdarzenia_x.clear();
    S.clear();
    ile.clear();
    wsk = 0;
    for (int i = 0; i < n; ++i)
    {
        int szerokosc = deski_x[i].x2 - deski_x[i].x1;
        if (szerokosc < 2*x)
            continue;
        zdarzenia_x.push_back({deski_x[i].x1 + x, deski_x[i].y,+1});
        zdarzenia_x.push_back({deski_x[i].x2 - x, deski_x[i].y,-1});
    }
    sort(zdarzenia_x.begin(), zdarzenia_x.end());
    for (int i = 0; i < m; ++i)
    {
        while(wsk < zdarzenia_x.size())
        {
            if ((zdarzenia_x[wsk].x < deski_y[i].x) or (zdarzenia_x[wsk].x == deski_y[i].x and zdarzenia_x[wsk].ile_dodajemy == 1))
            {
                if (zdarzenia_x[wsk].ile_dodajemy == 1)
                {
                    if (auto it = ile.find(zdarzenia_x[wsk].wysokosc) == ile.end())
                        ile[zdarzenia_x[wsk].wysokosc] = 1;
                    else
                        ile[zdarzenia_x[wsk].wysokosc]++;
                    S.insert(zdarzenia_x[wsk].wysokosc);
                }
                else
                {
                    ile[zdarzenia_x[wsk].wysokosc]--;
                    if (ile[zdarzenia_x[wsk].wysokosc] == 0)
                        S.erase(zdarzenia_x[wsk].wysokosc);
                }
                wsk++;
            }
            else
                break;
        }
        if (deski_y[i].y2 - deski_y[i].y1 < 2*x)
            continue;
        auto it = S.lower_bound(deski_y[i].y2 - x);
        if (it != S.end() and *it == deski_y[i].y2 - x)
            return true;
        if (it == S.begin())
            continue;
        --it;
        if (*it >= deski_y[i].y1 + x and *it <= deski_y[i].y2 - x)
            return true;
    }
    return false;
}

int main()
{
    // Binary search + zamiatanie z setem, mozna by bylo klasyczne drzewo przedzialowe, gdy by nie to, ze wspolrzedne <= 10^9.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    deski_x.assign(n,{});
    for (int i = 0; i < n; ++i)
        cin >> deski_x[i].x1 >> deski_x[i].x2 >> deski_x[i].y;

    deski_y.assign(m,{});
    for (int i = 0; i < m; ++i)
        cin >> deski_y[i].y1 >> deski_y[i].y2 >> deski_y[i].x;

    sort(deski_y.begin(), deski_y.end());
    poczatek = 0, koniec = 1e9+5;
    while(koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_pasuje(srodek) == true)
            poczatek = srodek;
        else
            koniec = srodek;
    }

    cout << poczatek << '\n';

    return 0;
}