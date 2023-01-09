#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n = 0, wczytana_liczba = 0;
ll wyn = 0;
vector<int> liczby;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        wyn += wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    sort(liczby.begin(),liczby.end());
    for (int i = 0; i < n/2; ++i)
        wyn += liczby[n-i-1] - liczby[i];
    printf("%lld",wyn);
    return 0;
}