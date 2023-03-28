#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, m = 0;
ll sum = 0, ile_dod = 0;
char wczytany_znak;
vector<int> ile_wiersze;
vector<int> ile_kolumny;
vector<vector<ll>> wyn;

int main()
{
    // O(N^2), najpierw dodajemy wszystkie po X, potem po Y.
    // Zadanie troche podobne do zadania Aquapark z OIG-a.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    ile_kolumny.assign(m,0);
    ile_wiersze.assign(n,0);
    wyn.assign(n,{});
    for (int i = 0; i < n; ++i)
        wyn[i].assign(m,0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> wczytany_znak;
            if (wczytany_znak == '#')
            {
                ile_kolumny[j]++;
                ile_wiersze[i]++;
            }
        }
    }

    sum = 0;
    ile_dod = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            wyn[j][i] += sum;
        ile_dod += ile_kolumny[i];
        sum += ile_dod;
    }

    sum = 0;
    ile_dod = 0;
    for (int i = m-1; i >= 0; --i)
    {
        for (int j = 0; j < n; ++j)
            wyn[j][i] += sum;
        ile_dod += ile_kolumny[i];
        sum += ile_dod;
    }

    sum = 0;
    ile_dod = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            wyn[i][j] += sum;
        ile_dod += ile_wiersze[i];
        sum += ile_dod;
    }

    sum = 0;
    ile_dod = 0;
    for (int i = n-1; i >= 0; --i)
    {
        for (int j = 0; j < m; ++j)
            wyn[i][j] += sum;
        ile_dod += ile_wiersze[i];
        sum += ile_dod;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << wyn[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}