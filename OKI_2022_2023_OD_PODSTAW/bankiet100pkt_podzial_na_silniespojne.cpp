#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, ile_spojnych = 0;
vector<int> krawedzie;
vector<bool> czy_odwiedzone;

void DFS(int v)
{
    czy_odwiedzone[v] = true;
    if (czy_odwiedzone[krawedzie[v]] == false)
        DFS(krawedzie[v]);
}

int main()
{
    // O(n) Cale zadanie polega na podzieleniu grafu na silnie spojne. Mozna to zrobic DFS-ami, lub BFS-ami.
    // Najlatwiej DFS-ami rekurencyjnie.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    czy_odwiedzone.assign(n+1,false);
    krawedzie.push_back(-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        krawedzie.push_back(wczytana_liczba);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (czy_odwiedzone[i] == false)
        {
            DFS(i);
            ile_spojnych++;
        }
    }

    printf("%d",ile_spojnych);

    return 0;
}