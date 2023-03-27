#include <iostream>
#include <vector>

using namespace std;

struct Krawedz
{
    int poczatek;
    int koniec;
};

int z = 0, n = 0, k1 = 0, k2 = 0, kandydat_jeden = -1, kandydat_dwa = -1;
bool czy_mamy = false;
vector<Krawedz> krawedzie;

bool czy_przecinaja (Krawedz p1, Krawedz p2)
{
    if (p1.poczatek == p2.poczatek)
        return false;
    if (p1.poczatek < p2.poczatek)
    {
        if (p1.koniec <= p2.poczatek)
            return false;
        if (p1.koniec >= p2.koniec)
            return false;
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> z;
    while (z--)
    {
        cin >> n;
        krawedzie.clear();
        kandydat_jeden = -1, kandydat_dwa = -1;
        czy_mamy = false;

        for (int i = 0; i < n-2; ++i)
        {
            cin >> k1 >> k2;
            krawedzie.push_back({min(k1,k2), max(k1, k2)});
        }

        for (int i = 0; i < n-3 and kandydat_jeden == -1; ++i)
        {
            for (int j = i+1; j < n-2 and kandydat_jeden == -1; ++j)
            {
                if (czy_przecinaja(krawedzie[i], krawedzie[j]) == true or czy_przecinaja(krawedzie[j], krawedzie[i]) == true)
                {
                    kandydat_jeden = i;
                    kandydat_dwa = j;
                }
            }
        }

        for (int i = 0; i < n-3 and czy_mamy == false; ++i)
        {
            if (i == kandydat_jeden)
                continue;
            for (int j = i+1; j < n-2 and czy_mamy == false; ++j)
            {
                if (j == kandydat_jeden)
                    continue;
                if (czy_przecinaja(krawedzie[i], krawedzie[j]) == true or czy_przecinaja(krawedzie[j], krawedzie[i]) == true)
                {
                    cout << krawedzie[kandydat_dwa].poczatek << ' ' << krawedzie[kandydat_dwa].koniec << '\n';
                    czy_mamy = true;
                    break;
                }
            }
        }
        if (czy_mamy == false)
            cout << krawedzie[kandydat_jeden].poczatek << ' ' << krawedzie[kandydat_jeden].koniec << '\n';
    }

    return 0;
}