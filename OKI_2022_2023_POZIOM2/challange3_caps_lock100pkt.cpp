#include <iostream>
#include <vector>

using namespace std;

string tekst, wzorzec;
long long p = 199, mod = 1e9+7, wsk = 0, hash_wzorca = 0;
vector<long long> POW;
vector<long long> hashe_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tekst >> wzorzec;
    POW.push_back(1);
    for (int i = 1; i < tekst.size(); ++i)
        POW.push_back((POW[i-1] * p) % mod);
    for (int i = 0; i < wzorzec.size(); ++i)
        hash_wzorca = (hash_wzorca + (long long)wzorzec[i] * POW[i]) % mod;
    hashe_prefiksowe.push_back((long long)tekst[0]);
    for (int i = 1; i < tekst.size(); ++i)
        hashe_prefiksowe.push_back((hashe_prefiksowe[i-1] + (long long)tekst[i] * POW[i]) % mod);
    for (int i = 0; i <= tekst.size() - wzorzec.size(); ++i)
    {
        long long suma_hashowa = 0;
        if (i == 0)
            suma_hashowa = hashe_prefiksowe[wzorzec.size()-1];
        else
            suma_hashowa = (hashe_prefiksowe[i + wzorzec.size()-1] - hashe_prefiksowe[i-1] + mod) % mod;
        if ((hash_wzorca * POW[i]) % mod == suma_hashowa)
        {
            for (int j = max(wsk,(long long)i); j < i + wzorzec.size(); ++j)
                tekst[j] = toupper(tekst[j]);
            wsk = max(wsk,(long long)(i+wzorzec.size()));
        }
    }
    cout << tekst << '\n';

    return 0;
}