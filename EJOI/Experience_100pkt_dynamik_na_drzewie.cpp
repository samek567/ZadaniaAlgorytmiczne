#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int n = 0, a = 0, b = 0;
ll wyn = 0, maxx = 0, minn = 0;
vector<int> moce;
vector<vector<int>> krawedzie;
vector<int> porzadek_topologiczny;
queue<int> Q;
vector<bool> czy_bylismy;
vector<int> parent;
vector<ll> dp_rosnace;
vector<ll> dp_malejace;

int main()
{
    // Zauwazamy, ze kazda grupa bedzie albo caly czas malejaca, albo caly czas rosnaca.
    // Robimy dynamika na drzewie.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    krawedzie.assign(n+1,{});
    czy_bylismy.assign(n+1,false);
    moce.assign(n+1,-1);
    parent.assign(n+1,-1);
    dp_rosnace.assign(n+1,0);
    dp_malejace.assign(n+1,0);

    for (int i = 1; i <= n; ++i)
        cin >> moce[i];

    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    Q.push(1);
    czy_bylismy[1] = true;
    porzadek_topologiczny.push_back(1);

    while(!Q.empty())
    {
        int spr = Q.front();
        Q.pop();
        for (int i = 0; i < krawedzie[spr].size(); ++i)
        {
            int wierz = krawedzie[spr][i];
            if (czy_bylismy[wierz] == false)
            {
                parent[wierz] = spr;
                Q.push(wierz);
                porzadek_topologiczny.push_back(wierz);
                czy_bylismy[wierz] = true;
            }
        }
    }

    for (int i = n-1; i >= 0; --i)
    {
        int wierz = porzadek_topologiczny[i];

        ll suma_dp = 0;
        for (int i = 0; i < krawedzie[wierz].size(); ++i)
            suma_dp += max(dp_malejace[krawedzie[wierz][i]], dp_rosnace[krawedzie[wierz][i]]);
        dp_malejace[wierz] = suma_dp;
        dp_rosnace[wierz] = suma_dp;

        ll max_val = dp_rosnace[wierz];
        for (int i = 0; i < krawedzie[wierz].size(); ++i)
        {
            int spr = krawedzie[wierz][i];
            if (spr == parent[wierz])
                continue;
            if (moce[wierz] < moce[spr])
                max_val = max(max_val,dp_rosnace[wierz] - max(dp_rosnace[spr], dp_malejace[spr]) + dp_rosnace[spr] + (moce[spr] - moce[wierz]));
        }
        dp_rosnace[wierz] = max_val;

        max_val = dp_malejace[wierz];
        for (int i = 0; i < krawedzie[wierz].size(); ++i)
        {
            int spr = krawedzie[wierz][i];
            if (spr == parent[wierz])
                continue;
            if (moce[wierz] > moce[spr])
                max_val = max(max_val,dp_malejace[wierz] - max(dp_rosnace[spr], dp_malejace[spr]) + dp_malejace[spr] + (moce[wierz] - moce[spr]));
        }
        dp_malejace[wierz] = max_val;
    }

    cout << max(dp_malejace[1], dp_rosnace[1]) << '\n';

    return 0;
}