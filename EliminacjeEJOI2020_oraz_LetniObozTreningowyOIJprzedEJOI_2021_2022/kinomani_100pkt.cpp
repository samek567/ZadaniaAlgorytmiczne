#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    int x;
    int ile_dodajemy;
    int idx;
    bool operator < (const Element &element) const
    {
        if (x == element.x)
            return ile_dodajemy < element.ile_dodajemy;
        return x < element.x;
    }
};

int n = 0, a = 0, b = 0, bilans = 0, wyn = 0;
vector<Element> elementy;
vector<vector<int>> odtwarzanie;
vector<int> dostepni_kinomani;
vector<int> jaki_numer_kinomana_jest_przy_filmie;

int main()
{
    // O(N lg N), mozna zamiast vectora dostepni_kinomani, uzyc stosu.
    // Zauwazamy, ze zawsze bedzie trzeba uzyc tylu kinomanow, ile jest maksymalnie rownoczesnie odtwarzanych filmow.
    // Podobny motyw wystapil w zadaniu Zbrodnia na Piccadilly Circus z potyczek algorytmicznych.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        elementy.push_back({a,1,i});
        elementy.push_back({b,-1,i});
    }
    sort(elementy.begin(), elementy.end());

    for (int i = 0; i < 2*n; ++i)
    {
        bilans += elementy[i].ile_dodajemy;
        wyn = max(wyn,bilans);
    }

    odtwarzanie.assign(wyn,{});
    for (int i = 0; i < wyn; ++i)
        dostepni_kinomani.push_back(i);
    jaki_numer_kinomana_jest_przy_filmie.assign(n,-1);

    for (int i = 0; i < 2*n; ++i)
    {
        if (elementy[i].ile_dodajemy == 1)
        {
            jaki_numer_kinomana_jest_przy_filmie[elementy[i].idx] = dostepni_kinomani.back();
            odtwarzanie[dostepni_kinomani.back()].push_back(elementy[i].idx);
            dostepni_kinomani.pop_back();
        }
        else
            dostepni_kinomani.push_back(jaki_numer_kinomana_jest_przy_filmie[elementy[i].idx]);
    }


    cout << wyn << '\n';
    for (int i = 0; i < wyn; ++i)
    {
        cout << odtwarzanie[i].size() << ' ';
        for (int j = 0; j < odtwarzanie[i].size(); ++j)
            cout << odtwarzanie[i][j] + 1 << ' ';
        cout << '\n';
    }

    return 0;
}
