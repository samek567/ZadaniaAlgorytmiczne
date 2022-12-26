#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, wczytana_liczba = 0;
vector<int> liczby;

int main()
{
    // O(n log n) xd
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
    for (int i = 0; i < n; ++i)
        printf("%d ",liczby[i]);
    return 0;
}