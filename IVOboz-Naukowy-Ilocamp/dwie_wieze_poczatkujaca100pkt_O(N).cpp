#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, m = 0, wczytana_liczba = 0, wskW1 = 0, wskW2 = 0, wyn = 0;
ll sumaW1 = 0, sumaW2 = 0;
vector<int> W1, W2;

int main()
{
    // O(N), zawsze usuwamy >=, i symulujemy wynik.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        W1.push_back(wczytana_liczba);
        sumaW1 += wczytana_liczba;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        W2.push_back(wczytana_liczba);
        sumaW2 += wczytana_liczba;
    }
    wskW1 = n-1, wskW2 = m-1;
    while(true)
    {
        if (sumaW1 == sumaW2)
            break;
        else if (sumaW1 > sumaW2)
        {
            sumaW1 -= W1[wskW1];
            wskW1--;
        }
        else
        {
            sumaW2 -= W2[wskW2];
            wskW2--;
        }
        wyn++;
    }

    cout << wyn << '\n';

    return 0;
}