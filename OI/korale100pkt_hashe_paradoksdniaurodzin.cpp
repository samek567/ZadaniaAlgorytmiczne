#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Element_seta
{
    long long hash1;
    long long hash2;
    bool operator < (const Element_seta & element_seta) const
    {
        if (hash1 == element_seta.hash1)
            return hash2 < element_seta.hash2;
        else
            return hash1 < element_seta.hash1;
    }
};

long long n = 0, wczytana_liczba = 0, max_wyn = 0, p = 314159, mod1 = 1e9+7, mod2 = 1e9+5, ile = 0, ile_znalezlismy = 0;
vector<int> liczby;
vector<long long> hashe_prefiksowe_mod1;
vector<long long> hashe_sufixowe_mod1;
vector<long long> hashe_prefiksowe_mod2;
vector<long long> hashe_sufixowe_mod2;
vector<long long> POW_mod1;
vector<long long> POW_mod2;
vector<int> stat;
set<Element_seta> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //std::size_t h1 = std::hash<std::string>{}(string("ala ma kota"));

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    POW_mod1.push_back(1);
    for (int i = 1; i < n; ++i)
        POW_mod1.push_back((POW_mod1[i-1] * p) % mod1);

    POW_mod2.push_back(1);
    for (int i = 1; i < n; ++i)
        POW_mod2.push_back((POW_mod2[i-1] * p) % mod2);

    hashe_prefiksowe_mod1.push_back(liczby[0]);
    for (int i = 1; i < n; ++i)
        hashe_prefiksowe_mod1.push_back((hashe_prefiksowe_mod1[i-1] + liczby[i] * POW_mod1[i]) % mod1);
    hashe_sufixowe_mod1.assign(n,1);
    hashe_sufixowe_mod1[n-1] = liczby[n-1];
    for (int i = n-2; i >= 0; --i)
        hashe_sufixowe_mod1[i] = (hashe_sufixowe_mod1[i+1] + liczby[i] * POW_mod1[n-i-1]) % mod1;

    hashe_prefiksowe_mod2.push_back(liczby[0]);
    for (int i = 1; i < n; ++i)
        hashe_prefiksowe_mod2.push_back((hashe_prefiksowe_mod2[i-1] + liczby[i] * POW_mod2[i]) % mod2);
    hashe_sufixowe_mod2.assign(n,1);
    hashe_sufixowe_mod2[n-1] = liczby[n-1];
    for (int i = n-2; i >= 0; --i)
        hashe_sufixowe_mod2[i] = (hashe_sufixowe_mod2[i+1] + liczby[i] * POW_mod2[n-i-1]) % mod2;

    for (int i = 1; i <= n; ++i)
    {
        S.clear();
        ile_znalezlismy = 0;
        for (int j = 0; j < n; j+=i)
        {
            if (j+i>n)
                break;
            long long hash_lewo_mod1 = 0;
            long long hash_prawo_mod1 = 0;
            long long hash_lewo_mod2 = 0;
            long long hash_prawo_mod2 = 0;
            long long poz_reverse = (n-1)-(i+j-1);

            if (j == 0)
                hash_lewo_mod1 = hashe_prefiksowe_mod1[i-1] % mod1;
            else
                hash_lewo_mod1 = (hashe_prefiksowe_mod1[j+i-1] - hashe_prefiksowe_mod1[j-1] + mod1) % mod1;
            if (j + i - 1 == n-1)
                hash_prawo_mod1 = hashe_sufixowe_mod1[j] % mod1;
            else
                hash_prawo_mod1 = (hashe_sufixowe_mod1[j] - hashe_sufixowe_mod1[j+i] + mod1) % mod1;
            hash_lewo_mod1 = (hash_lewo_mod1 * POW_mod1[n-j-1]) % mod1;
            hash_prawo_mod1 = (hash_prawo_mod1 * POW_mod1[n-poz_reverse-1]) % mod1;

            if (j == 0)
                hash_lewo_mod2 = hashe_prefiksowe_mod2[i-1] % mod2;
            else
                hash_lewo_mod2 = (hashe_prefiksowe_mod2[j+i-1] - hashe_prefiksowe_mod2[j-1] + mod2) % mod2;
            if (j + i - 1 == n-1)
                hash_prawo_mod2 = hashe_sufixowe_mod2[j] % mod2;
            else
                hash_prawo_mod2 = (hashe_sufixowe_mod2[j] - hashe_sufixowe_mod2[j+i] + mod2) % mod2;
            hash_lewo_mod2 = (hash_lewo_mod2 * POW_mod2[n-j-1]) % mod2;
            hash_prawo_mod2 = (hash_prawo_mod2 * POW_mod2[n-poz_reverse-1]) % mod2;

            auto it_hash_lewo = S.find({hash_lewo_mod1,hash_lewo_mod2});
            auto it_hash_prawo = S.find({hash_prawo_mod1,hash_prawo_mod2});
            if (it_hash_lewo == S.end())
                ile_znalezlismy++;
            else if (it_hash_prawo == S.end())
                ile_znalezlismy++;
            S.insert({hash_lewo_mod1,hash_lewo_mod2});
            S.insert({hash_prawo_mod1,hash_prawo_mod2});
        }
        max_wyn = max(max_wyn,ile_znalezlismy);
        stat.push_back(ile_znalezlismy);
    }

    for (int i = 0; i < n; ++i)
        if (stat[i] == max_wyn)
            ile++;
    printf("%lld %d\n",max_wyn,ile);
    for (int i = 0; i < n; ++i)
        if (stat[i] == max_wyn)
            printf("%d ",i+1);

    return 0;
}
