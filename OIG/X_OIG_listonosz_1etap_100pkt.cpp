#include <iostream>
#include <vector>

using namespace std;

struct Miasto
{
    int y;
    int x;
};

int n = 0, m = 0, x_i = 0, y_i = 0, idx_miasta_wczesniejszego = 0, idx_miasta_pozniejszego = 0, sortownia = 0;
long long wynik = 0;
vector<Miasto> miasta;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    miasta.push_back({-1,-1});
    for (int i = 0; i < n; ++i)
    {
        cin >> x_i >> y_i;
        miasta.push_back({y_i,x_i});
    }

    cin >> idx_miasta_wczesniejszego;
    sortownia = idx_miasta_wczesniejszego;

    for (int i = 0; i < m-1; ++i)
    {
        cin >> idx_miasta_pozniejszego;
        wynik += abs(miasta[idx_miasta_wczesniejszego].x - miasta[idx_miasta_pozniejszego].x) + abs(miasta[idx_miasta_wczesniejszego].y - miasta[idx_miasta_pozniejszego].y);
        idx_miasta_wczesniejszego = idx_miasta_pozniejszego;
    }

    idx_miasta_pozniejszego = sortownia;
    wynik += abs(miasta[idx_miasta_wczesniejszego].x - miasta[idx_miasta_pozniejszego].x) + abs(miasta[idx_miasta_wczesniejszego].y - miasta[idx_miasta_pozniejszego].y);

    printf("%lld",wynik);

    return 0;
}