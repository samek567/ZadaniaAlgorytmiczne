#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct Punkt
{
    int x;
    int y;
    int z;
};

int n = 0;
ll wyn = 0;
vector<Punkt> punkty;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    punkty.assign(n,{-1,-1,-1});
    for (int i = 0; i < n; ++i)
        cin >> punkty[i].x >> punkty[i].y >> punkty[i].z;

    for (int i = 0; i < n; ++i)
    {
        wyn = 0;
        for (int j = 0; j < n; ++j)
            wyn = max(wyn, abs((ll)punkty[i].x - (ll)punkty[j].x) + abs((ll)punkty[i].y - (ll)punkty[j].y) + abs((ll)punkty[i].z - (ll)punkty[j].z));
        cout << wyn << '\n';
    }

    return 0;
}