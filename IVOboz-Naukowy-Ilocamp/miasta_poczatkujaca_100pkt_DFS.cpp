#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, ile = 0;
vector<bool> czy_bylismy, czy_idzie_w_prawo, czy_idzie_w_lewo;
vector<int> wyn;

void DFS_prawo(int v)
{
    ile++;
    czy_bylismy[v] = true;
    if (czy_idzie_w_prawo[v] == true)
        if (czy_bylismy[v+1] == false)
            DFS_prawo(v+1);
}

void DFS_lewo(int v)
{
    ile++;
    czy_bylismy[v] = true;
    if (czy_idzie_w_lewo[v] == true)
        if (czy_bylismy[v-1] == false)
            DFS_lewo(v-1);
}

int main()
{
    // O(N), rozlewamy sie DFS-ami
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n;
    czy_bylismy.assign(n+1,false);
    czy_idzie_w_lewo.assign(n+1,false);
    czy_idzie_w_prawo.assign(n+1,false);
    wyn.assign(n+1,0);

    for (int i = 0; i < n-1; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba == 0)
            czy_idzie_w_prawo[i+1] = true;
        else if (wczytana_liczba == 1)
            czy_idzie_w_lewo[i+2] = true;
        else
        {
            czy_idzie_w_prawo[i+1] = true;
            czy_idzie_w_lewo[i+2] = true;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (czy_bylismy[i] == false)
        {
            ile = 0;
            DFS_prawo(i);
            for (int j = 0; j < ile; ++j)
                wyn[i+j] += ile - j - 1;
        }
    }

    fill(czy_bylismy.begin(),czy_bylismy.end(), false);



    for (int i = n; i >= 1; --i)
    {
        if (czy_bylismy[i] == false)
        {
            ile = 0;
            DFS_lewo(i);
            for (int j = 0; j < ile; ++j)
                wyn[i-j] += ile - j - 1;
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << wyn[i] << ' ';

    return 0;
}