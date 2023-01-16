#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int d = 0, a = 0, b = 0, suma = 0;
vector<ll> stat(1e6+1,1);
vector<int> sumy_prefiksowe(1e6+1,0);

int main()
{
    // O(n log n)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i <= 1e6; ++i)
    {
        for (int j = i + i; j <= 1e6; j += i)
            stat[j] *= i;
    }
    for (int i = 2; i <= 1e6; ++i)
    {
        if (stat[i] == i)
            suma++;
        sumy_prefiksowe[i] = suma;
    }
    cin >> d;
    for (int i = 0; i < d; ++i)
    {
        cin >> a >> b;
        printf("%d\n",sumy_prefiksowe[b] - sumy_prefiksowe[a-1]);
    }
    return 0;
}