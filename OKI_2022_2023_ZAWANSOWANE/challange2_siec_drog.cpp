#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0;
vector<vector<int>> drogi;

int main()
{
    // Challange 2

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        drogi.push_back({});
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytana_liczba;
            drogi[i].push_back(wczytana_liczba);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            bool czy_pasuje = true;

            for (int k = 0; k < n; ++k)
            {
                if (k != i && k != j)
                {
                    if (drogi[i][j] == drogi[i][k] + drogi[k][j])
                    {
                        czy_pasuje = false;
                        break;
                    }
                }
            }

            if (czy_pasuje == true)
            {
                printf("%d %d \n", i+1, j+1);
            }
        }
    }
    return 0;
}