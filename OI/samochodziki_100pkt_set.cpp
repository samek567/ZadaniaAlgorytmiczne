#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Element_seta
{
    int idx_najdalsze;
    int kolor;
    bool operator < (const Element_seta &element_seta) const
    {
        if (idx_najdalsze == element_seta.idx_najdalsze)
            return kolor < element_seta.kolor;
        return idx_najdalsze > element_seta.idx_najdalsze;
    }
};

int n = 0, k = 0, p = 0, wczytana_liczba = 0, wyn = 0, ile_zapas = 0;
vector<int> stat;
vector<int> idx_kolejny;
vector<int> samochodziki;
vector<int> najdalszy_idx_danego_koloru_na_secie;
vector<bool> czy_jest_w_secie;
set<Element_seta> S;

int main()
{
    // Set / kolejka priorytetowa. O(N lg N). Skoro elementy sa do miliona, to mozna zamiast seta drzewo przedzialowe.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> p;
    stat.assign(n+1,1e8);
    czy_jest_w_secie.assign(n+1,false);
    idx_kolejny.assign(p,-1);
    najdalszy_idx_danego_koloru_na_secie.assign(n+1,-1);
    for (int i = 0; i < p; ++i)
    {
        cin >> wczytana_liczba;
        samochodziki.push_back(wczytana_liczba);
    }
    for (int i = p-1; i >= 0; --i)
    {
        idx_kolejny[i] = stat[samochodziki[i]];
        stat[samochodziki[i]] = i;
    }

    for (int i = 0; i < p; ++i)
    {
        if (czy_jest_w_secie[samochodziki[i]] == true) // Aktualizujemy najdalszy, zeby nie bylo tak, ze i > najdalszy
        {
            auto it = S.find({najdalszy_idx_danego_koloru_na_secie[samochodziki[i]],samochodziki[i]});
            S.erase({*it});
            najdalszy_idx_danego_koloru_na_secie[samochodziki[i]] = idx_kolejny[i];
            S.insert({idx_kolejny[i],samochodziki[i]});
        }
        else
        {
            wyn++;
            if (S.size() == k)
            {
                czy_jest_w_secie[S.begin()->kolor] = false;
                S.erase(*S.begin());
            }
            S.insert({idx_kolejny[i],samochodziki[i]});
            czy_jest_w_secie[samochodziki[i]] = true;
            najdalszy_idx_danego_koloru_na_secie[samochodziki[i]] = idx_kolejny[i];
        }
    }

    cout << wyn << '\n';

    return 0;
}
