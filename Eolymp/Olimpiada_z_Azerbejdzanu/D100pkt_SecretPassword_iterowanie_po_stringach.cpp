#include <iostream>

using namespace std;

string ciag1, ciag2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag1 >> ciag2;

    for (int i = 0; i < min(ciag1.size(),ciag2.size()); ++i)
        cout << ciag1[i] << ciag2[i];
    if (ciag1.size() > ciag2.size())
        cout << ciag1[ciag1.size()-1];
    else if (ciag2.size() > ciag1.size())
        cout << ciag2[ciag2.size()-1];

    return 0;
}