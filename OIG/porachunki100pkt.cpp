#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

int n = 0, a = 0, b = 0, maxx = 0;
ll sum = 0;
unordered_map<ll,int> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        sum += (b - a);
        stat[sum]++;
        maxx = max(maxx, stat[sum]);
    }

    cout << n - maxx << '\n';

    return 0;
}