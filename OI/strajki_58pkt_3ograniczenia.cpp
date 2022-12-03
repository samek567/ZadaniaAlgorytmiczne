#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, z = 0, a = 0, b = 0, wynik = 0, bilans_strajkow = 0;
vector<vector<int>> krawedzie;
vector<int> ile_sasiadow_ma_strajk;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    krawedzie.assign(n+1,{});
    ile_sasiadow_ma_strajk.assign(n+1,0);

    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    cin >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> z;
        if (bilans_strajkow == 0)
            wynik = 1;

        if (z > 0)
        {
            bilans_strajkow++;
            wynik += krawedzie[z].size()-ile_sasiadow_ma_strajk[z]-1;
            for (int j = 0; j < krawedzie[z].size(); ++j)
                ile_sasiadow_ma_strajk[krawedzie[z][j]]++;
        }
        else
        {
            bilans_strajkow--;
            z *= -1;
            wynik -= krawedzie[z].size() - ile_sasiadow_ma_strajk[z]-1;

            for (int j = 0; j < krawedzie[z].size(); ++j)
                ile_sasiadow_ma_strajk[krawedzie[z][j]]--;
        }

        printf("%d \n",wynik);
    }

    return 0;
}
