#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

struct Element
{
    long long wartosc;
    long long idx;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long n = 0;
    long long t = 0;
    long long wczytany = 0;
    set<long long> numery_domow;
    map<long long, vector<long long>> statystyki;
    vector<Element> idxy_domow;
    long long wynik = 0;

    cin >> n >> t;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany;
        if (auto it = numery_domow.find(wczytany) == numery_domow.end()) // nie znalazlem
        {
            statystyki.insert({wczytany,{}});
        }
        idxy_domow.push_back({wczytany,statystyki[wczytany].size()});
        statystyki[wczytany].push_back(i);
        numery_domow.insert(wczytany);
    }

    for (int i = 0; i < n; ++i)
    {
        // Binary search ostatniego <= i+t.
        long long kolor = idxy_domow[i].wartosc;
        long long p = idxy_domow[i].idx - 1;
        long long k = statystyki[kolor].size();
        long long s = 0;
        long long szukana = i + t;
        while (k - p != 1)
        {
            long long s = (p+k) / 2;
            if (statystyki[kolor][s] > szukana)
            {
                k = s;
            }
            else
            {
                p = s;
            }
        }
        wynik += p - idxy_domow[i].idx;
    }

    cout << wynik;
    return 0;
}