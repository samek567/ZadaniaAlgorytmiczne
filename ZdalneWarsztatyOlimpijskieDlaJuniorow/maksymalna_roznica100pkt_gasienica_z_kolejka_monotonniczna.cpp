#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
typedef long long ll;

int n = 0, k = 0, wczytana_liczba = 0, lewy_wsk = 0, prawy_wsk = 0;
ll wyn = 0;
vector<int> liczby;
deque<int> Q_max;
deque<int> Q_min;

inline void przesuwaj_lewy()
{
    wyn = max(wyn,(ll)prawy_wsk - (ll)lewy_wsk + 1);
    if (!Q_max.empty())
        if (Q_max.front() == liczby[lewy_wsk])
            Q_max.pop_front();
    if (!Q_min.empty())
        if (Q_min.front() == liczby[lewy_wsk])
            Q_min.pop_front();
    lewy_wsk++;
    if (lewy_wsk > prawy_wsk)
    {
        prawy_wsk = lewy_wsk;
        Q_max.push_front(liczby[lewy_wsk]);
        Q_min.push_front(liczby[lewy_wsk]);
    }
}

int main()
{
    // O(n log n) Gasienica z kolejka monotonniczna
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
    Q_min.push_front(liczby[0]);
    Q_max.push_front(liczby[0]);
    while(true)
    {
        if (lewy_wsk == prawy_wsk && lewy_wsk == n-1)
            break;
        if (prawy_wsk == n-1)
            przesuwaj_lewy();
        else if (max(Q_max.front(),liczby[prawy_wsk+1]) - min(Q_min.front(),liczby[prawy_wsk+1]) <= k)
        {
            prawy_wsk++;
            while(!Q_max.empty())
            {
                if (Q_max.back() < liczby[prawy_wsk])
                    Q_max.pop_back();
                else
                    break;
            }
            Q_max.push_back(liczby[prawy_wsk]);
            while(!Q_min.empty())
            {
                if (Q_min.back() > liczby[prawy_wsk])
                    Q_min.pop_back();
                else
                    break;
            }
            Q_min.push_back(liczby[prawy_wsk]);
        }
        else
            przesuwaj_lewy();
    }
    printf("%lld",wyn);

    return 0;
}
