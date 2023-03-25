#include <iostream>
#include <vector>

using namespace std;

int n = 0, poczatek = 0, koniec = 0, srodek = 0, wyn = 0, iloczyn = 1, cnt = 0;
vector<int> wysokosci;
vector<int> lg_pow;
vector<int> najblizsza_potega;
vector<vector<int>> sparse_table;
vector<int> dod;

inline int querry(int l, int p)
{
    int idx = lg_pow[najblizsza_potega[p-l+1]];
    return min(sparse_table[idx][l], sparse_table[idx][p - najblizsza_potega[p-l+1] + 1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    wysokosci.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> wysokosci[i];

    lg_pow.assign(n+1,-1);
    najblizsza_potega.assign(n+1,-1);
    dod.assign(n,4e5+50);

    najblizsza_potega[1] = 1, iloczyn = 2;
    for (int i = 2; i <= n; ++i)
    {
        najblizsza_potega[i] = najblizsza_potega[i-1];
        if (i == iloczyn)
        {
            najblizsza_potega[i] = iloczyn;
            iloczyn *= 2;
        }
    }

    iloczyn = 1, cnt = 0;
    while(iloczyn <= n)
    {
        lg_pow[iloczyn] = cnt;
        cnt++;
        iloczyn *= 2;
    }

    sparse_table.push_back(dod);
    for (int i = 0; i < n; ++i)
        sparse_table[0][i] = wysokosci[i];
    cnt = 1;
    for (int i = 2; i <= n; i *= 2)
    {
        sparse_table.push_back(dod);
        for (int j = 0; j <= n-i; ++j)
            sparse_table[cnt][j] = min(sparse_table[cnt-1][j], sparse_table[cnt-1][j+i/2]);
        ++cnt;
    }

    cnt = 0;
    while(iloczyn <= n)
    {
        lg_pow[iloczyn] = cnt;
        cnt++;
        iloczyn *= 2;
    }

    for (int i = 0; i < n; ++i)
    {
        poczatek = 0, koniec = 4e5+50;
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (i - srodek < 0 or i + srodek >= n or wysokosci[i] < 2*srodek+1)
                koniec = srodek;
            else if (querry(i-srodek, i+srodek) > srodek)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        wyn = max(wyn, poczatek);
    }

    cout << wyn << '\n';

    return 0;
}