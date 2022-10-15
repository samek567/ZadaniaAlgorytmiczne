#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct Punkt
{
    int x;
    int y;

    bool operator < (const Punkt&punkt) const
    {
        if (y == punkt.y)
        {
            return x < punkt.x;
        }
        else
        {
            return y < punkt.y;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Punkt punkty[4];
    set<Punkt> rozne_pkt;

    for (int i = 0; i < 4; ++i)
    {
        cin >> punkty[i].x >> punkty[i].y;
        rozne_pkt.insert(punkty[i]);
    }
    sort(punkty,punkty+4);

    if (rozne_pkt.size() == 4 && punkty[0].y == punkty[1].y && punkty[2].y == punkty[3].y && punkty[1].x - punkty[0].x == punkty[3].x - punkty[2].x && punkty[0].x == punkty[2].x && punkty[1].x - punkty[0].x == punkty[2].y - punkty[0].y)
    {
        cout << "TAK";
    }
    else
    {
        cout << "NIE";
    }
    return 0;
}