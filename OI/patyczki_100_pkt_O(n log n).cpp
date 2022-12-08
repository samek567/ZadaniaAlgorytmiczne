#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Patyczek
{
    int wartosc;
    int kolor;

    bool operator < (const Patyczek &patyczek) const
    {
        if (wartosc == patyczek.wartosc)
        {
            return kolor < patyczek.kolor;
        }
        return wartosc < patyczek.wartosc;
    }
};


int k = 0, n = 0, wczytany_patyczek = 0;
vector<Patyczek> patyczki;


int main()
{
    /*
     1 - Rozwiazanie sie amortyzuje, rozwazmy kolory kolejnych patyczkow:
     Zielony Bialy Czarny Czarny Czarny Czarny Czerwony, to przedzial z kolorow bialy,czarny,czarny,czarny,czarny,czerwony przejrzymy tylko raz.
     2 - O(n log n)
     */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;

    for (int i = 0; i < k; ++i)
    {
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytany_patyczek;
            patyczki.push_back({wczytany_patyczek,i+1});
        }
    }
    sort(patyczki.begin(),patyczki.end());

    for (int i = 0; i < patyczki.size()-1; ++i)
    {
        if (patyczki[i].kolor != patyczki[i+1].kolor)
        {
            int wsk_2 = i+1;
            while(wsk_2 < patyczki.size()-1 && patyczki[wsk_2].kolor == patyczki[wsk_2+1].kolor)
                wsk_2++;
            int wsk_3 = wsk_2+1;

            if (wsk_3 != patyczki.size())
            {
                if (patyczki[i].kolor != patyczki[wsk_3].kolor && patyczki[i].wartosc+patyczki[wsk_2].wartosc>patyczki[wsk_3].wartosc)
                {
                    printf("%d %d %d %d %d %d",patyczki[i].kolor,patyczki[i].wartosc,patyczki[wsk_2].kolor,patyczki[wsk_2].wartosc,patyczki[wsk_3].kolor,patyczki[wsk_3].wartosc);
                    return 0;
                }
            }
        }
    }


    printf("NIE");

    return 0;
}
