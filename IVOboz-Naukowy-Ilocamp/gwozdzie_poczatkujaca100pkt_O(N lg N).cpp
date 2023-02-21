#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, k = 0, wczytana_liczba = 0, ile_powtorzen = 1, wyn = 0;
vector<int> liczby;

int main()
{
    // O(N lg N), sortowanie
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    sort(liczby.begin(),liczby.end());

    for (int i = 1; i < n; ++i)
    {
        if (liczby[i] == liczby[i-1])
            ile_powtorzen++;
        else
        {
            wyn = max(wyn,ile_powtorzen + min((n - i),k));
            ile_powtorzen = 1;
        }
    }

    wyn = max(wyn,ile_powtorzen);

    cout << wyn << '\n';

    return 0;
}