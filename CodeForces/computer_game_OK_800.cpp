#include <iostream>
#include <vector>

using namespace std;

int z = 0, n = 0, delta_SIZE = 8;
bool czy_sie_da = false;
vector<vector<char>> plansza;
vector<vector<bool>> czy_bylismy;
char wczytany_znak;
vector<int> delta_Y = {0,0,1,-1,1,1,-1,-1};
vector<int> delta_X = {1,-1,0,0,1,-1,1,-1};

void DFS(int y, int x)
{
    if (y == 1 && x == n-1)
        czy_sie_da = true;
    if (czy_sie_da == true)
        return;
    czy_bylismy[y][x] = true;
    for (int i = 0; i < delta_SIZE; ++i)
    {
        if (y + delta_Y[i] >= 0 && y + delta_Y[i] < 2 && x + delta_X[i] >= 0 && x + delta_X[i] < n)
            if (czy_bylismy[y + delta_Y[i]][x + delta_X[i]] == false && plansza[y + delta_Y[i]][x + delta_X[i]] == '0')
                DFS(y + delta_Y[i], x + delta_X[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> z;
    for (int i = 0; i < z; ++i)
    {
        cin >> n;
        plansza.clear();
        czy_bylismy.clear();
        czy_sie_da = false;
        for (int j = 0; j < 2; ++j)
        {
            plansza.push_back({});
            czy_bylismy.push_back({});
            for (int k = 0; k < n; ++k)
            {
                cin >> wczytany_znak;
                czy_bylismy[j].push_back(false);
                plansza[j].push_back(wczytany_znak);
            }
        }
        DFS(0,0);
        if (czy_sie_da == true)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}