#include <iostream>
#include <vector>

using namespace std;

int n = 0;
string wyn;
vector<string> ciag;
vector<vector<int>> ile;
vector<int> wsk;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    ciag.assign(n,"a");
    for (int i = 0; i < n; ++i)
        cin >> ciag[i];

    ile.assign(n,{});
    for (int i = 0; i < n; ++i)
    {
        ile[i].assign(26,0);
        for (int j = 0; j < ciag[i].size(); ++j)
            ile[i][(int)ciag[i][j]-97]++;
    }
    wsk.assign(n,0);

    for (char i = 'z'; i >= 'a'; --i)
    {
        int idx = (int)i-97, maxx = 1e9;
        for (int j = 0; j < n; ++j)
            maxx = min(maxx, ile[j][idx]);
        for (int j = 0; j < maxx; ++j)
            wyn.push_back(i);
        for (int j = 0; j < n; ++j)
        {
            int ile_zostalo = maxx;
            for (int k = wsk[j]; k < ciag[j].size() and ile_zostalo > 0; ++k)
            {
                int idxx = (int)ciag[j][k] - 97;
                ile[j][idxx]--;
                if (ciag[j][k] == i)
                    ile_zostalo--;
                wsk[j]++;
            }
        }
    }

    cout << max(wyn,(string)"bitek");

    return 0;
}