#include <iostream>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int licznik_b = 0;
    int licznik_cz = 0;
    long long min_wynik = LLONG_MAX;
    long long wynik = 0;
    int wskazywany_idx = 0;
    string ciag1;
    string ciag2;

    cin >> n >> ciag1 >> ciag2;

    for (int i = 0; i < n; ++i)
    {
        if (ciag1[i] == 'B')
        {
            licznik_b++;
        }
        else
        {
            licznik_cz++;
        }
    }

    // Najpierw sprawdzamy biale kulki u góry.

    for (int i = 0; i < n; ++i)
    {
        if (ciag1[i] == 'C')
        {
            for (int j = wskazywany_idx; j < n; ++j)
            {
                //cout << "J: " << j << endl;
                if (ciag2[j] == 'B')
                {
                    //cout << "J: " << j << endl;
                    if (j > i)
                    {
                        wynik += j - i;
                        //cout << "wynik: " << wynik << " i: " << i << " j: " << j << endl;
                    }
                    else
                    {
                        wynik += i - j;
                        //cout << "wynik: " << wynik << " i: " << i << " j: " << j << endl;
                    }
                    wskazywany_idx = j+1;
                    break;
                }
            }
        }
    }

    wynik += n - licznik_b;

    if (wynik < min_wynik)
    {
        min_wynik = wynik;
    }


    wynik = 0;
    wskazywany_idx = 0;

    for (int i = 0; i < n; ++i)
    {
        if (ciag1[i] == 'B')
        {
            for (int j = wskazywany_idx; j < n; ++j)
            {
                //cout << "J: " << j << endl;
                if (ciag2[j] == 'C')
                {
                    //cout << "J: " << j << endl;
                    if (j > i)
                    {
                        wynik += j - i;
                        //cout << "wynik: " << wynik << " i: " << i << " j: " << j << endl;
                    }
                    else
                    {
                        wynik += i - j;
                        //cout << "wynik: " << wynik << " i: " << i << " j: " << j << endl;
                    }
                    wskazywany_idx = j+1;
                    break;
                }
            }
        }
    }

    wynik += n - licznik_cz;

    if (wynik < min_wynik)
    {
        min_wynik = wynik;
    }



    if (min_wynik == LLONG_MAX)
    {
        printf("0");
    }
    else
    {
        printf("%lld",min_wynik);
    }

    return 0;
}