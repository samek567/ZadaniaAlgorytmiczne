#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n = 0, d = 0, wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0, DELTA_SIZE = 4, max_val = 0, ile_mamy = 0;
vector<vector<long long>> liczby;
vector<long long> posortowane_liczby;
vector<vector<bool>> czy_bylismy;
vector<int> delta_X = {0,0,-1,1};
vector<int> delta_Y = {1,-1,0,0};

void DFS(int y, int x)
{
    czy_bylismy[y][x] = true;
    ile_mamy++;
    for (int i = 0; i < DELTA_SIZE; ++i)
    {
        if (y + delta_Y[i] >= 0 && y + delta_Y[i] < n && x + delta_X[i] >= 0 && x + delta_X[i] < n)
        {
            if (liczby[y + delta_Y[i]][x + delta_X[i]] <= max_val && czy_bylismy[y + delta_Y[i]][x + delta_X[i]] == false)
                DFS(y + delta_Y[i], x + delta_X[i]);
        }
    }
}

bool czy_pasuje() // Od max val puszczamy dfs-y.
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            czy_bylismy[i][j] = false;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (czy_bylismy[i][j] == false && liczby[i][j] <= max_val)
            {
                ile_mamy = 0;
                DFS(i,j);
                if (ile_mamy >= d)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    for (int i = 0; i < n; ++i)
    {
        liczby.push_back({});
        czy_bylismy.push_back({});
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytana_liczba;
            posortowane_liczby.push_back(wczytana_liczba);
            liczby[i].push_back(wczytana_liczba);
            czy_bylismy[i].push_back(false);
        }
    }
    sort(posortowane_liczby.begin(),posortowane_liczby.end());

    poczatek = -1;
    koniec = posortowane_liczby.size();

    while (koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        max_val = posortowane_liczby[srodek];
        if (czy_pasuje() == true)
            koniec = srodek;
        else
            poczatek = srodek;
    }

    printf("%lld",posortowane_liczby[koniec]);

    return 0;
}