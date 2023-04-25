#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Element
{
    int wysokosc;
    int cena;
    bool operator < (const Element &element) const
    {
        return wysokosc < element.wysokosc; // bo kolejka priorytetowa jest od najwiekszych, wiec trzeba dac na odwrot.
    }
};

int n = 0, m = 0, cena = 0, wysokosc = 0, wyn = 0, wsk = 0;
priority_queue<int> Q;
vector<Element> elementy;

int main()
{
    // Zachlan
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    elementy.assign(n,{});
    for (int i = 0; i < n; ++i)
        cin >> elementy[i].cena >> elementy[i].wysokosc;
    sort(elementy.begin(), elementy.end());

    for (int i = 1; i <= m; ++i)
    {
        while (wsk < n and elementy[wsk].wysokosc <= i)
        {
            Q.push(elementy[wsk].cena);
            wsk++;
        }
        if (!Q.empty())
        {
            wyn += Q.top();
            Q.pop();
        }
    }

    cout << wyn << '\n';

    return 0;
}