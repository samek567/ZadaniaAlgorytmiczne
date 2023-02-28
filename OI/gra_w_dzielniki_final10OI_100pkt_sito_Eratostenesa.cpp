#include <iostream>
#include <vector>
#include "maja.h"
#include <cmath>

using namespace std;
typedef long long ll;

int n = 0, wyn = 1;
bool sito[1000001] = {false};
vector<int> P;

int main()
{
    // Szukamy wszystkie liczby pierwsze do max N, czyli 10^6, i rozkładamy liczbę N, na czynniki pierwzse, sprawdzajac
    // kolejno przez jaie liczby jest podzielna.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i <= 1e6; ++i)
    {
        if (sito[i] == false)
        {
            P.push_back(i);
            if (i <= 1e3)
                for (int j = i*i; j <= 1e6; j += i)
                    sito[j] = true;
        }
    }

    while(true)
    {
        n = gramy_dalej();
        if (n == 0)
            break;
        wyn = 1;
        for (int i = 0; i < P.size(); ++i)
        {
            if (P[i] > n or wyn * P[i] > n)
                break;
            if (czy_podzielna_przez(P[i]) == 1)
            {
                wyn *= P[i];
                int x = P[i] * P[i];
                if (P[i] <= sqrt(n)+1)
                {
                    while(true)
                    {
                        if (x > n)
                            break;
                        if (czy_podzielna_przez(x) == 1)
                        {
                            wyn *= P[i];
                            if ((ll)x * (ll)P[i] > n)
                                break;
                            x *= P[i];
                        }
                        else
                            break;
                    }
                }
            }
        }
        zgaduj(wyn);
    }

    return 0;
}