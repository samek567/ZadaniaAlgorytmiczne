#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string ciag;
    int licznik = 0;
    int ostatnio_sprawdzana = 0;

    cin >> ciag;


    for (int i = 1; i < ciag.length(); i++)
    {
        if (ciag[i] != ciag[ostatnio_sprawdzana])
        {
            ostatnio_sprawdzana = i;
        }
        else
        {
            licznik++;
        }
    }

    cout << licznik;

    return 0;
}