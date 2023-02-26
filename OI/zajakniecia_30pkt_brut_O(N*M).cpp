#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0;
vector<int> A;
vector<int> B;
vector<int> idx_poprzedniej_A;
vector<int> idx_poprzedniej_B;
vector<vector<int>> dp;
unordered_map<int,int> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        A.push_back(wczytana_liczba);
        if (auto it = stat.find(wczytana_liczba) != stat.end())
            idx_poprzedniej_A.push_back(stat[wczytana_liczba]);
        else
            idx_poprzedniej_A.push_back(-1);
        stat[wczytana_liczba] = i;
    }

    stat.clear();

    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        B.push_back(wczytana_liczba);
        if (auto it = stat.find(wczytana_liczba) != stat.end())
            idx_poprzedniej_B.push_back(stat[wczytana_liczba]);
        else
            idx_poprzedniej_B.push_back(-1);
        stat[wczytana_liczba] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        dp.push_back({});
        for (int j = 0; j < m; ++j)
            dp[i].push_back(0);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (A[i] == B[j] and idx_poprzedniej_A[i] != -1 and idx_poprzedniej_B[j] != -1)
                {
                    int idx_pop_A = idx_poprzedniej_A[i], idx_pop_B = idx_poprzedniej_B[j];
                    if (idx_pop_A == 0 or idx_pop_B == 0)
                        dp[i][j] = max(dp[i][j], 1);
                    else
                        dp[i][j] = max(dp[i][j], dp[idx_pop_A-1][idx_pop_B-1] + 1);
                }
            }
        }
    }


    cout << dp[A.size()-1][B.size()-1]  * 2 << '\n';

    return 0;
}