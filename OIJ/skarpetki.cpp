#include <iostream>

using namespace std;

int licznik_c = 0, licznik_b = 0;
string ciag;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag;

    for (int i = 0; i < ciag.size(); ++i)
    {
        if (ciag[i] == 'B')
        {
            licznik_b++;
        }
        else
        {
            licznik_c++;
        }
    }

    cout << (licznik_b / 2) + (licznik_c / 2);
    return 0;
}