#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n = 0, p = 0, k = 0, wynik = 1, t = 0, wczytana_liczba = 0;
bool czy_zmieniamy_k = false;
vector<int> liczby;
multiset<int> S;

int main()
{
    // 90 pkt, bo problem z pamiecia w 3 testach nie przechodzi pamiec. Set jest bardzo pamiecio zerny. Czasowo przechodzi. Trzeba zmienic na kolejke monotonniczna.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    while (p < n - 1)
    {
        if (czy_zmieniamy_k == false)
        {
            S.insert(liczby[p]);
        }
        auto it_max = S.rbegin();
        auto it_min = S.begin();

        if (abs(liczby[p+1] - *it_max) <= t && abs(liczby[p+1] - *it_min) <= t)
        {
            p++;
            wynik = max(wynik, p-k+1);
            czy_zmieniamy_k = false;
        }
        else
        {
            S.erase(S.lower_bound(liczby[k]));
            k++;
            if (k > p)
            {
                p = k;
                czy_zmieniamy_k = false;
            }
            else
            {
                czy_zmieniamy_k = true;
            }
        }
    }

    cout << wynik << "\n";

    return 0;
}
