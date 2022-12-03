#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, a_i = 0, d_i = 0, l_i = 0, pozycja = 0;
vector<int> kontenery;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    kontenery.assign(n+1,0);

    for (int i = 0; i < k; ++i)
    {
        cin >> a_i >> d_i >> l_i; // Od jakiej pozycji, ile, co_ile
        pozycja = a_i;
        for (int j = 0; j < d_i; ++j)
        {
            kontenery[pozycja]++;
            pozycja += l_i;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", kontenery[i]);
    }

    return 0;
}
