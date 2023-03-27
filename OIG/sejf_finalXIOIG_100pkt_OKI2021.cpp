#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, m = 0, y = 0, x = 0;
char wczytany_znak;
vector<int> wiersze;
vector<int> kolumny;

int main()
{
    // O(N+M), symulacja
    // tresc zadania: https://szkopul.edu.pl/problemset/problem/Plha_6BH8_14ZptrZOdschts/site/?key=statement
    // OKI: https://www.youtube.com/watch?v=JJzOAD4SBpc&list=PL9BlBU4U-rDPDamT7hFVsONnWDYrn5CEo&index=30
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    wiersze.assign(n+1,0);
    kolumny.assign(n+1,0);

    for (int i = 1; i <= n; ++i)
    {
        wiersze[i] = i-1;
        kolumny[i] = i;
    }

    while(m--)
    {
        cin >> wczytany_znak >> y >> x;
        if (wczytany_znak == 'P')
            cout << (ll)wiersze[y] * (ll)n + (ll)kolumny[x] << '\n';
        else if (wczytany_znak == 'W')
        {
            int val = wiersze[x];
            wiersze[x] = wiersze[y];
            wiersze[y] = val;
        }
        else if (wczytany_znak == 'K')
        {
            int val = kolumny[x];
            kolumny[x] = kolumny[y];
            kolumny[y] = val;
        }
    }

    return 0;
}