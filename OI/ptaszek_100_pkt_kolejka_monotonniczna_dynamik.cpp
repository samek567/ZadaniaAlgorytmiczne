#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Element
{
    long long dp;
    long long wysokosc;

    bool operator == (const Element &element) const
    {
        return ((dp == element.dp) && (wysokosc == element.wysokosc));
    }
    bool operator > (const Element & element) const
    {
        if (dp == element.dp)
        {
            return wysokosc < element.wysokosc;
        }
        return dp > element.dp;
    }
};

int n = 0, q = 0, k = 0;
long long d_i = 0;
Element spr;
vector<long long> wysokosci;
vector<Element> wyniki;
deque<Element> Q;

int main()
{
    // O(n * q) Kolejka monotonniczna dziala w czasie liniowym.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> d_i;
        wysokosci.push_back(d_i);
    }

    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        cin >> k;

        Q.clear();
        wyniki.clear();
        for (int j = 0; j < n; ++j)
        {
            spr = {-1,-1};
            if(Q.empty())
            {
                spr = {0,wysokosci[j]};
            }
            else
            {
                spr = {Q.front().dp,wysokosci[j]};
                if (Q.front().wysokosc <= wysokosci[j])
                {
                    spr.dp++;
                }
            }

            while (!Q.empty())
            {
                if (Q.back() > spr)
                {
                    Q.pop_back();
                }
                else
                {
                    break;
                }
            }
            Q.push_back(spr);
            wyniki.push_back(spr);

            if (j >= k)
            {
                if (wyniki[j-k] == Q.front())
                {
                    Q.pop_front();
                }
            }
        }

        cout << wyniki[n-1].dp << '\n';
    }

    return 0;
}
