#include <iostream>
#include <algorithm>

using namespace std;

struct Element
{
    int wartosc;
    int idx;

    bool operator < (const Element&element) const
    {
        return wartosc < element.wartosc;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int max_wynik = 0;
    int liczba_wysp = 1;
    int wskaznik_tab = 0;

    cin >> n;
    Element wyspy[n];
    bool czy_zatonela[n];
    for (int i = 0; i < n; ++i)
    {
        czy_zatonela[i] = false;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> wyspy[i].wartosc;
        wyspy[i].idx = i;
        max_wynik = max(max_wynik,wyspy[i].wartosc);
    }

    sort(wyspy,wyspy+n);

    cout << "1 ";

    for (int i = 1; i <= max_wynik; ++i)
    {
        for (int j = wskaznik_tab; j < n; ++j)
        {
            if (wyspy[j].wartosc > i)
            {
                wskaznik_tab = j;
                break;
            }
            else if (wyspy[j].wartosc == i)
            {
                if (wyspy[j].idx > 0 && wyspy[j].idx < n-1)
                {
                    if (czy_zatonela[wyspy[j].idx - 1] == true && czy_zatonela[wyspy[j].idx + 1] == true)
                    {
                        liczba_wysp--;
                    }
                    else if (czy_zatonela[wyspy[j].idx - 1] == false && czy_zatonela[wyspy[j].idx + 1] == false)
                    {
                        liczba_wysp++;
                    }
                }
                else
                {
                    if (wyspy[j].idx == 0 && czy_zatonela[wyspy[j].idx+1] == true)
                    {
                        liczba_wysp--;
                    }
                    else if (wyspy[j].idx == n-1 && czy_zatonela[wyspy[j].idx-1] == true)
                    {
                        liczba_wysp--;
                    }
                }
                czy_zatonela[wyspy[j].idx] = true;
            }
        }
        cout << liczba_wysp << " ";
    }
    return 0;
}