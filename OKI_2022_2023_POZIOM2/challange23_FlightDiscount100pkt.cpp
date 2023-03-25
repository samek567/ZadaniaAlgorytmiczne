#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;

struct Element_seta
{
    ll wartosc;
    int wierzcholek;
    bool czy_przeszlismy_taniej;
    bool operator < (const Element_seta &element_seta) const
    {
        if (wartosc == element_seta.wartosc)
        {
            if (wierzcholek == element_seta.wierzcholek)
                return czy_przeszlismy_taniej < element_seta.czy_przeszlismy_taniej;
            return wierzcholek < element_seta.wierzcholek;
        }
        return wartosc > element_seta.wartosc;
    }
};

struct Krawedz
{
    int wierzcholek;
    int cena;
};

int n = 0, m = 0, a = 0, b = 0, c = 0;
vector<vector<Krawedz>> krawedzie;
priority_queue<Element_seta> S;
vector<ll> dp_z_przejsciem_taniej;
vector<ll> dp_bez_przejscia_taniej;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    krawedzie.assign(n+1,{});
    dp_z_przejsciem_taniej.assign(n+1, 1e18);
    dp_bez_przejscia_taniej.assign(n+1, 1e18);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        krawedzie[a].push_back({b,c});
    }

    S.push({0,1,false});
    dp_bez_przejscia_taniej[1] = 0;

    while(!S.empty())
    {
        Element_seta spr = S.top();
        S.pop();
        if (spr.wierzcholek == n)
        {
            cout << spr.wartosc << '\n';
            return 0;
        }
        if (spr.czy_przeszlismy_taniej == true and dp_z_przejsciem_taniej[spr.wierzcholek] < spr.wartosc)
            continue;
        if (spr.czy_przeszlismy_taniej == false and dp_bez_przejscia_taniej[spr.wierzcholek] < spr.wartosc)
            continue;
        if (spr.czy_przeszlismy_taniej == true)
        {
            for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
            {
                int wierz = krawedzie[spr.wierzcholek][i].wierzcholek;
                if (spr.wartosc + (ll)krawedzie[spr.wierzcholek][i].cena < dp_z_przejsciem_taniej[wierz])
                {
                    dp_z_przejsciem_taniej[wierz] = spr.wartosc + (ll)krawedzie[spr.wierzcholek][i].cena;
                    S.push({spr.wartosc + (ll)krawedzie[spr.wierzcholek][i].cena, wierz,true});
                }
            }
        }
        else
        {
            for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
            {
                int wierz = krawedzie[spr.wierzcholek][i].wierzcholek;
                if (spr.wartosc + (ll)krawedzie[spr.wierzcholek][i].cena < dp_bez_przejscia_taniej[wierz])
                {
                    dp_bez_przejscia_taniej[wierz] = spr.wartosc + (ll)krawedzie[spr.wierzcholek][i].cena;
                    S.push({spr.wartosc + (ll)krawedzie[spr.wierzcholek][i].cena, wierz,false});
                }
            }
            for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
            {
                int wierz = krawedzie[spr.wierzcholek][i].wierzcholek;
                if (spr.wartosc + (ll)krawedzie[spr.wierzcholek][i].cena / 2 < dp_z_przejsciem_taniej[wierz])
                {
                    dp_z_przejsciem_taniej[wierz] = spr.wartosc + (ll)krawedzie[spr.wierzcholek][i].cena / 2;
                    S.push({spr.wartosc + (ll)krawedzie[spr.wierzcholek][i].cena / 2, wierz,true});
                }
            }
        }
    }

    return 0;
}