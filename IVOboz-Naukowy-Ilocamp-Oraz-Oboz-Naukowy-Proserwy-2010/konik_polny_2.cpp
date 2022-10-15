#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x = 0;
    int s = 0;

    cin >> x >> s;

    if (x < s*2)
    {
        cout << "TAK";
    }
    else
    {
        cout << "NIE";
    }
    return 0;
}