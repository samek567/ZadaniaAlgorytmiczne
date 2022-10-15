#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int m = 0;
    int wczytana_liczba = 0;
    long long wynik = 0;
    vector<int> patyczki {0};

    cin >> n >> m;
    int zliczanie[m+1] {0};
    vector<vector<long long>> dp(m+1,vector<long long>(m+1));
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            dp[i][j] = 0;
        }
    }

    // Counting sort.
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        zliczanie[wczytana_liczba]++;
    }

    for (int i = 1; i <= m; ++i)
    {
        if (zliczanie[i] == 1)
        {
            patyczki.push_back(i);
        }
        else if (zliczanie[i] >= 2)
        {
            patyczki.push_back(i);
            patyczki.push_back(i);
        }
    }

    for (int x = 1; x < patyczki.size(); ++x)
    {
        for (int y = x - 1; y > 0; --y)
        {
            long long l = 0;
            for (int z = y - 1; z >= 0; --z)
            {
                if (patyczki[z] == patyczki[z+1] && z != y - 1)
                {
                    continue;
                }
                if (patyczki[z] <= patyczki[x] - patyczki[y])
                {
                    l += dp[patyczki[y]][patyczki[z]];
                }
            }
            dp[patyczki[x]][patyczki[y]] = max(dp[patyczki[x]][patyczki[y]],l);
        }
        dp[patyczki[x]][0] = max(dp[patyczki[x]][0],(long long)1);
    }

    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            wynik += dp[i][j];
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }

    cout << wynik;
    return 0;
}