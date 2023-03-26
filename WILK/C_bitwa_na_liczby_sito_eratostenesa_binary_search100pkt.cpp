#include <iostream>
#include <vector>

using namespace std;

int n = 0, q = 0, a = 0, b = 0, poczatek = 0, koniec = 0, srodek = 0, wyn_bajsza = 0, wyn_bajtorz = 0;
vector<bool> sito;
vector<int> P;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    sito.assign(n+1000,false);
    for (int i = 2; i <= n+1000; ++i)
    {
        if (sito[i] == false)
        {
            P.push_back(i);
            if (i <= 1e3+50)
                for (int j = i * i; j <= n+1000; j += i)
                    sito[j] = true;
        }
    }

    while(q--)
    {
        cin >> a >> b;
        poczatek = -1, koniec = P.size(), wyn_bajsza = 1e9, wyn_bajtorz = 1e9;
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (P[srodek] <= a)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        if (poczatek != -1)
            wyn_bajsza = min(wyn_bajsza, a - P[poczatek]);
        poczatek = -1, koniec = P.size();
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (P[srodek] >= a)
                koniec = srodek;
            else
                poczatek = srodek;
        }
        if (koniec != P.size())
            wyn_bajsza = min(wyn_bajsza, P[koniec] - a);

        poczatek = -1, koniec = P.size();
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (P[srodek] <= b)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        if (poczatek != -1)
            wyn_bajtorz = min(wyn_bajtorz, b - P[poczatek]);
        poczatek = -1, koniec = P.size();
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (P[srodek] >= b)
                koniec = srodek;
            else
                poczatek = srodek;
        }
        if (koniec != P.size())
            wyn_bajtorz = min(wyn_bajtorz, P[koniec] - b);

        if (wyn_bajsza < wyn_bajtorz)
            cout << "Bajtorz" << '\n';
        else if (wyn_bajsza > wyn_bajtorz)
            cout << "Bajsza" << '\n';
        else
            cout << "Remis" << '\n';
    }

    return 0;
}