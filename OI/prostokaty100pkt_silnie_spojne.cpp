#include <iostream>
#include <vector>

using namespace std;

struct Prostokat
{
    int y1;
    int y2;
    int x1;
    int x2;
};

int n = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, ile_spojnych = 0;
vector<Prostokat> prostokaty;
vector<bool> czy_bylismy;

inline bool czy_przecinaja(int i, int j)
{
    // Te 4 if-y sprawdzaja czy sie przecinaja w jednym punkcie.
    if (prostokaty[i].y2 == prostokaty[j].y1 and prostokaty[i].x1 == prostokaty[j].x2)
        return false;
    if (prostokaty[i].y2 == prostokaty[j].y1 and prostokaty[i].x2 == prostokaty[j].x1)
        return false;
    if (prostokaty[i].y1 == prostokaty[j].y2 and prostokaty[i].x1 == prostokaty[j].x2)
        return false;
    if (prostokaty[i].y1 == prostokaty[j].y2 and prostokaty[i].x2 == prostokaty[j].x1)
        return false;

    if (prostokaty[i].x2 < prostokaty[j].x1) // prostokat i jest po lewej od prostokata j
        return false;
    if (prostokaty[i].x1 > prostokaty[j].x2) // prostokat i jest na prawo od prostokata j
        return false;
    if (prostokaty[i].y2 < prostokaty[j].y1) // prostokat i jest ponizej prostokata j
        return false;
    if (prostokaty[i].y1 > prostokaty[j].y2) // prostokat i jest wyzej od prostokata j
        return false;

    return true;
}

inline void DFS (int v)
{
    czy_bylismy[v] = true;
    for (int i = 0; i < n; ++i)
        if (czy_bylismy[i] == false and (czy_przecinaja(v,i) == true or czy_przecinaja(i,v) == true))
            DFS(i);
}

int main()
{
    // O(N^2), podzial grafu na silnie spojne.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    czy_bylismy.assign(n,false);

    for (int i = 0; i < n; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        prostokaty.push_back({y1,y2,x1,x2});
    }

    for (int i = 0; i < n; ++i)
    {
        if (czy_bylismy[i] == false)
        {
            DFS(i);
            ile_spojnych++;
        }
    }

    cout << ile_spojnych << '\n';

    return 0;
}