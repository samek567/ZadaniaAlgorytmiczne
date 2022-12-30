#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Element
{
    long long cena;
    mutable long long ile_wystapien;
    bool operator < (const Element &element) const
    {
        return cena < element.cena;
    }
};

int n = 0;
long long a_i = 0, b_i = 0, wyn = 0;
set<Element> S;

int main()
{
    // O(n log n)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a_i >> b_i;

        auto it = S.find({a_i,-1});
        if (it != S.end())
            it->ile_wystapien += b_i;
        else
            S.insert({a_i,b_i});

        wyn += S.begin()->cena;
        if (S.begin()->ile_wystapien == 1)
            S.erase(*S.begin());
        else
            S.begin()->ile_wystapien--;
    }

    printf("%lld",wyn);

    return 0;
}
