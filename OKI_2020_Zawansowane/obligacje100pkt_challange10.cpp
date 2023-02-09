#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

string ciag, wyn_ciag;
int wyn_ile = 0, idx_wyst = 1e6+2000;
unordered_map<string,pair<int,int>> stat; // Ile, idx pierwszego wystapienia.
vector<string> do_sprawdzenia;
set<char> dobre = {'a', 'b', 'c',
                   'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x','y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                   'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main()
{
    // O(Size na wejsciu * lg(26))
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while((cin >> ciag).good())
    {
        string spr;
        for (int i = 0; i < ciag.size(); ++i)
        {
            if (auto it = dobre.find(ciag[i]) != dobre.end())
                spr += ciag[i];
            else
            {
                if (!spr.empty())
                    do_sprawdzenia.push_back(spr);
                spr.clear();
            }
        }
        if (!spr.empty())
            do_sprawdzenia.push_back(spr);
    }
    int cnt = 0;
    for (int i = 0; i < do_sprawdzenia.size(); ++i)
    {
        if (auto it = stat.find(do_sprawdzenia[i]) != stat.end()) // Znalezlismy
            stat[do_sprawdzenia[i]].first++;
        else
        {
            stat.insert({do_sprawdzenia[i],{1,cnt}});
            cnt++;
        }
    }

    for (auto it = stat.begin(); it != stat.end(); ++it)
    {
        if (it->second.first > wyn_ile)
        {
            wyn_ciag = it->first;
            wyn_ile = it->second.first;
            idx_wyst = it->second.second;
        }
        else if(it->second.first == wyn_ile && it->second.second < idx_wyst)
        {
            idx_wyst = it->second.second;
            wyn_ciag = it->first;
        }
    }

    cout << wyn_ciag << " " << wyn_ile << '\n';

    return 0;
}