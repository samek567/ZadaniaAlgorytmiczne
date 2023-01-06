#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, poczatek = 0, koniec = 0, srodek = 0, wyn = 0, szerokosc = 0, ile_wyn = 0;
char wczytany_znak;
vector<vector<char>> dzialka;
vector<vector<int>> stat;

bool czy_pasuje(int x)
{
    for (int i = 0; i < n; ++i)
    {
        szerokosc = 0;
        for (int j = 0; j < m; ++j)
        {
            if (stat[i][j] >= x)
                szerokosc++;
            else
            {
                if (szerokosc >= x)
                    return true;
                szerokosc = 0;
            }
        }
        if (szerokosc >= x)
            return true;
    }
    return false;
}

int main()
{
    // O(n^2 * log n) Binary search po wyniku
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        dzialka.push_back({});
        stat.push_back({});
        for (int j = 0; j < m; ++j)
        {
            cin >> wczytany_znak;
            dzialka[i].push_back(wczytany_znak);
            stat[i].push_back(0);
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            if (dzialka[j][i] == '.')
                sum++;
            else
                sum = 0;
            stat[j][i] = sum;
        }
    }

    poczatek = -1;
    koniec = min(n,m)+1;
    while (koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_pasuje(srodek) == true)
            poczatek = srodek;
        else
            koniec = srodek;
    }
    wyn = poczatek;

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
                    ile_wyn += szerokosc - wyn + 1;
                szerokosc = 0;
            }
        }
        if (szerokosc >= wyn)
            ile_wyn += szerokosc - wyn + 1;
    }

    printf("%d %d",wyn,ile_wyn);

    return 0;
}
