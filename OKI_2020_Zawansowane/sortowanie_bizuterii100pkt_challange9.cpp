#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
string ciag;
vector<string> ciagi;

bool operator_do_sorta(string s1, string s2)
{
    if (s1.size() == s2.size())
        return s1 < s2;
    return s1.size() < s2.size();
}

int main()
{
    // O(N lg N + czas porownywania stringow)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> ciag;
        ciagi.push_back(ciag);
    }
    sort(ciagi.begin(),ciagi.end(),operator_do_sorta);
    for (int i = 0; i < n; ++i)
        cout << ciagi[i] << '\n';

    return 0;
}