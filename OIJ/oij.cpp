#include <iostream>

using namespace std;

int main() {
    string ciag;
    int licznik_o = 0;
    int licznik_i = 0;
    int licznik_j = 0;
    int licznik_slow = 0;

    cin >> ciag;

    for (int i = 0; i < ciag.length(); i++)
    {
        char znak = ciag[i];
        if (znak == 'o' && licznik_o == 0)
        {
            licznik_o++;
        }
        if (znak == 'i' && licznik_i == 0 && licznik_o == 1)
        {
            licznik_i++;
        }
        if (znak == 'j' && licznik_j == 0 && licznik_i == 1)
        {
            licznik_j++;
        }

        if (licznik_o == 1 && licznik_i == 1 && licznik_j == 1)
        {
            licznik_o = 0;
            licznik_i = 0;
            licznik_j = 0;
            licznik_slow++;
        }

    }

    if (licznik_slow == 0)
    {
        cout << "NIE";
    }
    else
    {
        cout << licznik_slow;
    }

    return 0;
}