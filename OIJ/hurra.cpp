#include <iostream>

using namespace std;

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 7 == 0 && i % 11 == 0)
        {
            cout << "Wiwat!" << endl;
        }
        else if (i % 7 == 0)
        {
            cout << "Hurra!" << endl;
        }
        else if (i % 11 == 0)
        {
            cout << "Super!" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
    return 0;
}