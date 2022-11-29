#include <iostream>

using namespace std;

string ciag;
int idx_pytajnika = 0, suma_cyfr = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag;

    for (int i = 0; i < ciag.size(); ++i)
    {
        if (ciag[i] == '?')
        {
            idx_pytajnika = i;
        }
        else
        {
            suma_cyfr += (int)ciag[i] - 48;
        }
    }

    if (suma_cyfr % 3 == 0)
    {
        printf("%d",0);
    }
    else if (suma_cyfr % 3 == 1)
    {
        printf("%d",2);
    }
    else
    {
        printf("%d",1);
    }

    return 0;
}