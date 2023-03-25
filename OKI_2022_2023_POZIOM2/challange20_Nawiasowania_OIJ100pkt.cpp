#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n = 0;
    long long licznik_kombinacji = 0;
    long long inkrement = 2;
    long long sprawdzany_wynik = 0;
    string ciag_wyswietlany;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        ciag_wyswietlany = "()";
        licznik_kombinacji = 1;
        inkrement = 2;
        sprawdzany_wynik = i;
        while (true)
        {
            if (i + licznik_kombinacji + inkrement <= n)
            {
                licznik_kombinacji += inkrement;
                ciag_wyswietlany += "()";
                inkrement++;
            }
            else
            {
                break;
            }
        }
        i += licznik_kombinacji - 1;
        ciag_wyswietlany += ")";
        cout << ciag_wyswietlany;
    }

    return 0;
}