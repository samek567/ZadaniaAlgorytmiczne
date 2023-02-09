#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef long double ld;

struct Element
{
    ld cena;
    int ile;
    bool operator < (const Element &element) const
    {
        return cena > element.cena;
    }
};

int n = 0, w = 0, v_i = 0, c_i = 0, ile_mamy = 0;
ld wyn = 0;
vector<Element> elementy;

int main()
{
    // O(N lg N) Sortujemy co najbardziej oplaca nam sie wziac
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    for (int i = 0; i < n; ++i)
    {
        cin >> v_i >> c_i;
        elementy.push_back({(ld)v_i / (ld)c_i,c_i});
    }

    sort(elementy.begin(),elementy.end());

    for (int i = 0; i < n; ++i)
    {
        if (ile_mamy + elementy[i].ile <= w)
        {
            wyn += elementy[i].cena * (ld)elementy[i].ile;
            ile_mamy += elementy[i].ile;
        }
        else
        {
            wyn += (ld)(w - ile_mamy) * elementy[i].cena;
            break;
        }
    }

    cout << fixed << setprecision(4) << wyn << '\n';
    return 0;
}