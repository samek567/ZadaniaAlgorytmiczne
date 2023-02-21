#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, wyn = 0;
vector<int> zapalki;
vector<int> dp_malejaca_lewo;
vector<int> dp_malejaca_prawo;

int main()
{
    // O(N)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dp_malejaca_lewo.assign(n,0);
    dp_malejaca_prawo.assign(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        zapalki.push_back(wczytana_liczba);
    }

    for (int i = 0; i < n; i+=0)
    {
        int cnt = 1;
        for (int j = i+1; j < n; ++j)
        {
            if (zapalki[j-1] >= zapalki[j])
                cnt++;
            else
                break;
        }
        for (int j = 0; j < cnt; ++j)
            dp_malejaca_prawo[i+j] = cnt - j;
        i += cnt;
    }
    for (int i = n-1; i >= 0; i+=0)
    {
        int cnt = 1;
        for (int j = i-1; j >= 0; --j)
        {
            if (zapalki[j] <= zapalki[j+1])
                cnt++;
            else
                break;
        }
        for (int j = 0; j < cnt; ++j)
            dp_malejaca_lewo[i-j] = cnt - j;
        i -= cnt;
    }
    for (int i = 0; i < n; ++i)
        wyn = max(wyn,dp_malejaca_lewo[i] + dp_malejaca_prawo[i] - 1);
    cout << wyn << '\n';

    return 0;
}