#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Krawedz
{
    int a;
    int b;
    bool operator < (const Krawedz &krawedz) const
    {
        if (a == krawedz.a)
            return b < krawedz.b;
        return a < krawedz.a;
    }
};

int n = 0, m = 0, a_i = 0, b_i = 0, ile = 0;
bool czy_cykl = false;
set<Krawedz> krawedzie_set;
vector<vector<int>> krawedzie;
vector<bool> czy_odwiedzone;

void DFS_czy_spojny(int v)
{
    czy_odwiedzone[v] = true;
    ile++;
    for (int i = 0; i < krawedzie[v].size(); ++i)
        if (czy_odwiedzone[krawedzie[v][i]] == false)
            DFS_czy_spojny(krawedzie[v][i]);
}

void DFS_czy_cykl(int v)
{
    if (czy_cykl == true)
        return;
    czy_odwiedzone[v] = true;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        if (auto it = krawedzie_set.find({v,krawedzie[v][i]}) == krawedzie_set.end() && krawedzie_set.find({krawedzie[v][i],v}) == krawedzie_set.end())
        {
            if (czy_odwiedzone[krawedzie[v][i]] == true)
                czy_cykl = true;
            krawedzie_set.insert({v,krawedzie[v][i]});
            DFS_czy_cykl(krawedzie[v][i]);
        }
    }
}

int main()
{
    // Graf jest drzewem, gdy jest spojny i nie ma cykli. Najpierw sprawdzimy czy jest spojny jednem dfs-em, potem czy nie ma cykli.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    krawedzie.assign(n+1,{});
    czy_odwiedzone.assign(n+1,false);
    if (n - m != 1)
    {
        printf("niedrzewo");
        return 0;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        krawedzie[a_i].push_back(b_i);
        krawedzie[b_i].push_back(a_i);
    }
    DFS_czy_spojny(1);
    if (ile != n)
    {
        printf("niedrzewo");
        return 0;
    }
    fill(czy_odwiedzone.begin(), czy_odwiedzone.end(),false);
    DFS_czy_cykl(1);
    if (czy_cykl == true)
        printf("niedrzewo");
    else
        printf("drzewo");

    return 0;
}