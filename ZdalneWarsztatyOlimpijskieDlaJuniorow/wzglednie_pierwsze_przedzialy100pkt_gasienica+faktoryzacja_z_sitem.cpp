#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n = 0, q = 0, wczytana_liczba = 0, a_i = 0, b_i = 0, lewy_wsk = 0, prawy_wsk = 0, sito_SIZE = 1000;
vector<bool> sito(sito_SIZE+1,false);
vector<int> P;
vector<int> liczby;
vector<vector<int>> dzielniki_pierwsze;
vector<int> konce_zglednie_pierwszych_przedzialow; // Koniec wzglednie pierwszego przedzialu zaczynajacego sie w i.
multiset<int> dzielniki_pierwsze_w_gasienicy;

inline vector<int> faktoryzacja(int x)
{
    vector<int> wyn_vect;
    for (int i = 0; i < P.size(); i+=0)
    {
        if (P[i] * P[i] > x)
            break;
        if (x % P[i] == 0)
        {
            x /= P[i];
            wyn_vect.push_back(P[i]);
        }
        else
            i++;
    }
    if (x != 1)
        wyn_vect.push_back(x);
    return wyn_vect;
}

inline bool czy_mozna_przesunac_prawy()
{
    for (int i = 0; i < dzielniki_pierwsze[prawy_wsk+1].size(); ++i)
    {
        if (auto it = dzielniki_pierwsze_w_gasienicy.find(dzielniki_pierwsze[prawy_wsk+1][i]) != dzielniki_pierwsze_w_gasienicy.end())
            return false;
    }
    return true;
}

inline void przesuwaj_lewy()
{
    konce_zglednie_pierwszych_przedzialow[lewy_wsk] = prawy_wsk;
    for (int i = 0; i < dzielniki_pierwsze[lewy_wsk].size(); ++i)
        dzielniki_pierwsze_w_gasienicy.erase(dzielniki_pierwsze_w_gasienicy.lower_bound(dzielniki_pierwsze[lewy_wsk][i]));
    lewy_wsk++;
    if (lewy_wsk > prawy_wsk)
    {
        prawy_wsk = lewy_wsk;
        for (int i = 0; i < dzielniki_pierwsze[prawy_wsk].size(); ++i)
            dzielniki_pierwsze_w_gasienicy.insert(dzielniki_pierwsze[prawy_wsk][i]);
    }
}

int main()
{
    // Gasienica + faktoryzacja z sitem.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i <= sito_SIZE; ++i)
    {
        if (sito[i] == false)
        {
            P.push_back(i);
            for (int j = i * i; j <= sito_SIZE; j += i)
                sito[j] = true;
        }
    }

    cin >> n >> q;
    konce_zglednie_pierwszych_przedzialow.assign(n,-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        dzielniki_pierwsze.push_back(faktoryzacja(liczby[i]));
    }

    for (int i = 0; i < dzielniki_pierwsze[0].size(); ++i)
        dzielniki_pierwsze_w_gasienicy.insert(dzielniki_pierwsze[0][i]);
    while (true)
    {
        if (lewy_wsk == prawy_wsk && prawy_wsk == n-1)
        {
            konce_zglednie_pierwszych_przedzialow[n-1] = n-1;
            break;
        }
        if (prawy_wsk == n-1)
            przesuwaj_lewy();
        else if (czy_mozna_przesunac_prawy() == true)
        {
            prawy_wsk++;
            for (int i = 0; i < dzielniki_pierwsze[prawy_wsk].size(); ++i)
                dzielniki_pierwsze_w_gasienicy.insert(dzielniki_pierwsze[prawy_wsk][i]);
        }
        else
            przesuwaj_lewy();
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> a_i >> b_i;
        if (konce_zglednie_pierwszych_przedzialow[a_i-1] >= b_i-1)
            printf("TAK\n");
        else
            printf("NIE\n");
    }
    return 0;
}