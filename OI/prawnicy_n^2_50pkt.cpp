#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Prawnik
{
    int poczatek;
    int koniec;
    int numer_prawnika;

    bool operator < (const Prawnik &prawnik) const
    {
        if (poczatek == prawnik.poczatek)
            return koniec < prawnik.koniec;
        return poczatek < prawnik.poczatek;
    }
};

int n = 0, k = 0, a = 0, b = 0, max_wyn = 0, poczatek = 0, koniec = 0, wyn = 0, wskaznik = 0, wyn_i = 0, wyn_j = 0, ile_mamy = 0;
vector<Prawnik> prawnicy;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        prawnicy.push_back({a,b,i+1});
    }
    sort(prawnicy.begin(),prawnicy.end());

    for (int i = 0; i < n; ++i)
    {
        vector<int> pasujace;
        poczatek = prawnicy[i].poczatek;
        wskaznik = 0;
        for (int f = 0; f < n; ++f)
        {
            if (prawnicy[f].poczatek <= poczatek)
            {
                if (prawnicy[f].koniec >= poczatek)
                    pasujace.push_back(prawnicy[f].koniec);
            }
            else
                break;
        }
        sort(pasujace.begin(),pasujace.end());
        if (pasujace.size() >= k)
        {
            koniec = pasujace[pasujace.size()-k];
            if (koniec - poczatek > max_wyn)
            {
                max_wyn = koniec-poczatek;
                wyn_i = poczatek;
                wyn_j = koniec;
            }
        }
    }

    printf("%d \n",max_wyn);
    for (int i = 0; i < n; ++i)
    {
        if (prawnicy[i].poczatek <= wyn_i && prawnicy[i].koniec >= wyn_j && ile_mamy < k)
        {
            printf("%d ",prawnicy[i].numer_prawnika);
            ile_mamy++;
        }
    }

    return 0;
}