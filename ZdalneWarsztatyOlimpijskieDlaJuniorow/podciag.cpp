#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short z = 0;
    int dlugosc_wyrazu_1 = 0;
    int dlugosc_wyrazu_2 = 0;
    int wskaznik_ciag_1 = 0;
    string ciag_1;
    string ciag_2;

    cin >> z;

    for (int i = 0; i < z; i++)
    {
        cin >> dlugosc_wyrazu_1 >> dlugosc_wyrazu_2 >> ciag_1 >> ciag_2;
        wskaznik_ciag_1 = 0;
        for (int j = 0; j < ciag_2.size(); j++)
        {
            if (ciag_2[j] == ciag_1[wskaznik_ciag_1])
            {
                wskaznik_ciag_1++;
            }
        }
        if (wskaznik_ciag_1 == dlugosc_wyrazu_1)
        {
            printf("TAK \n");
        }
        else
        {
            printf("NIE \n");
        }
    }

    return 0;
}