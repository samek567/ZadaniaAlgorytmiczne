#include <iostream>
#include <vector>
#include <set>

using namespace std;

int w = 0, n = 0, wczytana_liczba = 0, wyn = 0;
vector<int> stat(205,0);
multiset<int> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        stat[wczytana_liczba]++;
    }

    for (int i = 5; i <= w; ++i)
        for (int j = 0; j < stat[i]; ++j)
            S.insert(i);

    while(!S.empty())
    {
        // lower bound pierwszy, ktory jest >= niz wartosc.
        auto it = S.lower_bound(w - *S.rbegin());
        if (*S.rbegin() == *it) // Te same
        {
            if (S.count(*it) == 1)
            {
                if (*it == *S.begin())
                    S.erase(S.lower_bound(*S.rbegin()));
                else
                {
                    --it;
                    S.erase(S.lower_bound(*S.rbegin()));
                    S.erase(S.lower_bound(*it));
                }
            }
            else
            {
                S.erase(S.lower_bound(*S.rbegin()));
                S.erase(S.lower_bound(*it));
            }
        }
        else if (*it == w - *S.rbegin()) // Dopelniaja sie do jednego kajaka.
        {
            S.erase(S.lower_bound(*S.rbegin()));
            S.erase(S.lower_bound(*it));
        }
        else
        {
            if (*it == *S.begin())
                S.erase(S.lower_bound(*S.rbegin()));
            else
            {
                --it;
                S.erase(S.lower_bound(*S.rbegin()));
                S.erase(S.lower_bound(*it));
            }
        }
        wyn++;
    }
    cout << wyn;

    return 0;
}