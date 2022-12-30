#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n = 0, k = 0, wczytana_liczba = 0, max_wyn = 0;
vector<int> liczby;
multiset<int> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    for (int i = 0; i <= k; ++i)
    {
        S.insert({liczby[i]});
    }
    auto it = S.end();
    --it;
    --it;
    max_wyn = *it + *S.rbegin();

    for (int i = k+1; i < n; ++i)
    {
        S.insert(liczby[i]);
        S.erase(S.lower_bound(liczby[i-k-1]));
        auto it = S.end();
        --it;
        --it;
        max_wyn = max(max_wyn,*it + *S.rbegin());
    }

    printf("%d",max_wyn);

    return 0;
}
