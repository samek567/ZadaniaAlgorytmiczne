#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n = 0, ile_usunietych = 0, wsk_lewy = 0, wsk_prawy = 0, wyn = 0, maxx = 0;
vector<int> liczby;
multiset<int> S;

int main()
{
    // O(N lg N) - zachlan na secie.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    liczby.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];

    S.insert(liczby[0]);
    while(ile_usunietych < n)
    {
        wyn++;
        maxx = *S.rbegin();
        S.erase(S.lower_bound(maxx));
        ile_usunietych += maxx + 1;
        for (int i = wsk_lewy + 1; i < n and i <= wsk_lewy + maxx + 1; ++i)
            S.insert(liczby[i]);
        wsk_lewy += maxx + 1;
    }

    cout << wyn << '\n';

    return 0;
}
