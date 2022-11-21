#include <iostream>
#include <vector>
#include <algorithm>

struct Czynnosc
{
    long long t;
    long long kiedy_koniec;

    bool operator < (const Czynnosc &czynnosc) const
    {
        if (kiedy_koniec == czynnosc.kiedy_koniec)
        {
            return t > czynnosc.t;
        }
        return kiedy_koniec > czynnosc.kiedy_koniec;
    }
};

using namespace std;

int n = 0;
long long wczytane_t = 0, wczytany_kiedy_koniec = 0, wynik = 0;
vector<Czynnosc> czynnosci;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytane_t >> wczytany_kiedy_koniec;
        czynnosci.push_back({wczytane_t,wczytany_kiedy_koniec});
    }

    sort(czynnosci.begin(), czynnosci.end());

    wynik = czynnosci[0].kiedy_koniec - czynnosci[0].t;

    for (int i = 1; i < n; ++i)
    {
        if (wynik >= czynnosci[i].kiedy_koniec)
        {
            wynik = czynnosci[i].kiedy_koniec - czynnosci[i].t;
        }
        else
        {
            wynik -= czynnosci[i].t;
        }
    }

    cout << wynik << '\n';

    return 0;
}
