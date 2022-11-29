#include <iostream>
#include <vector>

using namespace std;

int n = 0, q = 0, wczytana_liczba = 0, x = 0, y = 0, k = 0, p = 0;
vector<int> liczby;
vector<int> dlugosc_podciagu;

void przesuwaj_koniec()
{
    dlugosc_podciagu[k] = max(dlugosc_podciagu[k],p - k + 1);
    k++;
}


int main()
{
    // Lecimy gasienica i O(n+q)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    dlugosc_podciagu.assign(n,-1);

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    while(p >= k)
    {
        if (p == n-1) // Przesuwamy tyl gasienicy
        {
            przesuwaj_koniec();
        }
        else if (p == k)
        {
            p++;
        }
        else if ((liczby[p+1] - liczby[p] != liczby[p] - liczby[p-1] && p != k))
        {
            przesuwaj_koniec();
        }
        else
        {
            p++;
        }
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> x >> y;
        x--;
        y--;
        if (dlugosc_podciagu[x] == -1)
        {
            printf("NIE \n");
        }
        else if (dlugosc_podciagu[x] >= y - x + 1)
        {
            printf("TAK \n");
        }
        else
        {
            printf("NIE \n");
        }
    }

    return 0;
}