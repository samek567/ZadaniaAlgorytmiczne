#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a,b) for (int a = 0; a < (b); ++a)
#define pb push_back
#define all(t) t.begin(),t.end()

int n = 0, q = 0, v = 0, x = 0;
const int max_N = 2e5, max_POW = 29;
int A[max_N];
int skok[max_N+1][max_POW+1];

inline int zapytanie()
{
    cin >> v >> x;
    --v;
    int ile = (1 << max_POW);
    for (int i = max_POW; i >= 0 and x > 0; --i)
    {
        if (x >= ile)
        {
            v = skok[v][i];
            x -= ile;
        }
        ile /= 2;
    }
    return v + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    rep(i,n) cin >> A[i];

    rep(i,n) skok[i][0] = A[i]-1;
    for (int i = 1; i <= max_POW; ++i) rep(j,n) skok[j][i] = skok[skok[j][i-1]][i-1];
    while(q--)
        cout << zapytanie() << '\n';

    return 0;
}