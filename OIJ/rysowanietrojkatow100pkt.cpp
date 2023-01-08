#include <iostream>
#include <vector>

using namespace std;

int n = 0;
vector<int> akt_vect;
vector<int> POW = {1,9,81,729};

vector<int> konwertuj_na_dziewiatkowy(int x) // Zwracamy vector o idx-ach 0,1,2,3
{
    vector<int> wyn (4,0);
    for (int i = 3; i >= 0; --i)
    {
        for (int j = 9; j >= 1; --j)
        {
            if (POW[i] * j <= x)
            {
                wyn[i] = j;
                x -= POW[i] * j;
                break;
            }
        }
    }
    return wyn;
}

void wypisz_droge(string tekst)
{
    for (int i = 0; i < 4; ++i)
    {
        if (akt_vect[i] != 0)
        {
            for (int j = 0; j < i; ++j)
                printf("9[");
            printf("%d[%s]",akt_vect[i],tekst.c_str());
            for (int j = 0; j < i; ++j)
                printf("]");
        }
    }
}

int main()
{
    // Konwertujemy liczbe na system dziewiatkowy.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = n; i >= 1; --i)
    {
        akt_vect = konwertuj_na_dziewiatkowy(i);
        wypisz_droge("A");
        akt_vect = konwertuj_na_dziewiatkowy(i-1);
        wypisz_droge("EC");
        printf("E");
    }
    akt_vect = konwertuj_na_dziewiatkowy(n);
    wypisz_droge("C");

    return 0;
}