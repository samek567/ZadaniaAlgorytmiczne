#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n = 0, m = 0;
ll mod = 1e9+7, p = 199, hash_wzorzec = 0, suma = 0;
char wczytany_znak;
vector<int> POW;
vector<int> hashe_prefiksowe;

int main()
{
    // Znajdz wzorzec w tekscie.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    POW.push_back(1);
    for (int i = 1; i < m; ++i)
    {
        POW.push_back(((ll)POW[i-1] * (ll)p) % (ll)mod);
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak;
        hash_wzorzec = ((ll)hash_wzorzec + (ll)wczytany_znak * (ll)POW[i]) % mod;
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> wczytany_znak;
        suma = ((ll)suma + (ll)wczytany_znak * (ll)POW[i]) % mod;
        hashe_prefiksowe.push_back(suma);
    }

    for (int i = 0; i <= m-n; ++i)
    {
        int suma_na_przedziale = 0;
        if (i == 0)
        {
            suma_na_przedziale = hashe_prefiksowe[i+n-1];
        }
        else
        {
            suma_na_przedziale = (hashe_prefiksowe[i+n-1] - hashe_prefiksowe[i-1] + mod) % mod;
        }
        if (((ll)hash_wzorzec * (ll)POW[i]) % mod == suma_na_przedziale)
        {
            cout << i+1 << '\n';
        }
    }

    return 0;
}