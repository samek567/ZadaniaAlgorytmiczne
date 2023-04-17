#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct Punkt
{
    int y;
    int x;
};

int n = 0, m = 0;
ll iloczyn_vectorowy = 0;
bool czy_dodatni = true, czy_zle = false;
Punkt start;
vector<Punkt> punkty;

inline ll iloczyn_vect(int p1, int p2)
{
    return (ll)punkty[p1].x * (ll)punkty[p2].y - (ll)punkty[p2].x * (ll)punkty[p1].y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    while(m--)
    {
        cin >> n >> start.x >> start.y;
        punkty.assign(n,{});
        for (int i = 0; i < n; ++i)
            cin >> punkty[i].x >> punkty[i].y;
        for (int i = 0; i < n; ++i)
        {
            punkty[i].y -= start.y;
            punkty[i].x -= start.x;
        }
        czy_zle = false;
        iloczyn_vectorowy = iloczyn_vect(0,1);
        if (iloczyn_vectorowy == 0)
            czy_zle = true;
        if (iloczyn_vectorowy > 0)
            czy_dodatni = true;
        else
            czy_dodatni = false;
        for (int i = 1; i < n; ++i)
        {
            if (i == n-1)
                iloczyn_vectorowy = iloczyn_vect(i,0);
            else
                iloczyn_vectorowy = iloczyn_vect(i,i+1);
            if (iloczyn_vectorowy >= 0 and czy_dodatni == false)
                czy_zle = true;
            else if (iloczyn_vectorowy <= 0 and czy_dodatni == true)
                czy_zle = true;
            if (czy_zle == true)
                break;
        }
        if (czy_zle == true)
            cout << "NIE" << '\n';
        else
            cout << "TAK" << '\n';
    }

    return 0;
}
