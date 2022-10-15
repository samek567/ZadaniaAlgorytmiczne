#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n = 0;
    int k = 0;
    int rozmiar = 0;
    int liczba1 = 0;
    int liczba2 = 0;
    int t_max = 0;
    int g_max = 0;
    cin >> n >> k;

    k = k / 2;

    rozmiar = pow(2,n) - 1;

    int pola [rozmiar];

    for (int i = 0; i < rozmiar; i++)
    {
        cin >> liczba1 >> liczba2;
        pola[i] = liczba1 + liczba2;
    }

    for (int i = 0; i < rozmiar;i++)
    {
        //cout << pola[i] << " ";
    }

    int tablica_dynamiczna [rozmiar][k+1];

    for (int i = (rozmiar + 1) / 2 - 1; i < rozmiar; i++)
    {
        tablica_dynamiczna[i][0] = 0;
        for (int j = 1; j <= k; j++)
        {
            tablica_dynamiczna[i][j] = pola[i];
        }
    }

    for (int i = (rozmiar + 1) / 2 - 2; i >= 0; i--)
    {
        tablica_dynamiczna[i][0] = 0;
        tablica_dynamiczna[i][1] = pola[i];
        for (int j = 2; j <= k; j++)
        {
            t_max = INT_MIN;
            for (int y = 0; y < j; y++)
            {
                if (tablica_dynamiczna[2*i+1][y]  + tablica_dynamiczna[2*i+2][j-y-1] > t_max)
                {
                    t_max = tablica_dynamiczna[2*i+1][y]  + tablica_dynamiczna[2*i+2][j-y-1];
                }
            }
            /*
            if (i == 2)
            {
                //cout << "dodajemy: " << "J: " << j << "Wartosc: " << t_max+pola[i] << endl;
            }
            */
            tablica_dynamiczna[i][j] = t_max + pola[i];
        }
    }

    for (int i = 0; i <= k; i++)
    {
        if (tablica_dynamiczna[0][i] > g_max)
        {
            g_max = tablica_dynamiczna[0][i];
        }
    }


    /*
    for (int i = 0; i <= k; i++)
    {
       cout << tablica_dynamiczna[0][i] << "  ";
    }
*/

    cout << g_max;
    return 0;
}