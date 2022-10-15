#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

struct Stacja
{
    long long y;
    long long x;
    int idx;

    bool operator < (const Stacja& stacja) const
    {
        if (y == stacja.y)
        {
            return x < stacja.x;
        }
        else
        {
            return y < stacja.y;
        }
    }
};

struct Element
{
    pair<long long, long long> pierwszy; // y,x
    pair<long long, long long> drugi; // y,x
};

long double licz_nachylenie(pair<long long, long long> el_1,pair<long long, long long> el_2)
{
    long double nachylenie = abs((long double)el_1.first - (long double)el_2.first) / abs((long double)el_1.second - (long double)el_2.second);
    return nachylenie;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    long double min_nachylenie = pow(10,20);
    int a = 1;
    int b = 1;

    cin >> n;

    Stacja stacje[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> stacje[i].x >> stacje[i].y;
        stacje[i].idx = i;
    }

    sort(stacje,stacje+n);

    vector<Element> elementy;
    vector<pair<int,int>> idxy_elementow; // first - pierwszy, second - ostatni
    int wskaznik_y = -1;

    for (int i = 0; i < n; ++i)
    {
        if (stacje[i].y == wskaznik_y)
        {
            elementy[elementy.size()-1].drugi.first = wskaznik_y;
            elementy[elementy.size()-1].drugi.second = stacje[i].x;
            idxy_elementow[elementy.size()-1].second = stacje[i].idx;
        }
        else
        {
            elementy.push_back({{stacje[i].y,stacje[i].x},{stacje[i].y,stacje[i].x}});
            idxy_elementow.push_back({stacje[i].idx,stacje[i].idx});
            wskaznik_y = stacje[i].y;
        }
    }

    for (int i = 0; i < elementy.size()-1; ++i)
    {
        long double nachylenie = licz_nachylenie(elementy[i].pierwszy,elementy[i+1].pierwszy);
        if (nachylenie < min_nachylenie && nachylenie != 0)
        {
            min_nachylenie = nachylenie;
            a = idxy_elementow[i].first;
            b = idxy_elementow[i+1].first;
        }

        nachylenie = licz_nachylenie(elementy[i].pierwszy,elementy[i+1].drugi);
        if (nachylenie < min_nachylenie && nachylenie != 0)
        {
            min_nachylenie = nachylenie;
            a = idxy_elementow[i].first;
            b = idxy_elementow[i+1].second;
        }

        nachylenie = licz_nachylenie(elementy[i].drugi,elementy[i+1].pierwszy);
        if (nachylenie < min_nachylenie && nachylenie != 0)
        {
            min_nachylenie = nachylenie;
            a = idxy_elementow[i].second;
            b = idxy_elementow[i+1].first;
        }

        nachylenie = licz_nachylenie(elementy[i].drugi,elementy[i+1].drugi);
        if (nachylenie < min_nachylenie && nachylenie != 0)
        {
            min_nachylenie = nachylenie;
            a = idxy_elementow[i].second;
            b = idxy_elementow[i+1].second;
        }
    }

    cout << a+1 << " " << b+1;
    return 0;
}