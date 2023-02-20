#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Element
{
    int wartosc;
    int idx;
    bool operator < (const Element &element) const
    {
        return wartosc < element.wartosc;
    }
};

int n = 0, m = 0, wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0;
vector<int> liczby;
vector<Element> elementy;
vector<int> jaki_idx;

inline bool czy_pasuje(int x)
{
    int maxx = 0, ile[n+1] = {0}, stat[n+1] = {0};
    for (int i = 0; i < x; ++i)
    {
        if (stat[jaki_idx[i]] != 0)
        {
            stat[jaki_idx[i]]++;
            ile[stat[jaki_idx[i]]]++;
            maxx = max(maxx, stat[jaki_idx[i]]);
        }
        else
        {
            stat[jaki_idx[i]] = 1;
            ile[1]++;
            maxx = max(maxx,1);
        }
    }

    if (x - maxx <= m)
        return true;

    for (int i = x; i < n; ++i)
    {
        if (stat[jaki_idx[i]] != 0)
        {
            stat[jaki_idx[i]]++;
            ile[stat[jaki_idx[i]]]++;
            maxx = max(maxx, stat[jaki_idx[i]]);
        }
        else
        {
            stat[jaki_idx[i]] = 1;
            ile[1]++;
            maxx = max(maxx,1);
        }

        ile[stat[jaki_idx[i-x]]]--;
        if (ile[stat[jaki_idx[i-x]]] == 0 && maxx == stat[jaki_idx[i-x]])
            maxx--;
        stat[jaki_idx[i-x]]--;

        if (x - maxx <= m)
            return true;
    }
    return false;
}

int main()
{
    // O(N lg N)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    jaki_idx.assign(n,-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        elementy.push_back({wczytana_liczba,i});
    }
    sort(elementy.begin(),elementy.end());
    jaki_idx[elementy[0].idx] = 0;
    for (int i = 1; i < n; ++i)
    {
        if (elementy[i].wartosc == elementy[i-1].wartosc)
            jaki_idx[elementy[i].idx] = jaki_idx[elementy[i-1].idx];
        else
            jaki_idx[elementy[i].idx] = i;
    }

    poczatek = 0, koniec = n+1;
    while(koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_pasuje(srodek) == true)
            poczatek = srodek;
        else
            koniec = srodek;
    }

    cout << poczatek << '\n';

    return 0;
}
