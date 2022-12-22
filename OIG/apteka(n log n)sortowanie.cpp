#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Osoba
{
    long long wartosc;
    long long idx;
    bool operator < (const Osoba& osoba) const
    {
        if (wartosc != osoba.wartosc)
        {
            return wartosc < osoba.wartosc;
        }
        else
        {
            return idx > osoba.idx;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n = 0;
    long long aktualna_liczba = 0;
    long long idx_sprawdzany = -1;
    long long suma = 0;
    vector<Osoba> osoby;

    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        cin >> aktualna_liczba;
        osoby.push_back({aktualna_liczba,i});
    }

    sort(osoby.begin(),osoby.end());

    /*
    for (long long i = 0; i < n; i++)
    {
        cout << "wartosc: " << osoby[i].wartosc << " idx: " << osoby[i].idx << endl;
    }
*/
    for (long long i = 0; i < n; i++)
    {
        if (osoby[i].idx > idx_sprawdzany)
        {
            suma += (osoby[i].idx - idx_sprawdzany) * osoby[i].wartosc;
            idx_sprawdzany = osoby[i].idx;
            // Liczymy ile dodajemy do sumy
        }
    }

    cout << suma;

    return 0;
}