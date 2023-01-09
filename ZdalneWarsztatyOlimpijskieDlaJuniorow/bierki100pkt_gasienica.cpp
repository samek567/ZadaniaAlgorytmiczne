#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, wczytana_liczba = 0, wyn = 0, lewy_wsk = 0;
vector<int> liczby;

int main()
{
    // O(n log n) Gasienica
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    sort(liczby.begin(),liczby.end());

    for(int i = 0; i < n; ++i)
    {
        if (i - lewy_wsk > 1)
        {
            if (liczby[lewy_wsk] + liczby[lewy_wsk+1] <= liczby[i]) // Nie da sie ulozyc trojkata.
            {
                lewy_wsk++;
                i--;
            }
        }
        wyn = max(wyn,i - lewy_wsk);
    }
    printf("%d",wyn+1);
    return 0;
}
