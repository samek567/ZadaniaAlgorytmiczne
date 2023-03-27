#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n = 0, max_wyn = 0, wyn = 0;
string ciag, spr;
vector<string> wydruki;
unordered_map<string,int> stat; // ciag first, ile ma dp.

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> ciag;
        wydruki.push_back(ciag);
    }
    sort(wydruki.begin(),wydruki.end());
    for (int i = 0; i < n; ++i)
    {
        if (auto it1 = stat.find(wydruki[i]) != stat.end())
        {
            stat[wydruki[i]]++;
            max_wyn = max(max_wyn,stat[wydruki[i]]);
        }
        else
        {
            wyn = 1;
            spr = wydruki[i];
            while(!spr.empty())
            {
                if (auto it = stat.find(spr) != stat.end())
                {
                    wyn += stat[spr];
                    break;
                }
                spr.pop_back();
            }
            stat[wydruki[i]] = wyn;
            max_wyn = max(max_wyn,wyn);
        }
    }
    printf("%d",max_wyn);
    return 0;
}