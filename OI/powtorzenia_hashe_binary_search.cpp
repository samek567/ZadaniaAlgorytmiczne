#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n = 0, max_size = 0;
long long mod = 1e9+7, p = 199, sum = 0;
string wczytane_slowo;
vector<long long> POW;
vector<string> slowa;
vector<vector<long long>> hashe_prefiksowe;

bool czy_wystepuje(int x)
{
    // Dla kazdego slowa naliczamy set i mamy jeden spolny map.
    map<long long,int> stat; // Hash,ile

    for (int i = 0; i < n; ++i)
    {
        set<long long> S;
        if (slowa[i].size() < x)
        {
            return false;
        }
        for (int j = 0; j <= slowa[i].size() - x; ++j)
        {
            long long suma_na_przedziale = 0;
            if (j == 0)
            {
                suma_na_przedziale = hashe_prefiksowe[i][j+x-1];
            }
            else
            {
                suma_na_przedziale = (hashe_prefiksowe[i][j+x-1] - hashe_prefiksowe[i][j-1] + mod) % mod;
            }
            suma_na_przedziale = (suma_na_przedziale * POW[max_size-j-1]) % mod;
            S.insert(suma_na_przedziale);
        }

        for (auto j : S)
        {
            stat[j]++;
        }
    }

    for (auto i : stat)
    {
        if (i.second == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytane_slowo;
        max_size = max(max_size,(int)wczytane_slowo.size());
        slowa.push_back(wczytane_slowo);
    }

    POW.push_back(1);
    for (int i = 1; i < max_size; ++i)
    {
        POW.push_back((POW[i-1] * p) % mod);
    }

    for (int i = 0; i < n; ++i)
    {
        sum = 0;
        hashe_prefiksowe.push_back({});
        for (int j = 0; j < slowa[i].size(); ++j)
        {
            sum = (sum + (long long)slowa[i][j] * POW[j]) % mod;
            hashe_prefiksowe[i].push_back(sum);
        }
    }

    int poczatek = -1, koniec = max_size+1, srodek = 0;
    while (koniec-poczatek != 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_wystepuje(srodek) == true)
        {
            poczatek = srodek;
        }
        else
        {
            koniec = srodek;
        }
    }

    cout << poczatek;

    return 0;
}
