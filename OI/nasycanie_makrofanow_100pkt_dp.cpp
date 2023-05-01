#include <iostream>
#include <vector>

using namespace std;

int n = 0, min_wyn = 1e9, koncowa_temperatura = -1;
bool czy_mamy = false;
string ciag, akt;
vector<vector<int>> krawedzie;
vector<vector<int>> dp;
vector<vector<int>> idx_poprzedniej;
vector<int> droga;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    krawedzie.assign(n,{});
    getline(cin,ciag);
    for (int i = 0; i < n; ++i)
    {
        getline(cin,ciag);
        akt.clear();
        for (int j = 0; j < ciag.size(); ++j)
        {
            if (ciag[j] == ' ')
            {
                if (!akt.empty())
                {
                    krawedzie[i].push_back(stoi(akt));
                    akt.clear();
                }
            }
            else
                akt.push_back(ciag[j]);
        }
        if (!akt.empty())
            krawedzie[i].push_back(stoi(akt));
    }

    for (int z = 15; z <= 34; ++z)
    {
        dp.assign(n+1,{});
        for (int i = 0; i <= n; ++i)
            dp[i].assign(35,500);
        idx_poprzedniej.assign(n+1,{});
        for (int i = 0; i <= n; ++i)
            idx_poprzedniej[i].assign(35,-1);

        dp[0][z] = 0;
        czy_mamy = false;
        min_wyn = 1e9, koncowa_temperatura = -1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 15; j <= 34; ++j)
            {
                for (int k = 0; k < krawedzie[i].size(); ++k)
                {
                    int temp = j + krawedzie[i][k];
                    if (temp < 15 or temp > 34)
                        continue;
                    if (dp[i][j] + abs(krawedzie[i][k]) < dp[i+1][temp])
                    {
                        dp[i+1][temp] = dp[i][j] + abs(krawedzie[i][k]);
                        idx_poprzedniej[i+1][temp] = j;
                    }
                }
            }
        }
        for (int i = 15; i <= 34; ++i)
        {
            if (dp[n][i] < min_wyn and dp[n][i] != 500)
            {
                min_wyn = dp[n][i], koncowa_temperatura = i;
                czy_mamy = true;
            }
        }
        if (czy_mamy == true)
        {
            droga.clear();
            int odtw_idx = n, odtw_temp = koncowa_temperatura;
            while(idx_poprzedniej[odtw_idx][odtw_temp] != -1)
            {
                droga.push_back(odtw_temp - idx_poprzedniej[odtw_idx][odtw_temp]);
                odtw_temp = idx_poprzedniej[odtw_idx][odtw_temp], odtw_idx--;
            }
            for (int i = droga.size()-1; i >= 0; --i)
                cout << droga[i] << ' ';
            cout << '\n';
        }
        else
            cout << "NIE" << '\n';
    }

    return 0;
}
