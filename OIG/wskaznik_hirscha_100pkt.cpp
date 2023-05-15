#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

struct Element
{
    int ile_cytowan;
    int cena;
    bool operator < (const Element &element) const
    {
        return ile_cytowan < element.ile_cytowan;
    }
};

int n = 0, q = 0, wsk = 0;
ll suma = 0;
vector<Element> elementy;
vector<ll> koszty;
priority_queue<int> Q;

inline void napelniaj()
{
    koszty.assign(n+1,1e18+20);
    wsk = n-1;
    for (int i = n; i >= 0; --i)
    {
        while(wsk >= 0)
        {
            if (elementy[wsk].ile_cytowan >= i)
            {
                suma += elementy[wsk].cena;
                Q.push(elementy[wsk].cena);
                wsk--;
            }
            else
                break;
        }
        while(Q.size() > i)
        {
            ll val = Q.top();
            suma -= val;
            Q.pop();
        }
        if (Q.size() == i)
            koszty[i] = suma;
    }
}

inline ll zapytanie()
{
    ll wartosc;
    cin >> wartosc;

    int poczatek = 0, koniec = n+1, srodek = 0;
    while(koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (wartosc >= koszty[srodek])
            poczatek = srodek;
        else
            koniec = srodek;
    }
    return poczatek;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    elementy.assign(n,{});
    for (int i = 0; i < n; ++i)
        cin >> elementy[i].ile_cytowan >> elementy[i].cena;
    sort(elementy.begin(), elementy.end());

    napelniaj();

    while(q--)
        cout << zapytanie() << '\n';

    return 0;
}
