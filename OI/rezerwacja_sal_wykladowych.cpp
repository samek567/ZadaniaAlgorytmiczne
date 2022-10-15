#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Wyklad
{
    int poczatek;
    int koniec;

    bool operator < (const Wyklad& wyklad) const
    {
        return koniec < wyklad.koniec;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int p_wczytany = 0;
    int k_wczytany = 0;
    int idx_przecinajacej = 0;
    long long opcja1 = 0;
    long long opcja2 = 0;
    long long poczatek = 0;
    long long koniec = 0;
    long long srodek = 0;
    vector<Wyklad> Sale_wykladowe;

    cin >> n;
    long long k[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> p_wczytany >> k_wczytany;
        Sale_wykladowe.push_back({p_wczytany,k_wczytany});
    }

    sort(Sale_wykladowe.begin(),Sale_wykladowe.end());

    /*
    cout << endl;
    for (auto i : Sale_wykladowe)
    {
        cout << i.poczatek << " " << i.koniec << endl;
    }
    */

    k[0] = Sale_wykladowe[0].koniec - Sale_wykladowe[0].poczatek;

    for (int i = 1; i < n; ++i)
    {
        idx_przecinajacej = -1; // -1 Jak wiemy ze nie znalezlismy
        opcja1 = k[i-1];
        opcja2 = Sale_wykladowe[i].koniec - Sale_wykladowe[i].poczatek;

        poczatek = -1;
        koniec = i;
        srodek = 0;

        while (koniec - poczatek != 1)
        {
            srodek = (poczatek+koniec) / 2;
            if (Sale_wykladowe[srodek].koniec > Sale_wykladowe[i].poczatek)
            {
                koniec = srodek;
            }
            else
            {
                poczatek = srodek;
            }
        }
        if (koniec == i) // Znalezlismy
        {
            opcja2 += k[i-1];
        }
        else
        {
            if (koniec-1 >= 0)
            {
                opcja2 += k[koniec-1];
            }
        }

        k[i] = max(opcja1,opcja2);
        //cout << "koniec: " << koniec << endl;
        //return 0;
    }

    cout << k[n-1];
/*
    cout << endl;
    for (auto i : k)
    {
        cout << i << endl;
    }
    */

    return 0;
}