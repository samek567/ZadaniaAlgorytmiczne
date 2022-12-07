#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, wczytana_liczba = 0, y1 = 0, y2 = 0, x1 = 0, x2 = 0;
vector<vector<int>> sumy_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i <= n; ++i)
    {
        sumy_prefiksowe.push_back({});
        for (int j = 0; j <= n; ++j)
        {
            sumy_prefiksowe[i].push_back(0);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> wczytana_liczba;
            sumy_prefiksowe[i][j] = sumy_prefiksowe[i-1][j] + sumy_prefiksowe[i][j-1] - sumy_prefiksowe[i-1][j-1] + wczytana_liczba;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            y1 = i-k;
            x1 = j-k;
            y2 = i+k;
            x2 = j+k;
            if (y1 < 1)
                y1 = 1;
            if (x1 < 1)
                x1 = 1;
            if (y2 > n)
                y2 = n;
            if (x2 > n)
                x2 = n;

            printf("%d ", sumy_prefiksowe[y2][x2] - sumy_prefiksowe[y2][x1-1] - sumy_prefiksowe[y1-1][x2] + sumy_prefiksowe[y1-1][x1-1]);
        }
        printf("\n");
    }
    return 0;
}
