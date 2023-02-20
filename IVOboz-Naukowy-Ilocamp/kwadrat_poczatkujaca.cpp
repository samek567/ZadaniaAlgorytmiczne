#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Punkt
{
    int y;
    int x;
    bool operator < (const Punkt &punkt) const
    {
        if (x == punkt.x)
            return y < punkt.y;
        return x < punkt.x;
    }
};

int x = 0, y = 0;
vector<Punkt> punkty;

int main()
{
    // O(1)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y;
    punkty.push_back({y,x});
    cin >> x >> y;
    punkty.push_back({y,x});
    cin >> x >> y;
    punkty.push_back({y,x});
    cin >> x >> y;
    punkty.push_back({y,x});

    sort(punkty.begin(), punkty.end());

    if (punkty[0].x == punkty[1].x && punkty[2].x == punkty[3].x && abs(punkty[0].y - punkty[1].y) == abs(punkty[2].y - punkty[3].y) && abs(punkty[1].x - punkty[3].x) == abs(punkty[0].x - punkty[2].x) && abs(punkty[0].y - punkty[1].y) == abs(punkty[0].x - punkty[2].x))
        cout << "TAK" << '\n';
    else
        cout << "NIE" << '\n';

    return 0;
}