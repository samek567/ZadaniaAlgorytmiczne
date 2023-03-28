#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, p = 43, mod = 1e9+7, hash1 = 0, hash2 = 0, hash3 = 0;
string ciag;
vector<int> hashe_prefixowe;
vector<int> POW;

int main()
{
    // O(N), hashe
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;

    hashe_prefixowe.assign(n,-1);
    POW.assign(n,-1);

    POW[0] = 1;
    for (int i = 1; i < n; ++i)
        POW[i] = ((ll)POW[i-1] * (ll)p + (ll)mod) % (ll)mod;

    hashe_prefixowe[0] = (int)ciag[0];
    for (int i = 1; i < n; ++i)
        hashe_prefixowe[i] = ((ll)hashe_prefixowe[i-1] + (ll)ciag[i] * (ll)POW[i] + (ll)mod) % (ll)mod;

    for (int i = n; i >= 1; --i)
    {
        if (3*i > n)
            continue;
        hash1 = ((ll)hashe_prefixowe[i-1] * (ll)POW[2*i] + (ll)mod) % (ll)mod, hash2 = ((((ll)hashe_prefixowe[2*i-1] - (ll)hashe_prefixowe[i-1] + (ll)mod) % (ll)mod) * (ll)POW[i] + (ll)mod) % (ll)mod, hash3 = ((ll)hashe_prefixowe[3*i-1] - (ll)hashe_prefixowe[2*i-1] + (ll)mod) % (ll)mod;
        if (hash1 == hash2 and hash1 == hash3)
        {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "0" << '\n';

    return 0;
}