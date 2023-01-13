#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, max_wysokosc = 0;
vector<int> wysokosci;
vector<int> wyniki_lewo;
vector<int> wyniki_prawo;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    wyniki_lewo.assign(n+1,0);
    wyniki_prawo.assign(n+1,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        wysokosci.push_back(wczytana_liczba);
    }
    for (int i = 0; i < n; ++i)
    {
        max_wysokosc = max(max_wysokosc,wysokosci[i]);
        wyniki_lewo[i] = max_wysokosc;
    }
    max_wysokosc = 0;
    for (int i = n-1; i >= 0; --i)
    {
        max_wysokosc = max(max_wysokosc,wysokosci[i]);
        wyniki_prawo[i] = max_wysokosc;
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d %d\n",wyniki_lewo[i],wyniki_prawo[i]);
    }

    return 0;
}
