#include <iostream>
#include <vector>

using namespace std;

int n = 0, p = 0, r = 0, a = 0, b = 0, ile_SCC = 0, wyn = 0;
vector<vector<int>> krawedzie;
vector<vector<int>> krawedzie_odwrocone;
vector<int> koszty;
vector<int> kolejnosc_pre_order;
vector<bool> czy_bylismy;
vector<int> w_jakiej_jest_SCC;
vector<bool> czy_wchodzi_krawedz;
vector<int> min_koszt_SCC;
vector<vector<int>> jakie_wierzcholki_sa_w_danej_SCC;
vector<int> jakie_SCC_sa_zle;

void DFS (int v)
{
    czy_bylismy[v] = true;
    for (int i = 0; i < krawedzie[v].size(); ++i)
        if (czy_bylismy[krawedzie[v][i]] == false)
            DFS(krawedzie[v][i]);
    kolejnosc_pre_order.push_back(v);
}

void DFS_SCC(int v)
{
    w_jakiej_jest_SCC[v] = ile_SCC;
    for (int i = 0; i < krawedzie_odwrocone[v].size(); ++i)
        if (w_jakiej_jest_SCC[krawedzie_odwrocone[v][i]] == -1)
            DFS_SCC(krawedzie_odwrocone[v][i]);
}

int main()
{
    // O(N+R+P)
    // 10.02.2023r, Jeden test na szkopule, tam gdzie wypisuje sie NIE, jest niepoprawny(nie wystarczy wypisac dowolnego, tylko trzeba wypisac najmniejszy). W tamtym tescie wynik to, NIE, 2
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;
    czy_bylismy.assign(n+1,false);
    w_jakiej_jest_SCC.assign(n+1,-1);
    koszty.assign(n+1,-1);
    krawedzie.assign(n+1,{});
    krawedzie_odwrocone.assign(n+1,{});
    for (int i = 0; i < p; ++i)
    {
        cin >> a >> b;
        koszty[a] = b;
    }
    cin >> r;
    for (int i = 0; i < r; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie_odwrocone[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
        if (czy_bylismy[i] == false)
            DFS(i);

    for (int i = n-1; i >= 0; --i)
    {
        int spr = kolejnosc_pre_order[i];
        if (w_jakiej_jest_SCC[spr] == -1)
        {
            DFS_SCC(spr);
            ile_SCC++;
        }
    }

    czy_wchodzi_krawedz.assign(ile_SCC,false);
    min_koszt_SCC.assign(ile_SCC,1e9);
    jakie_wierzcholki_sa_w_danej_SCC.assign(ile_SCC,{});

    for (int i = 1; i <= n; ++i)
        jakie_wierzcholki_sa_w_danej_SCC[w_jakiej_jest_SCC[i]].push_back(i);

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < krawedzie[i].size(); ++j)
            if (w_jakiej_jest_SCC[i] != w_jakiej_jest_SCC[krawedzie[i][j]])
                czy_wchodzi_krawedz[w_jakiej_jest_SCC[krawedzie[i][j]]] = true;

    for (int i = 1; i <= n; ++i)
        if (koszty[i] != -1)
            min_koszt_SCC[w_jakiej_jest_SCC[i]] = min(min_koszt_SCC[w_jakiej_jest_SCC[i]],koszty[i]);

    for (int i = 0; i < ile_SCC; ++i)
    {
        if (czy_wchodzi_krawedz[i] == false)
        {
            if (min_koszt_SCC[i] == 1e9)
                jakie_SCC_sa_zle.push_back(i);
            wyn += min_koszt_SCC[i];
        }
    }

    if (jakie_SCC_sa_zle.size() == 0)
        cout << "TAK" << '\n' << wyn << '\n';
    else
    {
        int min_wierzholek = 1e9;
        for (int i = 0; i < jakie_SCC_sa_zle.size(); ++i)
        {
            int spr = jakie_SCC_sa_zle[i];
            for (int j = 0; j < jakie_wierzcholki_sa_w_danej_SCC[spr].size(); ++j)
                min_wierzholek = min(min_wierzholek,jakie_wierzcholki_sa_w_danej_SCC[spr][j]);
        }
        cout << "NIE" << '\n' << min_wierzholek << '\n';
    }

    return 0;
}
