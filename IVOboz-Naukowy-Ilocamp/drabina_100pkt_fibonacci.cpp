#include <iostream>
#include <vector>

using namespace std;

int z = 0, x = 0, MOD = (1 << 30), p = 0;
vector<int> FIB;
vector<int> POW;

int main()
{
    // O(Z + 10^6 + 30)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    POW.push_back(1);
    for (int i = 1; i <= 31; ++i)
        POW.push_back(POW[i-1] * 2);

    FIB.push_back(0);
    FIB.push_back(1);
    for (int i = 2; i <= 1e6; ++i)
        FIB.push_back((FIB[i-1] + FIB[i-2]) % MOD);
    cin >> z;

    while(z--)
    {
        cin >> x >> p;
        cout << FIB[x+1] % POW[p] << '\n';
    }

    return 0;
}