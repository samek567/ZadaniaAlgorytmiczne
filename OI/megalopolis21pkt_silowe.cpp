#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Wierzcholek
{
    int numer_rodzica;
    int ile_dodajemy_krawedz;
};

int n = 0, m = 0, a = 0, b = 0, z = 0, wynik = -1;
char wczytany_znak;
vector<vector<int>> krawedzie;
vector<Wierzcholek> wierzcholki;
vector<bool> czy_odwiedzone;

void DFS_napelnianie(int v, int numer_rodzica)
{
    czy_odwiedzone[v] = true;
    wierzcholki[v] = {numer_rodzica,1};
    for (int i = 0; i < krawedzie[v].size(); ++i)
        if (czy_odwiedzone[krawedzie[v][i]] == false)
            DFS_napelnianie(krawedzie[v][i],v);
}

void DFS(int v, int wyn)
{
    if (wynik != -1)
        return;
    if (wierzcholki[v].ile_dodajemy_krawedz == 1 && wierzcholki[v].numer_rodzica != -1)
        wyn++;
    if (v == 1)
    {
        wynik = wyn;
        return;
    }
    czy_odwiedzone[v] = true;
    for (int i = 0; i < krawedzie[v].size(); ++i)
        if (czy_odwiedzone[krawedzie[v][i]] == false)
            DFS(krawedzie[v][i],wyn);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n;
    krawedzie.assign(n+1,{});
    wierzcholki.assign(n+1,{-1,-1});
    czy_odwiedzone.assign(n+1,false);
    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }
    DFS_napelnianie(1,-1);
    cin >> m;
    for (int i = 0; i < n+m-1; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'A')
        {
            cin >> a >> b;
            if (wierzcholki[a].numer_rodzica == b)
                wierzcholki[a].ile_dodajemy_krawedz = 0;
            else
                wierzcholki[b].ile_dodajemy_krawedz = 0;
        }
        else
        {
            fill(czy_odwiedzone.begin(),czy_odwiedzone.end(),false);
            cin >> z;
            wynik = -1;
            DFS(z,0);
            printf("%d\n", wynik);
        }
    }
    return 0;
}
