#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, wczytana_liczba = 0, wyn = 0;
vector<int> krawedzie;
vector<bool> czy_bylismy;

void DFS(int v, int idx_start)
{
    wyn = v;
    if (czy_bylismy[v] == true)
        return;
    czy_bylismy[v] = true;
    DFS(krawedzie[v],idx_start);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    czy_bylismy.assign(n+1,false);
    krawedzie.assign(n+1,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        krawedzie[i+1] = wczytana_liczba;
    }

    for (int i = 1; i <= n; ++i)
    {
        wyn = 0;
        fill(czy_bylismy.begin(),czy_bylismy.end(),false);
        DFS(i,i);
        printf("%d ",wyn);
    }
    return 0;
}
