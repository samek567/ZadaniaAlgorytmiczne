#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, k = 0, wczytana_liczba = 0;
vector<int> liczby;
long long wyn_zlote = 0;

int main()
{
    // O(n log n)
    // Zawsze dajemy srebne do najwiekszych.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    sort(liczby.begin(),liczby.end(),greater<int>());
    for (int i = k; i < n; ++i)
        wyn_zlote += liczby[i];
    printf("%lld",max((long long)liczby[0],wyn_zlote));
    return 0;
}