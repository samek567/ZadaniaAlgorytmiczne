#include <iostream>
#include <vector>

using namespace std;

int n = 0, wyn = 0;
vector<int> krawedz;
vector<bool> czy_bylismy;

void DFS(int v)
{
    czy_bylismy[v] = true;
    if (czy_bylismy[krawedz[v]] == false)
        DFS(krawedz[v]);
}

int main()
{
    // O(N), liczymy ile jest silnie spojnych
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    krawedz.assign(n+1,0);
    czy_bylismy.assign(n+1,false);

    for (int i = 0; i < n; ++i)
        cin >> krawedz[i+1];

    for (int i = 1; i <= n; ++i)
    {
        if (czy_bylismy[i] == false)
        {
            DFS(i);
            wyn++;
        }
    }

    cout << wyn << '\n';

    return 0;
}