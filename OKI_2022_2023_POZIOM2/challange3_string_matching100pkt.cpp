#include <iostream>
#include <vector>

using namespace std;

string ciag1, ciag2;
long long hash_wzorzec = 0, p = 199, mod = 1e9+7, sum = 0, wyn = 0;
vector<long long> POW;
vector<long long> hashe_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag1 >> ciag2;
    POW.push_back(1);
    for (int i = 1; i < ciag1.size(); ++i)
    {
        POW.push_back((POW[i-1] * p) % mod);
    }
    for (int i = 0; i < ciag1.size(); ++i)
    {
        sum = (sum + (int)ciag1[i] * POW[i]) % mod;
        hashe_prefiksowe.push_back(sum);
    }
    for (int i = 0; i < ciag2.size(); ++i)
    {
        hash_wzorzec = (hash_wzorzec + (int)ciag2[i] * POW[i]) % mod;
    }

    for (int i = 0; i <= ciag1.size() - ciag2.size(); ++i)
    {
        long long suma_hashowa = 0;
        if (i == 0)
            suma_hashowa = hashe_prefiksowe[ciag2.size()-1];
        else
            suma_hashowa = (hashe_prefiksowe[i + ciag2.size() - 1] - hashe_prefiksowe[i-1] + mod) % mod;
        if ((hash_wzorzec * POW[i]) % mod == suma_hashowa)
            wyn++;
    }

    printf("%d",wyn);

    return 0;
}