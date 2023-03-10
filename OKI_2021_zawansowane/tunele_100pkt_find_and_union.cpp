#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, k = 0, a_i = 0, b_i = 0, ile_spojnych = 0, wyn = 0;
vector<pair<int,int>> krawedzie_wejscie;
vector<int> rep;

int findd(int s)
{
    int numer_przepiecia = 0;
    int v = s;
    while(true)
    {
        if (v == rep[v])
        {
            numer_przepiecia = v;
            break;
        }
        v = rep[v];
    }
    v = s;
    while(true)
    {
        if (v == numer_przepiecia)
            break;
        int syn = rep[v];
        rep[v] = numer_przepiecia;
        v = syn;
    }
    return numer_przepiecia;
}

void unionn(int x, int y)
{
    rep[findd(x)] = findd(y);
}

int main()
{
    // O(N lg N) Union Find. Odwracamy krawedzie i idziemy od tylu klasycznym union findem.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    ile_spojnych = n;
    wyn = m+1;
    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        krawedzie_wejscie.push_back({a_i,b_i});
    }
    for (int i = 0; i <= n; ++i)
        rep.push_back(i);

    for (int i = m-1; i >= 0; --i)
    {
        if (findd(krawedzie_wejscie[i].first) != findd(krawedzie_wejscie[i].second))
        {
            ile_spojnych--;
            unionn(krawedzie_wejscie[i].first, krawedzie_wejscie[i].second);
        }
        if (ile_spojnych == k)
            wyn = i+1;
        else if (ile_spojnych < k)
            break;
    }

    cout << wyn << '\n';

    return 0;
}