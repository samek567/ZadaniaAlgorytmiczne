#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a,b) for (int a = 0; a < (b); ++a)
#define pb push_back
#define all(t) t.begin(),t.end()

struct Zdarzenie
{
    int wsp, idx;
};

int n = 0, q = 0, a = 0, b = 0;
const int max_N = 2e5+5, max_Q = 2e5+5;
int A[max_N];
int res[max_Q];
int dp[max_N];
vector<Zdarzenie> Z[max_N];
vector<Zdarzenie> V[max_N];
int wsk_V[max_N];

inline void dziel_i_rzadz(int l, int p)
{
    int s = (l+p) / 2;
    dp[s] = A[s];
    for(int i = s-1; i >= l; --i)
        dp[i] = min(A[i],dp[i+1]);
    for(int i = s+1; i <= p; ++i)
        dp[i] = min(A[i],dp[i-1]);
    for(int i = l; i <= s; ++i)
    {
        while(wsk_V[i] < V[i].size() and V[i][wsk_V[i]].wsp >= s)
        {
            res[V[i][wsk_V[i]].idx] = min(dp[i],dp[V[i][wsk_V[i]].wsp]);
            ++wsk_V[i];
        }
    }
    if(l != p)
    {
        if (l != s)
            dziel_i_rzadz(l,s-1);
        dziel_i_rzadz(s+1,p);
    }
}

int main()
{
    // O(N lg N + Q) static RMQ za pomoca dziel i rzadz bez przekazywania zapytan.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    rep(i,n) cin >> A[i];
    rep(i,q)
    {
        cin >> a >> b;
        --a,--b;
        Z[b].pb({a,i});
    }
    for(int i = n-1; i >= 0; --i)
        rep(j,Z[i].size())
            V[Z[i][j].wsp].pb({i,Z[i][j].idx});
    rep(i,n) wsk_V[i] = 0;
    dziel_i_rzadz(0,n-1);
    rep(i,q) cout << res[i] << '\n';

    return 0;
}