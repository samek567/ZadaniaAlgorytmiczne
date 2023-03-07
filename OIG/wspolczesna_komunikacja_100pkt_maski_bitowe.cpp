#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, k = 0, sum = 0;
ll wyn = 0;
string ciag;
vector<int> stat;

int main()
{
    // Maski bitowe, operacje bitowe
    // (N*K + (2^k)*(2^k)), przyspieszamy bruta w O(N^2), zauwazajac, ze k jest male, a n duze.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    stat.assign((1 << k),0);
    for (int i = 0; i < n; ++i)
    {
        cin >> ciag;
        sum = 0;
        for (int j = 0; j < ciag.size(); ++j)
            if (ciag[j] == '1')
                sum += (1 << (k-j-1));
        stat[sum]++;
    }

    for (int i = 1; i < (1 << k); ++i)
        if (stat[i] > 1)
            wyn += (ll)(stat[i]-1) * (ll)stat[i] / 2;

    for (int i = 1; i < (1 << k); ++i)
        for (int j = i+1; j < (1 << k); ++j)
            if ((i & j) > 0)
                wyn += (ll)stat[i] * (ll)stat[j];

    cout << wyn << '\n';

    return 0;
}
