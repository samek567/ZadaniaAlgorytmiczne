#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

struct Element
{
    int wartosc;
    int ile;
    bool operator < (const Element &element) const
    {
        return wartosc > element.wartosc;
    }
};

int n = 0, m = 0, a = 0, b = 0, wyn = 0;
ll wyn_ile = 0;
vector<vector<int>> krawedzie;
vector<int> dp;
vector<int> dp_ile;
vector<int> parent;
vector<Element> vect;
queue<int> Q;
vector<int> visited;

inline pair<int,int> DFS (int v, int rodzic)
{
    parent[v] = rodzic;
    if (krawedzie[v].size() == 1 and v != 1)
    {
        dp[v] = 0;
        dp_ile[v] = 1;
    }
    else
    {
        int maxx = 0, max_ile = 0;
        for (int i = 0; i < krawedzie[v].size(); ++i)
        {
            int wierz = krawedzie[v][i];
            if (wierz == rodzic)
                continue;
            pair<int,int> child = DFS(wierz,v);
            if (child.first == maxx)
                max_ile += child.second;
            else if (child.first > maxx)
            {
                maxx = child.first, max_ile = child.second;
            }
        }
        dp[v] = maxx + 1, dp_ile[v] = max_ile;
    }
    return {dp[v],dp_ile[v]};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    if (n == 1)
    {
        cout << "0" << '\n' << "1" << '\n';
        return 0;
    }


    krawedzie.assign(n+1,{});
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    if (m == n)
    {
        if (n > 5000)
        {
            cout << "NIE" << '\n';
            return 0;
        }
        visited.assign(n+1,-1);
        for (int i = 1; i <= n; ++i)
        {
            fill(visited.begin(), visited.end(), -1);
            visited[i] = 0;
            Q.push(i);
            while(!Q.empty())
            {
                int v = Q.front();
                Q.pop();
                for (int j = 0; j < krawedzie[v].size(); ++j)
                {
                    int wierz = krawedzie[v][j];
                    if (visited[wierz] == -1)
                    {
                        Q.push(wierz);
                        visited[wierz] = visited[v] + 1;
                        if (visited[wierz] == wyn)
                            wyn_ile++;
                        else if (visited[wierz] > wyn)
                        {
                            wyn = visited[wierz];
                            wyn_ile = 1;
                        }
                    }
                }
            }
        }
        cout << wyn << '\n' << wyn_ile / (ll)2 << '\n';
        return 0;
    }

    // dp na drzewie, to jest wzorcowe
    dp.assign(n+1,0);
    parent.assign(n+1,-1);
    dp_ile.assign(n+1,0);

    DFS(1,0);

    for (int i = 1; i <= n; ++i)
    {
        wyn = max(wyn, dp[i]);
        int maxx1 = -1, maxx2 = -1;
        for (int j = 0; j < krawedzie[i].size(); ++j)
        {
            int v = krawedzie[i][j];
            if (v == parent[i])
                continue;
            if (dp[v] > maxx1)
            {
                maxx2 = maxx1, maxx1 = dp[v];
            }
            else if (dp[v] > maxx2)
                maxx2 = dp[v];
        }
        wyn = max(wyn, maxx1 + maxx2 + 2);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (dp[i] == wyn)
            wyn_ile += dp_ile[i];
        vect.clear();
        for (int j = 0; j < krawedzie[i].size(); ++j)
        {
            int v = krawedzie[i][j];
            if (v == parent[i])
                continue;
            vect.push_back({dp[v], dp_ile[v]});
        }
        sort(vect.begin(), vect.end());
        if (vect[0].wartosc + vect[1].wartosc + 2 != wyn)
            continue;
        if (vect.size() >= 2)
        {
            int val1 = vect[0].wartosc, val2 = -1, suma1 = 0, suma2 = 0;
            for (int j = 0; j < vect.size(); ++j)
            {
                if (vect[j].wartosc == val1)
                    suma1 += vect[j].ile;
                else if (suma2 == 0)
                {
                    val2 = vect[j].wartosc, suma2 += vect[j].ile;
                }
                else if (val2 == vect[j].wartosc)
                    suma2 += vect[j].ile;
                else
                    break;
            }
            if (vect[0].wartosc == vect[1].wartosc)
            {
                ll dod = 0;
                for (int j = 0; j < vect.size(); ++j)
                {
                    if (vect[0].wartosc == vect[j].wartosc)
                        dod += (ll)vect[j].ile * (ll)(suma1 - vect[j].ile);
                    else
                        break;
                }
                wyn_ile += dod / (ll)2;
            }
            else
            {
                ll dod = 0;
                for (int j = 0; j < vect.size(); ++j)
                {
                    if (vect[0].wartosc == vect[j].wartosc)
                        dod += (ll)vect[j].ile * (ll)suma2;
                    else
                        break;
                }
                wyn_ile += dod;
            }
        }
    }

    cout << wyn << '\n' << wyn_ile << '\n';

    return 0;
}