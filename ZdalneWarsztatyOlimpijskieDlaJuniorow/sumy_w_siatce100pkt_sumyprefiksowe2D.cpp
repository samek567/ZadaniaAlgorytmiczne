#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, q = 0, p_y = 0, p_x = 0, k_y = 0, k_x = 0, wczytana_liczba = 0;
vector<vector<long long>> sumy_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
    {
        sumy_prefiksowe.push_back({});
        for (int j = 0; j <= m; ++j)
            sumy_prefiksowe[i].push_back(0);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> wczytana_liczba;
            sumy_prefiksowe[i][j] = sumy_prefiksowe[i-1][j] + sumy_prefiksowe[i][j-1] - sumy_prefiksowe[i-1][j-1] + wczytana_liczba;
        }
    }
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> p_y >> p_x >> k_y >> k_x;
        printf("%d\n",sumy_prefiksowe[k_y][k_x] - sumy_prefiksowe[k_y][p_x-1] - sumy_prefiksowe[p_y-1][k_x] + sumy_prefiksowe[p_y-1][p_x-1]);
    }
    return 0;
}