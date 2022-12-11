#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long n = 0, a = 0, b = 0;
vector<vector<long long>> krawedzie;
vector<long long> wierzcholki = {1};

bool czy_pasuje(long long x)
{
    vector<long long>dp;
    vector<bool> czy_bylismy;
    dp.assign(n+1,x);
    czy_bylismy.assign(n+1,false);
    for (int i = n-1; i >= 0; --i)
    {
        czy_bylismy[wierzcholki[i]] = true;
        if (krawedzie[wierzcholki[i]].size() == 1 && wierzcholki[i] != 1)
        {
            dp[wierzcholki[i]] = 0;
        }
        for (int j = 0; j < krawedzie[wierzcholki[i]].size(); ++j)
        {
            if (czy_bylismy[krawedzie[wierzcholki[i]][j]] == false)
            {
                dp[krawedzie[wierzcholki[i]][j]] += min(dp[wierzcholki[i]],(long long)0) - 1;
            }
        }
    }
    if (dp[1] >= 0)
        return true;
    return false;
}

int main()
{
    // Cos w stylu Sortowania Topologicznego + Programowanie dynamiczne na drzewie + binary search.
    // dp[v] - tabela kosztu dla pod drzewa ukorzenionego w wierzcholku v.
    // Dlatego dp[v] = min(0,x), bo nie bierzemy dodatnich kosztów pod uwagę, bo krol moze tam nie isc a musimy wziąć najmniej korzystny przypadek!
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    krawedzie.assign(n+1,{});
    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    vector<bool> czy_odwiedzone;
    queue<long long> Q;
    czy_odwiedzone.assign(n+1, false);
    czy_odwiedzone[1] = true;
    Q.push(1);
    while (!Q.empty())
    {
        int spr = Q.front();
        for (int i = 0; i < krawedzie[spr].size(); ++i)
        {
            if (czy_odwiedzone[krawedzie[spr][i]] == false)
            {
                czy_odwiedzone[krawedzie[spr][i]] = true;
                wierzcholki.push_back(krawedzie[spr][i]);
                Q.push(krawedzie[spr][i]);
            }
        }
        Q.pop();
    }

    long long poczatek = -1;
    long long koniec = n+1;
    long long srodek = 0;
    while (koniec-poczatek > 1)
    {
        srodek = (poczatek+koniec) / 2;
        if (czy_pasuje(srodek) == true)
            koniec = srodek;
        else
            poczatek = srodek;
    }
    printf("%lld",koniec);

    return 0;
}