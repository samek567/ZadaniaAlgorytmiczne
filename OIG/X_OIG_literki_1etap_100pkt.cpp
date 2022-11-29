#include <iostream>

using namespace std;

string ciag;
int licznik_o = 0, licznik_i = 0, licznik_g = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag;

    for (int i = 0; i < ciag.size(); ++i)
    {
        if (ciag[i] == 'O')
        {
            licznik_o++;
        }
        else if (ciag[i] == 'I')
        {
            licznik_i++;
        }
        else if (ciag[i] == 'G')
        {
            licznik_g++;
        }
    }

    printf("%d",min(licznik_o,min(licznik_i,licznik_g)));

    return 0;
}