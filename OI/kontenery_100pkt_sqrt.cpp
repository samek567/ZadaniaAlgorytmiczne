#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct Element
{
    int poczatek;
    int co_ile_skacze;
    int do_kiedy_skacze;
};

int n = 0, g = 0, K = 220, a = 0, l = 0, d = 0;
vector<int> ile;
vector<Element> elementy;

int main()
{
    // Sqrt. Zauwazamy, ze jak d_i >= K, to mozemy sobie pozlowic na skakanie, a jak jest mniejsze, to sprawdzamy malo kandydatow.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> g;
    ile.assign(n+1,0);
    while(g--)
    {
        cin >> a >> l >> d;
        if (d >= K)
        {
            for (int i = 0; i < l; ++i)
                ile[a + i * d]++;
        }
        else
            elementy.push_back({a,d,a + (l-1) * d});
    }

    for (int i = 1; i < K; ++i)
    {
        multiset<int> S[i];
        vector<int> stat[n+1];
        for (int j = 0; j < elementy.size(); ++j)
            if (elementy[j].co_ile_skacze == i)
                stat[elementy[j].poczatek].push_back(elementy[j].do_kiedy_skacze);
        for (int j = 1; j <= n; ++j)
        {
            int idx = j%i;
            for (int k = 0; k < stat[j].size(); ++k)
                S[idx].insert(stat[j][k]);
            while (!S[idx].empty())
            {
                if (*S[idx].begin() < j)
                    S[idx].erase(*S[idx].begin());
                else
                    break;
            }
            ile[j] += S[idx].size();
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ile[i] << ' ';

    return 0;
}