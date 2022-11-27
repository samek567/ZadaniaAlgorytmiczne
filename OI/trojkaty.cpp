#include <iostream>
#include <algorithm>
#include <set>

struct Q
{
    long long p;
    long long q;

    Q operator + (const Q &other) const
    {
        return {p * other.q + other.p * q,q*other.q};
    }
    bool operator < (const Q &other) const
    {
        return p * other.q < other.p * q;
    }
    bool operator > (const Q &other) const
    {
        return p * other.q > other.p * q;
    }
};

using namespace std;

int n = 0;
string wczytany_ciag, podciag;
multiset<Q> S;
Q spr;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        podciag.clear();
        cin >> wczytany_ciag;

        for (int j = 0; j < wczytany_ciag.size(); ++j)
        {
            if (wczytany_ciag[j] == '/')
            {
                spr = {stoll(podciag), 1};
                podciag.clear();
            } else
            {
                podciag += wczytany_ciag[j];
            }
        }
        spr.q = stoll(podciag);
        S.insert(spr);
        if (S.size() > 3)
        {
            auto it = S.end();
            --it;
            --it;
            S.erase(S.lower_bound(*it));
        }
    }

    auto it_najmniejszy = S.begin();
    auto it_sredni = S.begin();
    auto it_najwiekszy = S.begin();

    ++it_sredni;
    ++it_najwiekszy;
    ++it_najwiekszy;

    if (*it_najmniejszy + *it_sredni > *it_najwiekszy)
    {
        printf("TAK");
    }
    else
    {
        printf("NIE");
    }

    return 0;
}
