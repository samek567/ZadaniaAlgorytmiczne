#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, m = 0, wynik = 0;
long long wczytana_liczba = 0;
vector<long long> programy;
vector<long long> plyty;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        programy.push_back(wczytana_liczba);
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        plyty.push_back(wczytana_liczba);
    }

    sort(programy.begin(),programy.end());
    sort(plyty.begin(),plyty.end());

    int wskaznik_plyty = 0;
    for (int i = 0; i < n; ++i)
    {
        if (programy[i] <= plyty[wskaznik_plyty])
        {
            wynik++;
        }
        else
        {
            i--;
        }
        wskaznik_plyty++;
        if (wskaznik_plyty == m)
        {
            break;
        }
    }

    cout << wynik;
    return 0;
}