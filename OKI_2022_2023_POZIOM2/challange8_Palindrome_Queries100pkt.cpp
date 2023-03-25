#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long n = 0, m = 0, a = 0, b = 0, c = 0, base = 0, rozmiar_drzewa = 0, mod = 1e9+7, p = 199;
string ciag;
char wczytany_znak = 0;
vector<long long> POW;
vector<long long> drzewo_przedzialowe_od_lewej;
vector<long long> drzewo_przedzialowe_od_prawej;

void update_drzewo_lewe (long long v, char x)
{
    long long vall = (long long)x * POW[v];
    v = v + base;
    drzewo_przedzialowe_od_lewej[v] = vall % mod;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe_od_lewej[v] = (drzewo_przedzialowe_od_lewej[v * 2] + drzewo_przedzialowe_od_lewej[v * 2 + 1]) % mod;
        v /= 2;
    }
}
void update_drzewo_prawe (long long v, char x)
{
    long long vall = (long long)x * POW[n - v - 1];
    v = v + base;
    drzewo_przedzialowe_od_prawej[v] = vall % mod;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe_od_prawej[v] = (drzewo_przedzialowe_od_prawej[v * 2] + drzewo_przedzialowe_od_prawej[v * 2 + 1]) % mod;
        v /= 2;
    }
}

long long querry_drzewo_lewe(long long pocz, long long kon)
{
    long long poczatek = pocz + base - 1;
    long long koniec = kon + base + 1;
    long long sum = 0;
    while (poczatek / 2 != koniec / 2)
    {
        if (poczatek % 2 == 0)
            sum = (sum + drzewo_przedzialowe_od_lewej[poczatek + 1]) % mod;
        if (koniec % 2 == 1)
            sum = (sum + drzewo_przedzialowe_od_lewej[koniec - 1]) % mod;
        poczatek /= 2;
        koniec /= 2;
    }
    return sum;
}

long long querry_drzewo_prawe(long long pocz, long long kon)
{
    long long poczatek = pocz + base - 1;
    long long koniec = kon + base + 1;
    long long sum = 0;
    while (poczatek / 2 != koniec / 2)
    {
        if (poczatek % 2 == 0)
            sum = (sum + drzewo_przedzialowe_od_prawej[poczatek + 1]) % mod;
        if (koniec % 2 == 1)
            sum = (sum + drzewo_przedzialowe_od_prawej[koniec - 1]) % mod;
        poczatek /= 2;
        koniec /= 2;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    base = (1 << (int(ceil((double)log2(n)))));
    rozmiar_drzewa = base * 2;
    drzewo_przedzialowe_od_lewej.assign(rozmiar_drzewa,0);
    drzewo_przedzialowe_od_prawej.assign(rozmiar_drzewa,0);
    cin >> ciag;
    POW.push_back(1);
    for (int i = 1; i < ciag.size(); ++i)
    {
        POW.push_back((POW[i-1] * p) % mod);
    }

    for (int i = 0; i < n; ++i)
    {
        drzewo_przedzialowe_od_lewej[i + base] = ((long long)ciag[i] * POW[i]) % mod;
    }
    for (int i = base - 1; i > 0; --i)
        drzewo_przedzialowe_od_lewej[i] = (drzewo_przedzialowe_od_lewej[i * 2] + drzewo_przedzialowe_od_lewej[i * 2 + 1]) % mod;

    for (int i = 0; i < n; ++i)
        drzewo_przedzialowe_od_prawej[i + base] = ((long long)ciag[i] * POW[n-i-1]) % mod;
    for (int i = base - 1; i > 0; --i)
        drzewo_przedzialowe_od_prawej[i] = (drzewo_przedzialowe_od_prawej[i * 2] + drzewo_przedzialowe_od_prawej[i * 2 + 1]) % mod;

    for (int i = 0; i < m; ++i)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b >> wczytany_znak;
            update_drzewo_lewe(b-1,wczytany_znak);
            update_drzewo_prawe(b-1,wczytany_znak);
        }
        else
        {
            cin >> b >> c;
            --b;
            --c;
            long long querry_lewo = (querry_drzewo_lewe(b,c) + mod) % mod, querry_prawo = (querry_drzewo_prawe(b,c) + mod) % mod, roznica = 0;
            roznica = abs(b - (n-c-1));
            if (b < n-c-1)
                querry_lewo = ((querry_lewo + mod) * POW[roznica]) % mod;
            if (b > n-c-1)
                querry_prawo = ((querry_prawo + mod) * POW[roznica]) % mod;
            if (querry_lewo == querry_prawo)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}