#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    long long wartosc;
    int idx;

    bool operator < (const Element &element) const
    {
        if (wartosc == element.wartosc)
        {
            return idx < element.idx;
        }
        return wartosc < element.wartosc;
    }
};

int n = 0, max_wynik = 0;
long long s = 0, suma = 0, wczytana_liczba = 0;
vector<long long> sumy_prefiksowe;
vector<Element> stat;

int main()
{
    // O(N lg N), binary search. Mozna mapa / unordered_mapa / set, ale pamieciowo nie przechodzi na 100pkt.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        suma += wczytana_liczba;
        sumy_prefiksowe.push_back(suma);
        stat.push_back({sumy_prefiksowe[i],i});
    }
    sort(stat.begin(),stat.end());

    for (int i = 0; i < n; ++i)
    {
        long long szukana_suma = 0;
        if (i == 0)
        {
            szukana_suma = s;
        }
        else
        {
            szukana_suma = sumy_prefiksowe[i-1] + s;
        }
        int p = -1, k = n, srodek = 0;

        while(k - p != 1)
        {
            srodek = (p+k) / 2;
            if (stat[srodek].wartosc > szukana_suma)
            {
                k = srodek;
            }
            else
            {
                p = srodek;
            }
        }
        if (p > -1)
        {
            if (stat[p].wartosc == szukana_suma)
            {
                max_wynik = max(max_wynik, stat[p].idx - i + 1);
            }
        }
    }

    if (max_wynik == 0)
    {
        cout << "BRAK" << '\n';
    }
    else
    {
        cout << max_wynik << '\n';
    }

    return 0;
}