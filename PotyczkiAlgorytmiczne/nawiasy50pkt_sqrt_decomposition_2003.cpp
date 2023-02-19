#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, k = 3, ile_przedzialow = 0, wczytana_liczba = 0, sum = 0;
string ciag;
vector<int> stat;
vector<int> min_przedzial;
vector<int> ile_dodajemy_przedzial;

inline void dodaj(int a, int b, int val)
{
    a--, b--;
    int w_jakim_przedziale_a = a / k, w_jakim_przedziale_b = b / k;

    for (int i = w_jakim_przedziale_a+1; i < w_jakim_przedziale_b; ++i)
        ile_dodajemy_przedzial[i] += val;

    for (int i = a; i <= min(w_jakim_przedziale_a*k+k-1,b); ++i)
        stat[i] += val;

    if (w_jakim_przedziale_a != w_jakim_przedziale_b)
        for (int i = b; i >= w_jakim_przedziale_b*k; --i)
            stat[i] += val;

    min_przedzial[w_jakim_przedziale_a] = 1e9;
    for (int i = w_jakim_przedziale_a*k; i < w_jakim_przedziale_a*k+k; ++i)
        min_przedzial[w_jakim_przedziale_a] = min(min_przedzial[w_jakim_przedziale_a],stat[i]);

    min_przedzial[w_jakim_przedziale_b] = 1e9;
    for (int i = w_jakim_przedziale_b*k; i < w_jakim_przedziale_b*k+k; ++i)
        min_przedzial[w_jakim_przedziale_b] = min(min_przedzial[w_jakim_przedziale_b],stat[i]);
}

inline int odczytaj_min(int a, int b)
{
    a--, b--;
    int wyn = 1e9, w_jakim_przedziale_a = a / k, w_jakim_przedziale_b = b / k;

    for (int i = w_jakim_przedziale_a+1; i < w_jakim_przedziale_b; ++i)
        wyn = min(wyn, ile_dodajemy_przedzial[i] + min_przedzial[i]);

    for (int i = a; i <= min(w_jakim_przedziale_a*k+k-1,b); ++i)
        wyn = min(wyn,stat[i] + min_przedzial[w_jakim_przedziale_a]);

    if (w_jakim_przedziale_a != w_jakim_przedziale_b)
        for (int i = b; i >= w_jakim_przedziale_b*k; --i)
            wyn = min(wyn,stat[i] + min_przedzial[w_jakim_przedziale_b]);

    return wyn;
}

int main()
{
    // O(M*sqrt(N)), sqrt decomposition
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;
    ile_przedzialow = n / k + 1;
    min_przedzial.assign(ile_przedzialow,1e9);
    ile_dodajemy_przedzial.assign(ile_przedzialow,0);
    stat.assign(n+2*k,0);
    for (int i = 0; i < n; ++i)
    {
        if (ciag[i] == '(')
            sum++;
        else
            sum--;
        stat[i] = sum;
    }
    for (int i = 0; i < n; ++i)
        min_przedzial[i/k] = min(min_przedzial[i/k],stat[i]);

    cin >> m;
    while(m--)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba == 0)
        {
            if (odczytaj_min(1,n) == 0 && stat[n-1] + ile_dodajemy_przedzial[(n-1) / k] == 0)
                cout << "TAK" << '\n';
            else
                cout << "NIE" << '\n';
        }
        else
        {
            if (ciag[wczytana_liczba-1] == '(')
            {
                ciag[wczytana_liczba-1] = ')';
                dodaj(wczytana_liczba,n,-2);
            }
            else
            {
                ciag[wczytana_liczba-1] = '(';
                dodaj(wczytana_liczba,n,2);
            }
        }
    }

    return 0;
}
