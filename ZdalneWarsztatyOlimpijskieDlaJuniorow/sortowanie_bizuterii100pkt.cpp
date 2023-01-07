#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
string ciag;
vector<string> ciagi;

bool porownanie_sort(string c1, string c2)
{
    if (c1.size() == c2.size())
        return c1 < c2;
    return c1.size() < c2.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> ciag;
        ciagi.push_back(ciag);
    }
    sort(ciagi.begin(),ciagi.end(), porownanie_sort);
    for (int i = 0; i < n; ++i)
        printf("%s\n",ciagi[i].c_str());
    return 0;
}