#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Przedzial
{
    int poczatek;
    int koniec;

    bool operator < (const Przedzial &przedzial) const
    {
        if (poczatek == przedzial.poczatek)
        {
            return koniec > przedzial.koniec; // Bez znaczenia
        }
        return poczatek < przedzial.poczatek;
    }
};

int n = 0, a_i = 0, b_i = 0;
vector<Przedzial> przedzialy;
Przedzial wynik;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a_i >> b_i;
        przedzialy.push_back({a_i,b_i});
    }
    sort(przedzialy.begin(),przedzialy.end());

    wynik = {przedzialy[0].poczatek, przedzialy[0].koniec};

    for (int i = 1; i < n; ++i)
    {
        if (przedzialy[i].poczatek <= wynik.koniec)
        {
            wynik.koniec = max(wynik.koniec,przedzialy[i].koniec);
        }
        else
        {
            cout << wynik.poczatek << " " << wynik.koniec << '\n';
            wynik = {przedzialy[i].poczatek,przedzialy[i].koniec};
        }
    }

    cout << wynik.poczatek << " " << wynik.koniec << '\n';

    return 0;
}
