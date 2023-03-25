#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, q = 0, wczytana_liczba = 0, min_y = 0, min_x = 0, max_y = 0, max_x = 0, ile_zer = 0, ile_minus_jedynek = 0;
vector<vector<int>> sumy_prefiksowe_zera;
vector<vector<int>> sumy_prefiksowe_minus_jedynki;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
    {
        sumy_prefiksowe_zera.push_back({});
        sumy_prefiksowe_minus_jedynki.push_back({});
        for (int j = 0; j <= m; ++j)
        {
            sumy_prefiksowe_zera[i].push_back(0);
            sumy_prefiksowe_minus_jedynki[i].push_back(0);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> wczytana_liczba;
            sumy_prefiksowe_zera[i][j] = sumy_prefiksowe_zera[i-1][j] + sumy_prefiksowe_zera[i][j-1] - sumy_prefiksowe_zera[i-1][j-1];
            if (wczytana_liczba == 0)
                sumy_prefiksowe_zera[i][j]++;

            sumy_prefiksowe_minus_jedynki[i][j] = sumy_prefiksowe_minus_jedynki[i-1][j] + sumy_prefiksowe_minus_jedynki[i][j-1] - sumy_prefiksowe_minus_jedynki[i-1][j-1];
            if (wczytana_liczba < 0)
                sumy_prefiksowe_minus_jedynki[i][j]++;
        }
    }

    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> min_y >> min_x >> max_y >> max_x;
        ile_zer = sumy_prefiksowe_zera[max_y][max_x] - sumy_prefiksowe_zera[max_y][min_x-1] - sumy_prefiksowe_zera[min_y-1][max_x] + sumy_prefiksowe_zera[min_y-1][min_x-1];
        ile_minus_jedynek = sumy_prefiksowe_minus_jedynki[max_y][max_x] - sumy_prefiksowe_minus_jedynki[max_y][min_x-1] - sumy_prefiksowe_minus_jedynki[min_y-1][max_x] + sumy_prefiksowe_minus_jedynki[min_y-1][min_x-1];
        if (ile_zer > 0)
            printf("0\n");
        else if (ile_minus_jedynek % 2 == 0)
            printf("1\n");
        else
            printf("-1\n");
    }
    return 0;
}