#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;

    cin >> n;

    for (int c = 0; c < n; ++c)
    {
        int a = 0;
        int b = 0;
        cin >> a >> b;
        if (b % a == 0)
        {
            cout << "TAK" << endl;
        }
        else
        {
            cout << "NIE" << endl;
        }
    }
    return 0;
}