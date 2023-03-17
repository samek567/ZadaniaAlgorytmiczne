#include <iostream>
#include <vector>

using namespace std;

int odtw = 0;
string ciag, spr;
vector<int> dp_min;
vector<int> dp_max;
vector<int> idx_poprzedniej_min;
vector<int> idx_poprzedniej_max;
vector<string> wyn_min;
vector<string> wyn_max;

inline bool czy_palindrom()
{
    for (int i = 0; i < spr.size() / 2; ++i)
        if (spr[i] != spr[spr.size()-1-i])
            return false;
    return true;
}

int main()
{
    // Programowanie dynamiczne, O(N^3)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag;

    dp_min.assign(ciag.size()+1,-1);
    dp_max.assign(ciag.size()+1,-1);
    idx_poprzedniej_min.assign(ciag.size()+1,-1);
    idx_poprzedniej_max.assign(ciag.size()+1,-1);

    dp_min[0] = 0;
    dp_max[0] = 0;

    for (int i = 0; i < ciag.size(); ++i)
    {
        spr.clear();
        for (int j = i; j < ciag.size(); ++j)
        {
            spr += ciag[j];
            if (spr.size() % 2 == 0 and czy_palindrom() == true)
            {
                if (dp_min[j+1] == -1 or dp_min[i] + 1 < dp_min[j+1])
                {
                    dp_min[j+1] = dp_min[i] + 1;
                    idx_poprzedniej_min[j+1] = i;
                }
                if (dp_max[j+1] == -1 or dp_max[i] + 1 > dp_max[j+1])
                {
                    dp_max[j+1] = dp_max[i] + 1;
                    idx_poprzedniej_max[j+1] = i;
                }
            }
        }
    }

    if (idx_poprzedniej_min[ciag.size()] == -1)
    {
        cout << "NIE" << '\n';
        return 0;
    }

    odtw = ciag.size();
    while(true)
    {
        if (idx_poprzedniej_min[odtw] == -1)
            break;
        spr.clear();
        for (int i = idx_poprzedniej_min[odtw]; i < odtw; ++i)
            spr.push_back(ciag[i]);
        wyn_min.push_back(spr);
        odtw = idx_poprzedniej_min[odtw];
    }

    odtw = ciag.size();
    while(true)
    {
        if (idx_poprzedniej_max[odtw] == -1)
            break;
        spr.clear();
        for (int i = idx_poprzedniej_max[odtw]; i < odtw; ++i)
            spr.push_back(ciag[i]);
        wyn_max.push_back(spr);
        odtw = idx_poprzedniej_max[odtw];
    }

    for (int i = wyn_min.size()-1; i >= 0; --i)
        cout << wyn_min[i] << ' ';
    cout << '\n';
    for (int i = wyn_max.size()-1; i >= 0; --i)
        cout << wyn_max[i] << ' ';
    cout << '\n';

    return 0;
}