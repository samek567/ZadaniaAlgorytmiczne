#include <iostream>
#include <set>

using namespace std;

struct Element
{
    string wartosc;
    mutable int ile_wystapien;

    bool operator < (const Element &element) const
    {
        if (wartosc.size() == element.wartosc.size())
            return wartosc < element.wartosc;
        return wartosc.size() < element.wartosc.size();
    }
};

int n = 0, wyn = 0;
string wczytan_ciag;
set<Element> elementy;

int main()
{
    // Zachlan.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytan_ciag;
        auto it = elementy.find({wczytan_ciag,0});
        if (it != elementy.end())
        {
            it->ile_wystapien++;
        }
        else
        {
            elementy.insert({wczytan_ciag,1});
        }
    }

    while(!elementy.empty())
    {
        auto it = elementy.begin();
        wyn = max(wyn,(int)it->wartosc.size());
        if (it->ile_wystapien >= 2)
        {
            auto it_2 = elementy.find({it->wartosc+it->wartosc,it->ile_wystapien});
            if (it_2 != elementy.end())
            {
                it_2->ile_wystapien += it->ile_wystapien / 2;
            }
            else
            {
                elementy.insert({it->wartosc+it->wartosc,it->ile_wystapien/2});
            }
        }
        elementy.erase(*it);
    }

    printf("%d",wyn);
    return 0;
}