#include <iostream>
#include <vector>

using namespace std;

int n = 0, base = (1 << 15), rozmiar_drzewa = base * 2, poczatek = 0, koniec = 0, srodek = 0, wczytana_liczba = 0;
vector<int> drzewo_przedzialowe;
vector<int> wyn;
vector<int> A;

inline void update(int val, int v) // zwykly update w drzewie przedzialowym punkt-przedzial, O(lg N)
{
    v += base;
    drzewo_przedzialowe[v] = val;
    v /= 2;
    while(v > 0)
    {
        drzewo_przedzialowe[v] = drzewo_przedzialowe[v*2] + drzewo_przedzialowe[v*2+1];
        v /= 2;
    }
}

inline int szukaj_idx(int v, int ile_mamy, int ktorej_szukamy) // Bin search od gory, O(lg N)
{
    if (v >= base)
        return v-base;
    if (ile_mamy + drzewo_przedzialowe[v*2] >= ktorej_szukamy)
        return szukaj_idx(v*2,ile_mamy,ktorej_szukamy);
    else
        return szukaj_idx(v*2+1,ile_mamy+drzewo_przedzialowe[v*2],ktorej_szukamy);
}

int main()
{
    // O(N lg N), kodujemy zachlanie od tylu.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    A.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    drzewo_przedzialowe.assign(rozmiar_drzewa,0);
    wyn.assign(n,-1);

    for (int i = 1; i <= n; ++i)
        drzewo_przedzialowe[i+base] = 1;
    for (int i = base-1; i > 0; --i)
        drzewo_przedzialowe[i] = drzewo_przedzialowe[i*2] + drzewo_przedzialowe[i*2+1];

    int cnt = 0;
    for (int i = n-1; i >= 0; --i)
    {
        if (A[i] >= n-cnt)
        {
            cout << "NIE" << '\n';
            return 0;
        }
        int val = szukaj_idx(1,0,n-A[i]-cnt);
        ++cnt;
        wyn[i] = val;
        update(0,val);
    }

    for (int i = 0; i < n; ++i)
        cout << wyn[i] << '\n';

    return 0;
}
