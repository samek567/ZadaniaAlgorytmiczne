#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string napis;

    cin >> napis;

    for (int i = 0; i < napis.size(); ++i)
    {
        if (napis[i] == 'a')
        {
            napis[i] = '4';
        }
        else if (napis[i] == 'e')
        {
            napis[i] = '3';
        }
        else if (napis[i] == 'i')
        {
            napis[i] = '1';
        }
        else if (napis[i] == 'o')
        {
            napis[i] = '0';
        }
        else if (napis[i] == 's')
        {
            napis[i] = '5';
        }
    }

    cout << napis;
    return 0;
}