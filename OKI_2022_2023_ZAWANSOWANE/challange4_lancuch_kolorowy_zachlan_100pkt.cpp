#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Element
{
    int wartosc;
    int ile_wystapien;

    bool operator < (const Element &element) const
    {
        return wartosc < element.wartosc;
    }
};

int n = 0, m = 0, wczytana_liczba = 0, ile_czesci_mamy = 0;
long long wynik = 0, suma_ladnego_fragmentu = 0;
vector<int> liczby;
vector<int> ile_wystapien;
set<Element> elementy_lancucha;
int statystyki[1000005] {0};

int main()
{
    // Zachlan.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        ile_wystapien.push_back(wczytana_liczba);
        suma_ladnego_fragmentu += wczytana_liczba;
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        statystyki[wczytana_liczba] = ile_wystapien[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    for (int i = 0; i < n; ++i)
    {
        if (statystyki[liczby[i]] == 0)
        {
            ile_czesci_mamy = 0;
            elementy_lancucha.clear();
        }
        else
        {
            auto it = elementy_lancucha.find({liczby[i],0});
            if (it != elementy_lancucha.end()) // Znalezlismy
            {
                if (it->ile_wystapien < statystyki[liczby[i]])
                {
                    elementy_lancucha.erase(it);
                    elementy_lancucha.insert({it->wartosc,it->ile_wystapien+1});
                    ile_czesci_mamy++;
                }
                else
                {
                    if (liczby[i-ile_czesci_mamy] != liczby[i])
                    {
                        ile_czesci_mamy = 0;
                        elementy_lancucha.clear();
                    }
                }
            }
            else
            {
                elementy_lancucha.insert({liczby[i],1});
                ile_czesci_mamy++;
            }
        }
        if (ile_czesci_mamy == suma_ladnego_fragmentu)
        {
            wynik++;
        }
    }


    cout << wynik;

    return 0;
}