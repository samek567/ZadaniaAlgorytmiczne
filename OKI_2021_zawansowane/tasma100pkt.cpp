#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, wyn = 0;
vector<int> liczby;
set<int> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    while (m--)
    {
        liczby.clear();
        S.clear();
        wyn = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> wczytana_liczba;
            liczby.push_back(wczytana_liczba);
        }
        for (int i = 0; i < n; ++i)
        {
            if (auto it = S.find(liczby[i]) == S.end())
            {
                S.insert(liczby[i]);
                for (int j = n-1; j > i; --j)
                {
                    if (liczby[i] != liczby[j])
                    {
                        wyn = max(wyn,j-i);
                        break;
                    }
                }
            }
        }
        if (wyn != 0)
            cout << wyn << '\n';
        else
            cout << "BRAK" << '\n';
    }
    return 0;
}