#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Punkt
{
    ll wspolrzedna;
    ll ile_dodaje;
    bool operator < (const Punkt &punkt) const
    {
        if (wspolrzedna == punkt.wspolrzedna)
            return ile_dodaje > punkt.ile_dodaje;
        return wspolrzedna < punkt.wspolrzedna;
    }
};

int n = 0, wyn = 0, max_wyn = 0;
ll a_i = 0, b_i = 0;
vector<Punkt> punkty;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a_i >> b_i;
        punkty.push_back({a_i,1});
        punkty.push_back({b_i,-1});
    }
    sort(punkty.begin(),punkty.end());
    for (int i = 0; i < n+n; ++i)
    {
        wyn += punkty[i].ile_dodaje;
        max_wyn = max(max_wyn,wyn);
    }
    printf("%d",max_wyn);
    return 0;
}