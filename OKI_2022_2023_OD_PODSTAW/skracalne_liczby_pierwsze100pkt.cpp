#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long p = 0;
    unsigned long long k = 0;
    unsigned long long licznik = 0;
    vector<unsigned long long> skracalne_liczby_pierwsze;
    string ciag;
    string ciag_sprawdzany;
    unsigned long long sprawdzana_pierwsza;
    bool czy_pierwsza = true;

    cin >> p >> k;

    for (int i = 2; i < 9; ++i)
    {
        queue<unsigned long long> generowanie_liczb;

        generowanie_liczb.push(i);
        skracalne_liczby_pierwsze.push_back(i);

        while (!generowanie_liczb.empty())
        {
            ciag = to_string(generowanie_liczb.front());
            for (int h = 1; h <= 9; h += 2)
            {
                ciag_sprawdzany = ciag + to_string(h);
                sprawdzana_pierwsza = stoull(ciag_sprawdzany);
                czy_pierwsza = true;
                for (int j = 2; j * j <= sprawdzana_pierwsza; ++j)
                {
                    if (sprawdzana_pierwsza % j == 0)
                    {
                        czy_pierwsza = false;
                        break;
                    }
                }
                if (czy_pierwsza == true && sprawdzana_pierwsza <= pow(10,18))
                {
                    skracalne_liczby_pierwsze.push_back(sprawdzana_pierwsza);
                    generowanie_liczb.push(sprawdzana_pierwsza);
                }
            }
            generowanie_liczb.pop();
        }
        if (i != 2)
        {
            i++;
        }
    }

    for (int i = 0; i < skracalne_liczby_pierwsze.size(); ++i)
    {
        if (skracalne_liczby_pierwsze[i] >= p && skracalne_liczby_pierwsze[i] <= k)
        {
            licznik++;
        }
    }

    cout << licznik;
    return 0;
}