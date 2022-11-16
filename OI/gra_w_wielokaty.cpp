#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, p1 = 0, p2 = 0, p3 = 0;

bool czy_pasuja()
{
    vector<int> pkt {p1,p2,p3};
    sort(pkt.begin(),pkt.end());
    if (p1 == p2-1 && p2 == p3-1)
    {
        return true;
    }
    if (p1 == 0 && p2 == 1 && p3 == n-1)
    {
        return true;
    }
    if (p1 == 0 && p2 == n-2 && p3 == n-1)
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    cin >> p1 >> p2 >> p3;

    if (czy_pasuja() == true)
    {
        cout << "TAK" << '\n';
    }
    else if ((n-3) % 2 == 1)
    {
        cout << "TAK" << '\n';
    }
    else
    {
        cout << "NIE" << '\n';
    }

    return 0;
}
