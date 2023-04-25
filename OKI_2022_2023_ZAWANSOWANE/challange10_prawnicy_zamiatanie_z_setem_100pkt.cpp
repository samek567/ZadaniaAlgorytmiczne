#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Przedzial
{
    int poczatek;
    int koniec;
    int idx;
    bool operator < (const Przedzial &przedzial) const
    {
        return poczatek < przedzial.poczatek;
    }
};

struct Element
{
    int wartosc;
    int idx;
    bool operator < (const Element &element) const
    {
        if (wartosc == element.wartosc)
            return idx < element.idx;
        return wartosc < element.wartosc;
    }
};

int n = 0, k = 0, wyn = 0;
vector<Przedzial> przedzialy;
multiset<int> S;
set<Element> S_odtw;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    przedzialy.assign(n,{});
    for (int i = 0; i < n; ++i)
    {
        cin >> przedzialy[i].poczatek >> przedzialy[i].koniec;
        przedzialy[i].idx = i+1;
    }

    sort(przedzialy.begin(), przedzialy.end());

    for (int i = 0; i < n; ++i)
    {
        while(!S.empty())
        {
            if (*S.begin() < przedzialy[i].poczatek)
                S.erase(S.lower_bound(*S.begin()));
            else
                break;
        }
        S.insert(przedzialy[i].koniec);
        if (S.size() > k)
            S.erase(S.lower_bound(*S.begin()));
        if (S.size() == k)
            wyn = max(wyn, *S.begin() - przedzialy[i].poczatek);
    }

    for (int i = 0; i < n; ++i)
    {
        while(!S_odtw.empty())
        {
            if (S_odtw.begin()->wartosc < przedzialy[i].poczatek)
                S_odtw.erase(*S_odtw.begin());
            else
                break;
        }
        S_odtw.insert({przedzialy[i].koniec,przedzialy[i].idx});
        if (S_odtw.size() > k)
            S_odtw.erase(*S_odtw.begin());
        if (S_odtw.size() == k)
        {
            if (S_odtw.begin()->wartosc - przedzialy[i].poczatek == wyn)
            {
                cout << wyn << '\n';
                while(!S_odtw.empty())
                {
                    cout << S_odtw.begin()->idx << ' ';
                    S_odtw.erase(*S_odtw.begin());
                }
                return 0;
            }
        }
    }

    return 0;
}