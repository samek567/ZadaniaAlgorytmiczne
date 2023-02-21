#include <iostream>

using namespace std;

int n = 0, wczytana_liczba = 0, minn = 1e9+5;

int main()
{
    // O(N), zauwazamy, ze zawsze najbardziej oplaca nam sie wziac jedna liczbe, ta najmniejsza, bo inne i tak nie poprawia sredniej.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        minn = min(minn,wczytana_liczba);
    }

    cout << minn << ".00" << '\n';

    return 0;
}