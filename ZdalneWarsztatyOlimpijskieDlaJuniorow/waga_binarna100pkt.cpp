#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

struct Q
{
    ll p;
    ll q;
    ll m_i;
    Q operator / (const Q &other) const
    {
        return {p * other.q, q * other.p};
    }
    bool operator < (const Q &other) const
    {
        if (p * other.q == other.p * q) // Czy sa rowne
            return m_i < other.m_i;
        return p * other.q < other.p * q;
    }
};

int n = 0, l_i = 0, m_i = 0;
vector<Q> waga;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> l_i >> m_i;
        waga.push_back({l_i,(1 << m_i),m_i});
    }
    sort(waga.begin(),waga.end());
    for (int i = 0; i < n; ++i)
        printf("%lld %lld\n",waga[i].p, waga[i].m_i);
    return 0;
}