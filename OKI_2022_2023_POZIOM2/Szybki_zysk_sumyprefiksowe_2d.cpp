#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, q = 0, wczytana_liczba = 0;
vector<vector<int>> liczby;
vector<vector<int>> ile_zer;
vector<vector<int>> ile_ujemnych;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i <= n; ++i)
    {
        liczby.push_back({});
        ile_zer.push_back({});
        ile_ujemnych.push_back({});
        for (int j = 0; j <= m; ++j)
        {
            liczby[i].push_back(0);
            ile_zer[i].push_back(0);
            ile_ujemnych[i].push_back(0);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> wczytana_liczba;
            if (wczytana_liczba == 0)
                liczby[i][j] = 0;
            else if (wczytana_liczba < 0)
                liczby[i][j] = -1;
            else if (wczytana_liczba > 0)
                liczby[i][j] = 1;
        }
    }


    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            ile_ujemnych[i][j] = ile_ujemnych[i-1][j] + ile_ujemnych[i][j-1] - ile_ujemnych[i-1][j-1];
            if (liczby[i][j] == -1)
                ile_ujemnych[i][j]++;
            ile_zer[i][j] = ile_zer[i-1][j] + ile_zer[i][j-1] - ile_zer[i-1][j-1];
            if (liczby[i][j] == 0)
                ile_zer[i][j]++;
        }
    }

    cin >> q;

    int x_1 = 0, x_2 = 0, y_1 = 0, y_2 = 0;
    for (int z = 0; z < q; ++z)
    {
        cin >> y_1 >> x_1 >> y_2 >> x_2;

        int ile_zer_zapytanie = ile_zer[y_2][x_2] - ile_zer[y_2][x_1-1] - ile_zer[y_1-1][x_2] + ile_zer[y_1-1][x_1-1];
        int ile_ujemnych_zapytanie = ile_ujemnych[y_2][x_2] - ile_ujemnych[y_2][x_1-1] - ile_ujemnych[y_1-1][x_2] + ile_ujemnych[y_1-1][x_1-1];
        if (ile_zer_zapytanie > 0)
            printf("0 \n");
        else if (ile_ujemnych_zapytanie % 2 == 0)
            printf("1 \n");
        else
            printf("-1 \n");
    }

    return 0;
}
