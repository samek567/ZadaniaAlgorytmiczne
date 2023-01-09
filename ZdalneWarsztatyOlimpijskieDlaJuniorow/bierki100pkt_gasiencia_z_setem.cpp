#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n = 0, wczytana_liczba = 0, wyn = 0;
vector<int> liczby;
multiset<int> w_gasienicy;

int main()
{
    // O(n log n) Gasienica z setem
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
        if (w_gasienicy.size() <= 1)
            w_gasienicy.insert(liczby[i]);
        else
        {
            auto it = w_gasienicy.begin();
            ++it;
            if (*w_gasienicy.begin() + *it > liczby[i])
                w_gasienicy.insert(liczby[i]);
            else
            {
                w_gasienicy.erase(w_gasienicy.lower_bound(liczby[i - w_gasienicy.size()]));
                i--;
            }
        }
        wyn = max(wyn,(int)w_gasienicy.size());
    }
    printf("%d",wyn);
    return 0;
}