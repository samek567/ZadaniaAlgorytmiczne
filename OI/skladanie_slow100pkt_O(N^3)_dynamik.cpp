#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, MAXX = 1e6;
bool czy_sprawdzilismy = false;
string ciag;
vector<string> wyrazy;
vector<int> dp;
vector<int> jaki_idx;
vector<int> wyn;

inline bool czy_sie_da_przylozyc(int i, int idx)
{
    for (int j = 0; j < wyrazy[i].size(); ++j)
    {
        if (wyrazy[i][j] != ciag[idx + j])
            return false;
    }
    return true;
}

int main()
{
    // O(N^3), dynamik. Mozna w O(N^2) z hashami.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag >> n;

    wyrazy.assign(n,"a");
    for (int i = 0; i < n; ++i)
        cin >> wyrazy[i];

    dp.assign(ciag.size(),0);
    jaki_idx.assign(ciag.size(),-1);
    for (int i = 0; i < n; ++i)
    {
        if (wyrazy[i].size() > ciag.size())
            continue;
        for (int j = ciag.size()-1; j - (int)wyrazy[i].size() >= 0; --j)
        {
            if (czy_sie_da_przylozyc(i,j-wyrazy[i].size() + 1) and dp[j-wyrazy[i].size()] > 0)
            {
                dp[j] = min(MAXX, dp[j] + dp[j-wyrazy[i].size()]);
                if (jaki_idx[j] == -1)
                    jaki_idx[j] = i;
            }
        }
        if (czy_sie_da_przylozyc(i,0))
        {
            dp[wyrazy[i].size()-1] = min(MAXX, dp[wyrazy[i].size()-1] + 1);
            if (jaki_idx[wyrazy[i].size()-1] == -1)
                jaki_idx[wyrazy[i].size()-1] = i;
        }

        if (jaki_idx[ciag.size()-1] > -1 and czy_sprawdzilismy == false)
        {
            czy_sprawdzilismy = true;
            int odtw = ciag.size()-1;
            while(odtw >= 0)
            {
                wyn.push_back(jaki_idx[odtw]);
                odtw -=  wyrazy[jaki_idx[odtw]].size();
            }
        }
    }

    if (dp[ciag.size()-1] == 0)
        cout << "NIE" << '\n';
    else
    {
        cout << dp[ciag.size()-1] << '\n';
        for (int i = wyn.size()-1; i >= 0; --i)
            cout << wyn[i] + 1 << '\n';
    }

    return 0;
}
