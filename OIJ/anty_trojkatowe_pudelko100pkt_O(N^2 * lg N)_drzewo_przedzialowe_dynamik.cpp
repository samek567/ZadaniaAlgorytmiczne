#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int n = 0, m = 0, wczytana_liczba = 0;
const int base = 2048, rozmiar_drzewa = 4096; // Base, to potega dwojki >= max(M), a max(M) = 1500, wiec najblizsza potega dwojki to 2048.
ll wyn = 0;
vector<int> liczby;
ll dp[1501][1501]; // 1501, bo max M to 1500.
ll drzewo_przedzialowe[1501][rozmiar_drzewa]; // 1501, bo max M to 1500.

inline void update(int x, int v, ll val)
{
    v += base;
    drzewo_przedzialowe[x][v] = val;
    v /= 2;
    while(v > 0)
    {
        drzewo_przedzialowe[x][v] = drzewo_przedzialowe[x][v*2] + drzewo_przedzialowe[x][v*2+1];
        v /= 2;
    }
}

inline ll querry(int x, int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    ll res = 0;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res += drzewo_przedzialowe[x][l+1];
        if (p % 2 == 1)
            res += drzewo_przedzialowe[x][p-1];
        l /= 2;
        p /= 2;
    }
    return res;
}

int main()
{
    // O(N^2 * lg N)
    // Ulepszenie rozwiazania w O(N^3), za pomoca drzewa przedzialowego punkt - przedzial.
    // dp[i][j], ile jest pudelek antytrojkatowych, gdzie najwiekszy bok ma dlugosc i, a drugi najwiekszy bok dlugosc j.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int stat[m+1] = {0};
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        stat[wczytana_liczba]++;
    }

    for (int i = 1; i <= m; ++i)
    {
        if (stat[i] != 0)
        {
            wyn++;
            for (int j = 0; j < min(stat[i],2); ++j)
                liczby.push_back(i);
        }
    }

    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j)
            dp[i][j] = 0;

    for (int i = 0; i <= m; ++i)
        for (int j = 0; j < rozmiar_drzewa; ++j)
            drzewo_przedzialowe[i][j] = 0;

    dp[liczby[1]][liczby[0]] = 1;
    update(liczby[1],liczby[0],1);

    for (int i = 2; i < liczby.size(); ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            int L_I = liczby[i], L_J = liczby[j];
            if (dp[L_I][L_J] == 0)
            {
                ll val = 1 + querry(L_J,0,L_I - L_J);
                update(L_I, L_J, val);
                dp[L_I][L_J] = val;
            }
        }
    }

    for (int i = 1; i <= m; ++i)
        for (int j = i; j >= 1; --j)
            wyn += dp[i][j];

    cout << wyn << '\n';

    return 0;
}
