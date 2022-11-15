#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, a_i = 0, b_i = 0;
long long wyn = 0;
vector<vector<bool>> czy_jest_krawedz;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i <= n; ++i)
    {
        czy_jest_krawedz.push_back({});
        for (int j = 0; j <= n; ++j)
        {
            czy_jest_krawedz[i].push_back(false);
        }
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        czy_jest_krawedz[a_i][b_i] = true;
        czy_jest_krawedz[b_i][a_i] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i+1; j <= n; ++j)
        {
            if (czy_jest_krawedz[i][j] == true)
            {
                continue;
            }
            for (int k = j+1; k <= n; ++k)
            {
                if (czy_jest_krawedz[i][k] == false && czy_jest_krawedz[j][k] == false)
                {
                    wyn++;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i+1; j <= n; ++j)
        {
            if (czy_jest_krawedz[i][j] == false)
            {
                continue;
            }
            for (int k = j+1; k <= n; ++k)
            {
                if (czy_jest_krawedz[i][k] == true && czy_jest_krawedz[j][k] == true)
                {
                    wyn++;
                }
            }
        }
    }

    cout << wyn << '\n';

    return 0;
}
