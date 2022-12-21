#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    int y;
    int x;

    bool operator < (const Element &element) const
    {
        return x < element.x;
    }
};

int n = 0, wczytane_x = 0, wczytane_y = 0, min_wyn = 0, min_droga = 0;
vector<Element> elementy;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytane_x >> wczytane_y;
        elementy.push_back({wczytane_y,wczytane_x});
    }
    sort(elementy.begin(),elementy.end());

    min_droga = elementy[0].y + (elementy[1].x - elementy[0].x);
    min_wyn = min_droga + elementy[1].y;
    for (int i = 2; i < n; ++i)
    {
        min_droga = min(min_droga + (elementy[i].x - elementy[i-1].x),elementy[i-1].y + (elementy[i].x - elementy[i-1].x));
        min_wyn = min(min_wyn,min_droga + elementy[i].y);
    }

    printf("%d",min_wyn);

    return 0;
}
