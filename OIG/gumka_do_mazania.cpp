#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Wyraz
{
    string ciag;
    int od_ktorego_idx; // Zeby nie kasowac
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int min_wystapienia_i = INT_MAX;
    int licznik_wystapien = 0;
    string wczytany_ciag;
    string wynik;
    vector<Wyraz> wyrazy;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_ciag;
        wyrazy.push_back({wczytany_ciag,0});
    }

    for (char i = 'z'; i >= 'a'; --i)
    {
        min_wystapienia_i = INT_MAX;

        for (int j = 0; j < n; ++j)
        {
            licznik_wystapien = 0;
            for (int k = wyrazy[j].od_ktorego_idx; k < wyrazy[j].ciag.size(); ++k)
            {
                if (wyrazy[j].ciag[k] == i)
                {
                    licznik_wystapien++;
                }
            }
            min_wystapienia_i = min(min_wystapienia_i,licznik_wystapien);
        }

        if (min_wystapienia_i == 0 || min_wystapienia_i == INT_MAX)
        {
            continue;
        }

        for (int h = 0; h < min_wystapienia_i; ++h)
        {
            wynik += i;
        }

        // Przesuwanie idxu wskazywanego.
        for (int f = 0; f < n; ++f)
        {
            int licznik = 0;
            for (int e = wyrazy[f].od_ktorego_idx; e < wyrazy[f].ciag.size(); ++e)
            {
                if (wyrazy[f].ciag[e] == i)
                {
                    licznik++;
                }
                if (licznik >= min_wystapienia_i)
                {
                    wyrazy[f].od_ktorego_idx = e;
                    break;
                }
            }
        }

    }

    vector<string> do_wyniku;
    do_wyniku.push_back("bitek");
    do_wyniku.push_back(wynik);

    sort(do_wyniku.begin(),do_wyniku.end());

    cout << do_wyniku[1];


    return 0;
}