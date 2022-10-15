#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element
{
    int idx;
    int liczba_ruchow;
    bool czy_C;
};

struct Element2
{
    int idx;
    int liczba_ruchow;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int m = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int wczytane_p = 0;
    int wczytane_k = 0;
    queue<Element> Q;

    cin >> n >> m;
    vector<int> relacje[n+1];
    vector<bool> wierzcholki;
    for (int i = 0; i <= n; ++i)
    {
        wierzcholki.push_back(false);
    }


    for (int i = 0; i < m; ++i)
    {
        cin >> wczytane_p >> wczytane_k;
        relacje[wczytane_p].push_back(wczytane_k);
        relacje[wczytane_k].push_back(wczytane_p);
    }

    cin >> a >> b >> c;

    queue<Element2> BFS;
    vector<bool> wierzcholki_C;
    for (int i = 0; i <= n; ++i)
    {
        wierzcholki_C.push_back(false);
    }
    wierzcholki_C[a] = true;
    BFS.push({a,0});

    int wyn = 0;
    bool czy_kon = false;
    while (!BFS.empty() && czy_kon == false)
    {
        for (int i = 0; i < relacje[BFS.front().idx].size(); ++i)
        {
            if (wierzcholki_C[relacje[BFS.front().idx][i]] == false)
            {
                if (relacje[BFS.front().idx][i] == c)
                {
                    wyn = BFS.front().liczba_ruchow+1;
                    czy_kon = true;
                    break;
                }
                else
                {
                    BFS.push({relacje[BFS.front().idx][i],BFS.front().liczba_ruchow+1});
                }
            }
            wierzcholki_C[relacje[BFS.front().idx][i]] = true;
        }
        BFS.pop();
    }

    queue<Element2> BFS_2;
    vector<bool> wierzcholki_C_2;
    for (int i = 0; i <= n; ++i)
    {
        wierzcholki_C_2.push_back(false);
    }
    wierzcholki_C_2[c] = true;
    BFS_2.push({c,0});

    czy_kon = false;
    while (!BFS_2.empty() && czy_kon == false)
    {
        for (int i = 0; i < relacje[BFS_2.front().idx].size(); ++i)
        {
            if (wierzcholki_C_2[relacje[BFS_2.front().idx][i]] == false)
            {
                if (relacje[BFS_2.front().idx][i] == b)
                {
                    wyn += BFS_2.front().liczba_ruchow+1;
                    czy_kon = true;
                    break;
                }
                else
                {
                    BFS_2.push({relacje[BFS_2.front().idx][i],BFS_2.front().liczba_ruchow+1});
                }
            }
            wierzcholki_C_2[relacje[BFS_2.front().idx][i]] = true;
        }
        BFS_2.pop();
    }

    Q.push({a,0,false});
    wierzcholki[a] = true;
    while (!Q.empty())
    {
        for (int i = 0; i < relacje[Q.front().idx].size(); ++i)
        {
            if (wierzcholki[relacje[Q.front().idx][i]] == false)
            {
                if (relacje[Q.front().idx][i] == b)
                {
                    if (Q.front().czy_C == true)
                    {
                        cout << "TAK";
                        return 0;
                    }
                    else
                    {
                        if (wyn > Q.front().liczba_ruchow+1)
                        {
                            cout << "NIE";
                        }
                        else
                        {
                            cout << "TAK";
                        }
                        return 0;
                    }
                }
                else
                {
                    Q.push({relacje[Q.front().idx][i],Q.front().liczba_ruchow+1,Q.front().czy_C});
                    if (relacje[Q.front().idx][i] == c)
                    {
                        Q.back().czy_C = true;
                    }
                }
            }
            wierzcholki[relacje[Q.front().idx][i]] = true;
        }
        Q.pop();
    }
    return 0;
}