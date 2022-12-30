#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, a_i = 0, b_i = 0;
vector<int> liczby;
vector<vector<int>> sumy_prefiksowe;

int main()
{
    /*
    Sumy prefiksowe.
    O(n+m)
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    sumy_prefiksowe.push_back({});
    for (int i = 1; i <= 5; ++i)
    {
        sumy_prefiksowe.push_back({});
        sumy_prefiksowe[i].push_back(0);
        for (int j = 0; j < n; ++j)
        {
            if (liczby[j] == i)
                sumy_prefiksowe[i].push_back(sumy_prefiksowe[i][j] + 1);
            else
                sumy_prefiksowe[i].push_back(sumy_prefiksowe[i][j]);
        }
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        for (int j = 1; j <= 5; ++j)
        {
            if (sumy_prefiksowe[j][b_i] - sumy_prefiksowe[j][a_i-1] > 0)
            {
                printf("%d \n",j);
                break;
            }
        }
    }
    return 0;
}
