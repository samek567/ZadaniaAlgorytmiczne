#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

long long suma_cyfr (long long x)
{
    long long s = 0;
    while (x != 0)
    {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    long long n = 0;
    long long liczba = 0;
    long long licznik = 0;
    string ciag;
    string ciag_zamiana;
    vector<string> liczby_suma_cyfr_9;
    vector<long long> liczby_pechowe_test;
    unordered_set<long long> liczby_pechowe;

    liczby_suma_cyfr_9.push_back("9");

    cin >> n;

    for (long long i = 1; i < 10; ++i)
    {
        queue<long long> generowanie_liczb;

        generowanie_liczb.push(i);
        while (!generowanie_liczb.empty())
        {
            ciag = to_string(generowanie_liczb.front());
            for (int j = 0; j < 10; ++j)
            {
                ciag_zamiana = ciag + to_string(j);
                liczba = stoll(ciag_zamiana);
                if (suma_cyfr(liczba) == 9 && liczba <= n)
                {
                    generowanie_liczb.push(liczba);
                    liczby_suma_cyfr_9.push_back(ciag_zamiana);
                }
                else if (suma_cyfr(liczba) < 9 && liczba <= n)
                {
                    generowanie_liczb.push(liczba);
                }
            }
            generowanie_liczb.pop();
        }
    }


    string liczba_pechowa;
    for (int i = 0; i < liczby_suma_cyfr_9.size(); ++i)
    {
        for (int j = 0; j < liczby_suma_cyfr_9[i].size()-1; ++j)
        {
            if (liczby_suma_cyfr_9[i][j] == '0' && liczby_suma_cyfr_9[i][j+1] == '0')
            {
                liczba_pechowa = liczby_suma_cyfr_9[i];
                liczba_pechowa[j] = '1';
                liczba_pechowa[j+1] = '3';
                if (stoll(liczba_pechowa) <= n)
                {
                    liczby_pechowe.insert(stoll(liczba_pechowa));
                    licznik++;
                }
            }
        }

        liczba_pechowa = "00" + liczby_suma_cyfr_9[i];

        for (int k = liczby_suma_cyfr_9[i].size(); k+2 < 15; ++k)
        {
            liczba_pechowa[0] = '1';
            liczba_pechowa[1] = '3';
            if (stoll(liczba_pechowa) <= n)
            {
                liczby_pechowe.insert(stoll(liczba_pechowa));
                licznik++;
            }
            liczba_pechowa[0] = '0';
            liczba_pechowa[1] = '0';
            liczba_pechowa = "0" + liczba_pechowa;
        }

    }

    cout << liczby_pechowe.size();

    return 0;
}