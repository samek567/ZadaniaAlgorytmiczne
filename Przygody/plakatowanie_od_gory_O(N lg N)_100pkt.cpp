#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Element_seta
{
    int wysokosc;
    int numer;

    bool operator < (const Element_seta &element_seta) const
    {
        if (wysokosc == element_seta.wysokosc)
            return numer < element_seta.numer;
        return wysokosc > element_seta.wysokosc;
    }
};

struct Element_seta_idxy
{
    int wysokosc;
    int numer;
    bool operator < (const Element_seta_idxy &element_seta_idxy) const
    {
        return numer < element_seta_idxy.numer;
    }
};

int n = 0, szerokosc = 0, wysokosc = 0, wynik = 0;
set<Element_seta> S;
set<Element_seta_idxy> idxy;
vector<int> wysokosci;

int main()
{
    // 100pkt Plakatowanie od gory O(n log n)
    // Czesty trik z dwoma setami, ze jak chcemy miec dostep do sasiadow na zmieniajacym sie zbiorze,
    // to robimy 1 set po wartosciach, a drugi po idx-ach
    // Podobny myk z 2 setami w zadaniu wyprzedzanie z 1 etapu XXX OI.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> szerokosc >> wysokosc;
        wysokosci.push_back(wysokosc);
    }

    // Jak usuniemy powtorzenia to beda max 3 obok siebie te same.
    // I nie musimy wtedy zadnych petli usuwania tych samych.
    for (int i = 0; i < n; ++i)
    {
        int ile_tych_samych = 0;
        for (int j = i; j < n; ++j)
        {
            if (wysokosci[i] == wysokosci[j])
                ile_tych_samych++;
            else
                break;
        }
        S.insert({wysokosci[i],(int)S.size()});
        idxy.insert({wysokosci[i],(int)idxy.size()});
        i += ile_tych_samych-1;
    }

    while(true) // Robimy dopoki istnieje element ktory ma chociaz jednego sasiada.
    {
        auto it_w_idxach = idxy.find({-1,S.begin()->numer});
        auto it_jeden_lewo = it_w_idxach;
        auto it_jeden_prawo = it_w_idxach;
        int max_wysokosc_sasiad = 0;
        bool czy_sasiad_lewo_pasuje = false;
        bool czy_sasiad_prawo_pasuje = false;
        if (idxy.begin()->numer != it_w_idxach->numer)
        {
            --it_jeden_lewo;
            max_wysokosc_sasiad = max(max_wysokosc_sasiad,it_jeden_lewo->wysokosc);
        }
        if (idxy.rbegin()->numer != it_w_idxach->numer)
        {
            ++it_jeden_prawo;
            max_wysokosc_sasiad = max(max_wysokosc_sasiad,it_jeden_prawo->wysokosc);
        }

        if (it_jeden_lewo->wysokosc == max_wysokosc_sasiad)
        {
            czy_sasiad_lewo_pasuje = true;
        }
        if (it_jeden_prawo->wysokosc == max_wysokosc_sasiad)
        {
            czy_sasiad_prawo_pasuje = true;
        }

        wynik++;
        if (czy_sasiad_lewo_pasuje == false && czy_sasiad_prawo_pasuje == false)
            break;

        if (czy_sasiad_lewo_pasuje == true && czy_sasiad_prawo_pasuje == true)
        {
            idxy.erase({-1,it_w_idxach->numer});
            S.erase(*S.begin());

            idxy.erase({-1,it_jeden_lewo->numer});
            auto it_delete = S.find({it_jeden_lewo->wysokosc,it_jeden_lewo->numer});
            S.erase(*it_delete);
        }
        else
        {
            idxy.erase({-1,it_w_idxach->numer});
            S.erase(*S.begin());
        }
    }

    printf("%d",wynik);

    return 0;
}