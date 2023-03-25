#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, wyn = 0, numer_spojnej = 0;
vector<int> krawedz;
vector<int> w_jakiej_spojnej;

void DFS(int v)
{
    w_jakiej_spojnej[v] = numer_spojnej;
    if (w_jakiej_spojnej[krawedz[v]] == -1)
        DFS(krawedz[v]);
    else if (w_jakiej_spojnej[krawedz[v]] == numer_spojnej)
        wyn++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    krawedz.assign(n+1,0);
    w_jakiej_spojnej.assign(n+1,-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        krawedz[i+1] = wczytana_liczba;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (w_jakiej_spojnej[i] == -1)
        {
            DFS(i);
            numer_spojnej++;
        }
    }
    cout << wyn << '\n';

    return 0;
}