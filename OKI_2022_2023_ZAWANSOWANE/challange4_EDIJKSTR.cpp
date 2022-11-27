#include <iostream>
#include <vector>
#include <set>
#include <climits>

struct Element_seta
{
    long long cena;
    long long numer_wierzcholka;

    bool operator < (const Element_seta& element_seta) const
    {
        if (cena == element_seta.cena)
        {
            return numer_wierzcholka < element_seta.numer_wierzcholka;
        }
        return cena < element_seta.cena;
    }
};

struct Krawedz
{
    long long cena;
    long long numer_wierzcholka;
};

using namespace std;

int n = 0, a = 0, b = 0, ile_wierzcholkow = 0, ile_krawedzi = 0, a_wczytane = 0, b_wczytane = 0;
long long cena_wczytane = 0;
vector<vector<Krawedz>> krawedzie;
set<Element_seta> S;

long long dijkstraa(int &poczatek, int &koniec)
{
    vector<long long> odw;
    odw.assign(ile_wierzcholkow+1,LLONG_MAX);
    odw[poczatek] = 0;
    S.insert({0,poczatek});

    while (true)
    {
        Element_seta spr = *S.begin();
        S.erase(*S.begin());

        if (spr.numer_wierzcholka == koniec)
        {
            return spr.cena;
        }

        for (int i = 0; i < krawedzie[spr.numer_wierzcholka].size(); ++i)
        {
            if (spr.cena + krawedzie[spr.numer_wierzcholka][i].cena < odw[krawedzie[spr.numer_wierzcholka][i].numer_wierzcholka])
            {
                S.insert({spr.cena + krawedzie[spr.numer_wierzcholka][i].cena,krawedzie[spr.numer_wierzcholka][i].numer_wierzcholka});
                odw[krawedzie[spr.numer_wierzcholka][i].numer_wierzcholka] = spr.cena + krawedzie[spr.numer_wierzcholka][i].cena;
            }
        }
        if (S.empty())
        {
            return -1;
        }
    }
}

int main()
{
    // Challange 4 Implementacja Dijkstry

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int z = 0; z < n; ++z)
    {
        S.clear();
        krawedzie.clear();

        cin >> ile_wierzcholkow >> ile_krawedzi;

        krawedzie.assign(ile_wierzcholkow+1,{});
        for (int i = 0; i < ile_krawedzi; ++i)
        {
            cin >> a_wczytane >> b_wczytane >> cena_wczytane;
            krawedzie[a_wczytane].push_back({cena_wczytane,b_wczytane});
        }

        cin >> a >> b;

        long long wyn = dijkstraa(a,b);
        if (wyn == -1)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << wyn << '\n';
        }
    }

    return 0;
}
