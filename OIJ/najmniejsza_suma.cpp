#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct Liczba
{
    int wartosc;
    char znak;
    // Sortowanie uzyte w moim wykonaniu zadania zwyciezcy z 1 edycji OIG uzyty na platformie szkopol - kod wlasny troche podmienione
    bool operator < (const Liczba& liczba) const
    {
        return wartosc < liczba.wartosc;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long k = 0;
    unsigned long long licznik = 0;
    unsigned long long licznik_zer = 0;
    unsigned long long suma = 0;
    bool czy_pierwszy_obieg = true;
    string ciag;
    vector<Liczba> cyfry;

    cin >> ciag >> k;

    string slowa[k];

    for (long long i = 0; i < ciag.size(); ++i)
    {
        if (ciag[i] == '0')
        {
            licznik_zer++;
        }
        else if (ciag[i] == '1')
        {
            cyfry.push_back({1,'1'});
        }
        else if (ciag[i] == '2')
        {
            cyfry.push_back({2,'2'});
        }
        else if (ciag[i] == '3')
        {
            cyfry.push_back({3,'3'});
        }
        else if (ciag[i] == '4')
        {
            cyfry.push_back({4,'4'});
        }
        else if (ciag[i] == '5')
        {
            cyfry.push_back({5,'5'});
        }
        else if (ciag[i] == '6')
        {
            cyfry.push_back({6,'6'});
        }
        else if (ciag[i] == '7')
        {
            cyfry.push_back({7,'7'});
        }
        else if (ciag[i] == '8')
        {
            cyfry.push_back({8,'8'});
        }
        else if (ciag[i] == '9')
        {
            cyfry.push_back({9,'9'});
        }
    }

    if (licznik_zer == ciag.size())
    {
        cout << "0";
        return 0;
    }

    sort(cyfry.begin(),cyfry.end());

    for (long long i = 0; i < cyfry.size() + licznik_zer; i++)
    {
        if (czy_pierwszy_obieg == false && licznik_zer > 0)
        {
            slowa[licznik] += '0';
            licznik_zer--;
            i--;
        }
        else
        {
            slowa[licznik] += cyfry[i].znak;
        }
        licznik++;
        if (licznik == k)
        {
            licznik = 0;
            czy_pierwszy_obieg = false;
        }
    }

    for (long long i = 0; i < k; i++)
    {
        suma += stoll(slowa[i]);
    }

    printf("%llu",suma);

    return 0;
}