#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Wiezowiec
{
    int wysokosc;
    int szerokosc;
};

int n = 0, m = 0, wyn = 0, szerokosc = 0, wyn_ile = 0;
char wczytany_znak;
vector<vector<char>> plansza;
vector<vector<int>> stat;
stack<Wiezowiec> S;

inline void przetwarzaj_nizszy_max_wyn(int val)
{
    szerokosc = 0;
    while (!S.empty())
    {
        if (S.top().wysokosc > val)
        {
            szerokosc += S.top().szerokosc;
            wyn = max(wyn,min(szerokosc,S.top().wysokosc));
            S.pop();
        }
        else if (S.top().wysokosc == val)
        {
            szerokosc += S.top().szerokosc;
            S.pop();
        }
        else
            break;
    }
    S.push({val,szerokosc+1});
}

int main()
{
    // O(n * m) stos monotonniczny.
    // Bardzo podobne Plakatowanie XV OI, Dzialka IX OI, Drawing rectangle in histogram SPOJ
    /*
    Najpierw znajdujemy maksymalny bok kwadratu odpalajac algorytm histogramowy na kazdym wierszu(katalog SPOJ na moim repozytorium)
    tak jak w zadaniu dzialka. Potem liczymy latwo ile jest dzialek o boku wyn w i-tym wierszu.
    Co ciekawe to zadanie mozna zrobic w O(n^2*logn) Szukajac dlugosc dzialki binarnie po wyniku, dla dlugosci x sprawdzac prawie
    identycznie jak odtwarzamy ile jest w tym rozwiazaniu. I zliczanie dokladnie tak samo jak w tym.
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        plansza.push_back({});
        stat.push_back({});
        for (int j = 0; j < m; ++j)
        {
            cin >> wczytany_znak;
            plansza[i].push_back(wczytany_znak);
            stat[i].push_back(0);
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            if (plansza[j][i] == '.')
                sum++;
            else
                sum = 0;
            stat[j][i] = sum;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        while(!S.empty())
            S.pop();
        for (int j = 0; j < m; ++j)
        {
            if (S.empty())
                S.push({stat[i][j],1});
            else if (stat[i][j] > S.top().wysokosc)
                S.push({stat[i][j],1});
            else if (stat[i][j] == S.top().wysokosc)
                S.top().szerokosc++;
            else
            {
                przetwarzaj_nizszy_max_wyn(stat[i][j]);
            }
        }
        szerokosc = 0;
        while (!S.empty())
        {
            szerokosc += S.top().szerokosc;
            wyn = max(wyn,min(szerokosc, S.top().wysokosc));
            S.pop();
        }
    }

    for (int i = 0; i < n; ++i)
    {
        szerokosc = 0;
        for (int j = 0; j < m; ++j)
        {
            if (stat[i][j] >= wyn)
                szerokosc++;
            else
            {
                if (szerokosc >= wyn)
                    wyn_ile += szerokosc - wyn + 1;
                szerokosc = 0;
            }
        }
        if (szerokosc >= wyn)
            wyn_ile += szerokosc - wyn + 1;
    }

    printf("%d %d",wyn,wyn_ile);

    return 0;
}
