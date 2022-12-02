#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Krawedz
{
    long long do_kogo;
    long long cena;
};

struct Element_kojeki
{
    long long numer_wierzcholka;
    long long cena;
};

long long n = 0, k = 0, wczytany_numer_nowego_zamku = 0, wczytane_a = 0, wczytane_b = 0, wczytane_cena = 0, wynik = 0;

vector<vector<Krawedz>> krawedzie;
vector<bool> czy_jest_zamek;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    krawedzie.assign(n+1, {});
    czy_jest_zamek.assign(n+1,false);
    czy_jest_zamek[1] = true;

    for (int i = 0; i < n-1; ++i)
    {
        cin >> wczytane_a >> wczytane_b >> wczytane_cena;
        krawedzie[wczytane_a].push_back({wczytane_b,wczytane_cena});
        krawedzie[wczytane_b].push_back({wczytane_a,wczytane_cena});
    }

    for (int z = 0; z < k; ++z)
    {
        cin >> wczytany_numer_nowego_zamku;
        czy_jest_zamek[wczytany_numer_nowego_zamku] = true;

        bool czy_sprawdzalismy[n+1];
        for (int j = 0; j <= n; ++j)
        {
            czy_sprawdzalismy[j] = false;
        }
        czy_sprawdzalismy[wczytany_numer_nowego_zamku] = true;
        queue<Element_kojeki> Q;
        Q.push({wczytany_numer_nowego_zamku,0});

        while (!Q.empty())
        {
            Element_kojeki spr = Q.front();
            if (czy_jest_zamek[spr.numer_wierzcholka] == true)
            {
                wynik += spr.cena;
            }

            for (int i = 0; i < krawedzie[spr.numer_wierzcholka].size(); ++i)
            {
                if (czy_sprawdzalismy[krawedzie[spr.numer_wierzcholka][i].do_kogo] == false)
                {
                    Q.push({krawedzie[spr.numer_wierzcholka][i].do_kogo,spr.cena + krawedzie[spr.numer_wierzcholka][i].cena});
                    czy_sprawdzalismy[krawedzie[spr.numer_wierzcholka][i].do_kogo] = true;
                }
            }
            Q.pop();
        }
        cout << wynik * 2<< "\n";
    }

    return 0;
}