#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Punkt
{
    int wartosc;
    int idx;

    bool operator < (const Punkt&punkt) const
    {
        return idx < punkt.idx;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int wynik = 0;

    cin >> n;
    Punkt liczby[n+1];
    liczby[0] = {0,0};

    for (int i = 1; i <= n; ++i)
    {
        cin >> liczby[i].wartosc;
        liczby[i].idx = i;
    }
    sort(liczby,liczby+n+1);

    int max_wyn = 0;
    for (int i = 1; i <= n; ++i)
    {
        max_wyn = max(max_wyn,liczby[i].wartosc);
        if (max_wyn == i)
        {
            wynik++;
        }
    }

    cout << wynik;
    return 0;
}