#include <iostream>
#include <set>

using namespace std;

struct Element
{
    string fragment;
    mutable int w_ilu_slowach;

    bool operator < (const Element &element) const
    {
        if (fragment.size() != element.fragment.size())
        {
            return fragment.size() > element.fragment.size();
        }
        return fragment < element.fragment;
    }
};

int n = 0;
string ciag, slowo;
set<string> podslowa;
set<Element> statystyki;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        podslowa.clear();
        cin >> ciag;

        for (int j = 0; j < ciag.size(); ++j)
        {
            slowo.clear();
            for (int k = j; k < ciag.size(); ++k)
            {
                slowo += ciag[k];
                podslowa.insert(slowo);
            }
        }

        for (auto f : podslowa)
        {
            auto it = statystyki.find({f,0});

            if (it != statystyki.end())
            {
                it->w_ilu_slowach+=1;
            }
            else
            {
                statystyki.insert({f,1});
            }
        }
    }


    for (auto i : statystyki)
    {
        if (i.w_ilu_slowach == n)
        {
            cout << i.fragment.size() << '\n';
            return 0;
        }
    }

    cout << "0" << '\n';

    return 0;
}
