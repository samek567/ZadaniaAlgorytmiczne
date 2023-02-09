#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, wczytana_liczba = 0, numer_spojnej = 0, wyn = 0;
vector<int> krawedz;
vector<int> w_jakiej_jest_spojnej;

void DFS(int v)
{
    w_jakiej_jest_spojnej[v] = numer_spojnej;
    if (krawedz[v] == 0)
    {
        wyn++;
        return;
    }
    if (w_jakiej_jest_spojnej[krawedz[v]] == -1)
        DFS(krawedz[v]);
    else if (w_jakiej_jest_spojnej[krawedz[v]] ==  numer_spojnej)
        wyn++;
}

int main()
{
    // O(N + K) DFS-y i silnie spojne
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    krawedz.assign(n+1,0);
    w_jakiej_jest_spojnej.assign(n+1,-1);
    for (int i = 0; i < n; ++i)
        cin >> krawedz[i+1];
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> wczytana_liczba;
        if (w_jakiej_jest_spojnej[wczytana_liczba] == -1)
        {
            DFS(wczytana_liczba);
            numer_spojnej++;
        }
    }
    cout << wyn << '\n';
    return 0;
}