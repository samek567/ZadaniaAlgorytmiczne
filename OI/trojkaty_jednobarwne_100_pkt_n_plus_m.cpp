#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, a_i = 0, b_i = 0;
long long wyn = 0, ile_roznych = 0;
vector<long long> ile_szarych;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    ile_szarych.assign(n+1,0);

    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        ile_szarych[a_i]++;
        ile_szarych[b_i]++;
    }

    for (int i = 1; i <= n; ++i)
    {
        ile_roznych += (ile_szarych[i] * (n - 1 - ile_szarych[i]));
    }
    ile_roznych /= 2;

    wyn = n * (n-1) * (n-2) / 6 - ile_roznych;

    cout << wyn << '\n';

    return 0;
}
