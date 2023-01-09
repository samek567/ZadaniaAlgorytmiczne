#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    int wysokosc;
    int idx;
    bool operator < (const Element &element) const
    {
        return wysokosc < element.wysokosc;
    }
};

int n = 0, wczytana_liczba = 0, ile_czesci = 1, max_wysokosc = 0, wsk_elementy = 0;
vector<int> wysokosci;
vector<bool> czy_zatonela;
vector<Element> elementy;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    czy_zatonela.assign(n,false);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        wysokosci.push_back(wczytana_liczba);
        elementy.push_back({wczytana_liczba,i});
        max_wysokosc = max(max_wysokosc,wczytana_liczba);
    }
    sort(elementy.begin(),elementy.end());
    if (n == 1)
    {
        for (int i = 0; i < max_wysokosc; ++i)
            printf("1 ");
        printf("0");
        return 0;
    }
    printf("1 ");
    for (int i = 1; i <= max_wysokosc; ++i)
    {
        for (int j = wsk_elementy; j < n; ++j)
        {
            if (elementy[j].wysokosc != i)
                break;
            if (elementy[j].idx == 0)
            {
                if (czy_zatonela[elementy[j].idx+1] == true)
                    ile_czesci--;
            }
            else if (elementy[j].idx == n-1)
            {
                if (czy_zatonela[elementy[j].idx-1] == true)
                    ile_czesci--;
            }
            else
            {
                if (czy_zatonela[elementy[j].idx-1] == true && czy_zatonela[elementy[j].idx+1] == true)
                    ile_czesci--;
                if (czy_zatonela[elementy[j].idx-1] == false && czy_zatonela[elementy[j].idx+1] == false)
                    ile_czesci++;
            }
            czy_zatonela[elementy[j].idx] = true;
            wsk_elementy++;
        }
        printf("%d ",ile_czesci);
    }
    return 0;
}