#include <iostream>
#include <vector>

using namespace std;

int n = 0, r = 0, wczytana_liczba = 0, min_x = 0, max_x = 0, min_y = 0, max_y = 0;
vector<vector<int>> sumy_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r;
    for (int i = 0; i <= n; ++i)
    {
        sumy_prefiksowe.push_back({});
        for (int j = 0; j <= n; ++j)
            sumy_prefiksowe[i].push_back(0);
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
            max_y = min(n,i+r);
            min_y = max(1,i-r);
            max_x = min(n,j+r);
            min_x = max(1,j-r);
            printf("%d ",sumy_prefiksowe[max_y][max_x] - sumy_prefiksowe[max_y][min_x-1] - sumy_prefiksowe[min_y-1][max_x] + sumy_prefiksowe[min_y-1][min_x-1]);
        }
        printf("\n");
    }
    return 0;
}