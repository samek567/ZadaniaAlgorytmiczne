#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Auto
{
    int ktory_pas;
    int czas;
};

int n = 0, m = 0, p = 0, t = 0, ile_x = 0, ile_y = 0, wyn = 0, DOD = 3e6;
vector<Auto> poziomkowa;
vector<Auto> truskawkowa;
vector<bool> stat(6e6,false);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> p >> t;

    poziomkowa.assign(p,{0,0});
    for (int i = 0; i < p; ++i)
        cin >> poziomkowa[i].ktory_pas >> poziomkowa[i].czas;

    truskawkowa.assign(t,{0,0});
    for (int i = 0; i < t; ++i)
        cin >> truskawkowa[i].ktory_pas >> truskawkowa[i].czas;

    for (int i = 0; i < p; ++i)
        ile_x = max(ile_x, poziomkowa[i].czas);

    for (int i = 0; i < t; ++i)
        ile_y = max(ile_y, truskawkowa[i].czas);

    for (int i = 0; i < p; ++i)
        stat[(poziomkowa[i].ktory_pas + ile_y) - (m + poziomkowa[i].czas) + DOD] = true;

    for (int i = 0; i < t; ++i)
        if (auto it = stat[(ile_y - truskawkowa[i].czas + 1) - (m - truskawkowa[i].ktory_pas + 1) + DOD] == false)
            wyn++;

    cout << wyn << '\n';

    return 0;
}