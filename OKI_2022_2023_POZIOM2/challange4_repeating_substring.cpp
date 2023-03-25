#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Element
{
    long long hash1;
    long long hash2;
    bool operator < (const Element &element) const
    {
        if (hash1 == element.hash1)
            return hash2 < element.hash2;
        return hash1 < element.hash1;
    }
};

string ciag;
long long p = 314159, mod1 = 1e9+7, mod2 = 1e9+5, poczatek = 0, koniec = 0, srodek = 0, idx_wyn = -1;
vector<long long> POW_mod1;
vector<long long> POW_mod2;
vector<long long> hashe_prefiksowe_mod1;
vector<long long> hashe_prefiksowe_mod2;

inline bool czy_pasuje(int x)
{
    map<Element,long long> stat;
    for (int i = 0; i <= ciag.size() - x; ++i)
    {
        Element suma_hashowa = {0,0};
        if (i == 0)
            suma_hashowa = {hashe_prefiksowe_mod1[x-1],hashe_prefiksowe_mod2[x-1]};
        else
            suma_hashowa = {(hashe_prefiksowe_mod1[i+x-1] - hashe_prefiksowe_mod1[i-1] + mod1) % mod1,(hashe_prefiksowe_mod2[i+x-1] - hashe_prefiksowe_mod2[i-1] + mod2) % mod2};
        suma_hashowa = {(suma_hashowa.hash1 * POW_mod1[ciag.size()-i-1]) % mod1,(suma_hashowa.hash2 * POW_mod2[ciag.size()-i-1]) % mod2};
        if (auto it = stat.find(suma_hashowa) != stat.end())
        {
            idx_wyn = i;
            return true;
        }
        else
            stat.insert({suma_hashowa,1});
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag;
    POW_mod1.push_back(1);
    for (int i = 1; i < ciag.size(); ++i)
        POW_mod1.push_back((POW_mod1[i-1] * p) % mod1);

    POW_mod2.push_back(1);
    for (int i = 1; i < ciag.size(); ++i)
        POW_mod2.push_back((POW_mod2[i-1] * p) % mod2);

    hashe_prefiksowe_mod1.push_back((long long)ciag[0]);
    for (int i = 1; i < ciag.size(); ++i)
        hashe_prefiksowe_mod1.push_back((hashe_prefiksowe_mod1[i-1] + (long long)ciag[i] * POW_mod1[i]) % mod1);

    hashe_prefiksowe_mod2.push_back((long long)ciag[0]);
    for (int i = 1; i < ciag.size(); ++i)
        hashe_prefiksowe_mod2.push_back((hashe_prefiksowe_mod2[i-1] + (long long)ciag[i] * POW_mod2[i]) % mod2);

    poczatek = 0;
    koniec = ciag.size()+1;
    srodek = 0;
    while (koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_pasuje(srodek) == true)
            poczatek = srodek;
        else
            koniec = srodek;
    }
    if (idx_wyn == -1)
        printf("-1");
    else
        for (int i = idx_wyn; i < idx_wyn + poczatek; ++i)
            printf("%c",ciag[i]);

    return 0;
}
