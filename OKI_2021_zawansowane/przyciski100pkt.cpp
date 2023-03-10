#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, maxx = 0, t_maxx = 0;
vector<int> przyciski;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    przyciski.assign(n+1,0);
    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba == n+1)
            t_maxx = maxx;
        else
        {
            przyciski[wczytana_liczba] = max(przyciski[wczytana_liczba],t_maxx) + 1;
            maxx = max(maxx,przyciski[wczytana_liczba]);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << max(przyciski[i],t_maxx) << ' ';

    return 0;
}