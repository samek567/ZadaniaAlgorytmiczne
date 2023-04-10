#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct Punkt
{
    int y;
    int x;
    bool operator < (const Punkt &punkt) const
    {
        return x < punkt.x;
    }
};

int wysokosc = 0, szerokosc = 0, n = 0, DOD = 30000, do_kod = 0, base = (1 << 16), rozmiar_drzewa = base * 2, wyn = 0;
vector<Punkt> punkty;
vector<int> tree;
vector<int> tree2;
deque<int> Q;

inline void update (int v, int l_update, int p_update, int l_kontrolowana, int p_kontrolowana, int val)
{
    if (l_kontrolowana > p_update or p_kontrolowana < l_update)
        return;
    else if (l_kontrolowana >= l_update and p_kontrolowana <= p_update)
    {
        tree[v] += val;
        tree2[v] += val;
    }
    else
    {
        tree[v*2] += tree2[v];
        tree[v*2+1] += tree2[v];
        tree2[v*2] += tree2[v];
        tree2[v*2+1] += tree2[v];
        tree2[v] = 0;
        int srod = (p_kontrolowana - l_kontrolowana + 1) / 2;
        update(v * 2, l_update, p_update, l_kontrolowana, l_kontrolowana + srod - 1, val);
        update(v * 2 + 1, l_update, p_update, l_kontrolowana + srod, p_kontrolowana, val);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

int main()
{
    // O(N lg N),
    // Zamiatanie z drzewem przedzialowym przedzial-przedzial dodaj na przedziale i odczytaj max-a na przedziale(w naszym przypadku w calej zmiotce)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> szerokosc >> wysokosc >> n;

    tree.assign(rozmiar_drzewa,0);
    tree2.assign(rozmiar_drzewa,0);
    punkty.assign(n,{-1,-1});

    for (int i = 0; i < n; ++i)
        cin >> punkty[i].x >> punkty[i].y;
    for (int i = 0; i < n; ++i)
        punkty[i].y += DOD;
    sort(punkty.begin(), punkty.end());

    do_kod = punkty[0].x + szerokosc;
    for (int i = 0; i < n; ++i)
    {
        if (punkty[i].x > do_kod)
        {
            do_kod = punkty[i].x;
            while(!Q.empty())
            {
                if (punkty[Q.back()].x < do_kod - szerokosc)
                {
                    update(1, punkty[Q.back()].y, punkty[Q.back()].y + wysokosc, 1, 2*DOD, -1);
                    Q.pop_back();
                }
                else
                    break;
            }
        }
        Q.push_front(i);
        update(1, punkty[i].y, punkty[i].y + wysokosc, 1, 2*DOD, 1);
        wyn = max(wyn, tree[1]);
    }

    cout << wyn << '\n';

    return 0;
}
