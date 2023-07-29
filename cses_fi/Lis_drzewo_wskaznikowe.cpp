#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a,b) for (int a = 0; a < (b); ++a)
#define pb push_back
#define all(t) t.begin(),t.end()

struct Node
{
    int l, p, val;
};

int n = 0, wyn = 0;
const int max_N = 2e5+5, max_SIZE = 1e9;
int A[max_N];
vector<Node> tree;

inline int query(int l_zap, int p_zap, int l_kontrolowana, int p_kontrolowana, int v)
{
    if (p_kontrolowana < l_zap or l_kontrolowana > p_zap) return 0;
    if (l_kontrolowana >= l_zap and p_kontrolowana <= p_zap) return tree[v].val;
    int res = 0;
    if (tree[v].l != -1) res = query(l_zap,p_zap,l_kontrolowana,(l_kontrolowana+p_kontrolowana)/2,tree[v].l);
    if (tree[v].p != -1) res = max(res, query(l_zap,p_zap,(l_kontrolowana+p_kontrolowana)/2+1,p_kontrolowana,tree[v].p));
    return res;
}

inline void update(int v_zap, int l_kontrolowana, int p_kontrolowana, int val, int v)
{
    if (v_zap == l_kontrolowana and l_kontrolowana == p_kontrolowana) tree[v].val = val;
    else
    {
        if (v_zap <= (l_kontrolowana+p_kontrolowana) / 2)
        {
            if (tree[v].l == -1)
            {
                tree[v].l = tree.size();
                tree.pb({-1,-1,0});
            }
            update(v_zap,l_kontrolowana,(l_kontrolowana+p_kontrolowana)/2,val,tree[v].l);
        }
        else
        {
            if (tree[v].p == -1)
            {
                tree[v].p = tree.size();
                tree.pb({-1,-1,0});
            }
            update(v_zap,(l_kontrolowana+p_kontrolowana)/2+1,p_kontrolowana,val,tree[v].p);
        }
        int res = 0;
        if (tree[v].l != -1) res = tree[tree[v].l].val;
        if (tree[v].p != -1) res = max(res,tree[tree[v].p].val);
        tree[v].val = res;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    rep(i,n) cin >> A[i];
    tree.pb({-1,-1,0});
    rep(i,n)
    {
        int val = 1 + query(0,A[i]-1,0,max_SIZE,0);
        update(A[i],0,max_SIZE,val,0);
        wyn = max(wyn,val);
    }
    cout << wyn << '\n';

    return 0;
}