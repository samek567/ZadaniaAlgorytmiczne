#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, max_wyn = 0;
vector<int> szczyty;

inline int sprawdzaj(int dlugosc)
{
    int ile_mamy = 0;
    int wyn = 0;
    bool czy_ulozylismy = false;
    for (int i = 0; i < n; ++i)
    {

        if (i != 0 && i != n-1)
            if (szczyty[i] > szczyty[i-1] && szczyty[i] > szczyty[i+1])
                czy_ulozylismy = true;

        ile_mamy++;
        if (ile_mamy == dlugosc)
        {
            if (czy_ulozylismy == true)
                wyn++;
            else
                return -1;
            ile_mamy = 0;
            czy_ulozylismy = false;
        }
    }
    return wyn;
}

int main()
{
    // O(n * sqrt(n))
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        szczyty.push_back(wczytana_liczba);
    }

    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            max_wyn = max(max_wyn, sprawdzaj(i));
            max_wyn = max(max_wyn, sprawdzaj(n/i));
        }
    }

    printf("%d", max_wyn);

    return 0;
}
