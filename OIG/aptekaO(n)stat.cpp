#include <iostream>
#include <vector>

using namespace std;

long long n = 0, wczytana_liczba = 0, akt_idx = 0, wyn = 0, min_val = 0, pas_idx = 0;
vector<long long> liczby;
vector<long long> stat;

int main()
{
    /*
    O(n)
    Mozna to zadanie napewno zrobic na 3 rozne sposoby.
    1 - Ten
    2 - Sortowaniem kolejnych liczb z zapamietaniem idx-a i przegladanie liczb w kolejnosci nie malejacej i przesuwanie sie tylko do dalszych idx-ow. O(n log n)
    3 - Dokladnie ten sposob, tylko szukanie mina drzewem przedzialowym punkt-przedzial O(n log n)
     */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    stat.assign(n+1,0);
    liczby.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    min_val = 1e9+5;
    pas_idx = n;
    for (int i = n; i >= 0; --i)
    {
        stat[i] = pas_idx;
        if (liczby[i] < min_val)
        {
            min_val = liczby[i];
            pas_idx = i;
        }
    }

    while(true)
    {
        if (akt_idx == n)
            break;
        wyn += (stat[akt_idx] - akt_idx) * liczby[stat[akt_idx]];
        akt_idx = stat[akt_idx];
    }

    printf("%lld",wyn);

    return 0;
}