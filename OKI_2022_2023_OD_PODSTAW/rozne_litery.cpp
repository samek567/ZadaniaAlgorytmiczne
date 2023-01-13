#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int sum = 0;
string ciag;
map<char,int> stat;
vector<int> posortowane;

int main()
{
    // O(n log n) statystyki.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (char i = 'a'; i <= 'z'; ++i)
        stat[i] = 0;
    cin >> ciag;
    for (int i = 0; i < ciag.size(); ++i)
        stat[ciag[i]]++;
    for (char i = 'a'; i <= 'z'; ++i)
        posortowane.push_back(stat[i]);
    sort(posortowane.begin(),posortowane.end(),greater<int>());
    for (int i = 0; i < posortowane.size(); ++i)
    {
        if (posortowane[i] == 0)
            break;
        sum += posortowane[i];
        printf("%d ",ciag.size() - sum);
    }
    return 0;
}
