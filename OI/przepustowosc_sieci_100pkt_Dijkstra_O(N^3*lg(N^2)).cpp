#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Element_seta
{
    int wierzcholek;
    int koszt;
    bool operator < (const Element_seta &element_seta) const
    {
        if (koszt == element_seta.koszt)
            return wierzcholek < element_seta.wierzcholek;
        return koszt > element_seta.koszt;
    }
};

struct Krawedz
{
    int do_kogo;
    int koszt;
};

int n = 0, q = 0, a = 0, b = 0;
vector<vector<Krawedz>> krawedzie;
vector<vector<int>> wyn;
set<Element_seta> S;

int main()
{
    // O(N^3 * lg(N^2)), algorytm Dijkstry. Pewnie mozna troche szybciej na kolejce priorytetowej zamiast seta.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    krawedzie.assign(n+1,{});
    wyn.assign(n+1,{});
    for (int i = 1; i <= n; ++i)
        wyn[i].assign(n+1,0);

    for (int i = 1; i <= n; ++i)
    {
        cin >> q;
        while(q--)
        {
            cin >> a >> b;
            krawedzie[i].push_back({a,b});
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        S.clear();
        S.insert({i,1000000005});
        while(!S.empty())
        {
            Element_seta spr = *S.begin();
            S.erase(spr);
            for (int j = 0; j < krawedzie[spr.wierzcholek].size(); ++j)
            {
                int wierz = krawedzie[spr.wierzcholek][j].do_kogo, minn = min(spr.koszt, krawedzie[spr.wierzcholek][j].koszt);
                if (wyn[i][wierz] == 0 or minn > wyn[i][wierz])
                {
                    auto it = S.find({wierz, wyn[i][wierz]});
                    if (it != S.end())
                        S.erase(*it);
                    wyn[i][wierz] = minn;
                    S.insert({wierz, wyn[i][wierz]});
                }
            }
        }
    }

    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        cout << wyn[a][b] << '\n';
    }

    return 0;
}
