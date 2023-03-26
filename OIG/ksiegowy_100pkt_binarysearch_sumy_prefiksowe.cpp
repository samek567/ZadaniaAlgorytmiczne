#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct Element
{
    ll val;
    int idx;
};

int n = 0, idx_lewo = 1e9, idx_prawo = -1e9, min_lewo = -1, min_prawo = -1;
ll min_val = 1e18, sum = 0;
vector<int> liczby;
vector<ll> sumy_prefiksowe;
vector<ll> sumy_sufixowe;
vector<Element> elementy;

int main()
{
    // O(N lg N), wyszukiwanie binarne, chyba mozna usunac binary searcha i trzymac max_val i potem raz liniowo odtworzyc.
    // Dzieki!!! https://forum.pasja-informatyki.pl/582738/zadanie-ksiegowy-oig
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n;

    liczby.assign(n,-1);
    sumy_prefiksowe.assign(n,-1);
    sumy_sufixowe.assign(n,-1);

    for (int i = 0; i < n; ++i)
        cin >> liczby[i];

    sumy_prefiksowe[0] = liczby[0];
    for (int i = 1; i < n; ++i)
        sumy_prefiksowe[i] = sumy_prefiksowe[i-1] + liczby[i];

    sumy_sufixowe[n-1] = liczby[n-1];
    for (int i = n-2; i >= 0; --i)
        sumy_sufixowe[i] = sumy_sufixowe[i+1] + liczby[i];

    for (int i = 0; i < n; ++i)
    {
        if (sumy_prefiksowe[i] < 0)
        {
            idx_lewo = min(idx_lewo, i);
            idx_prawo = max(idx_prawo,i);
        }
    }

    if (idx_lewo == 1e9)
    {
        cout << "1 1" << '\n';
        return 0;
    }

    for (int i = idx_prawo+1; i < n; ++i)
    {
        sum += liczby[i];
        if (elementy.empty())
            elementy.push_back({sum,i});
        else if (sum > elementy[elementy.size()-1].val)
            elementy.push_back({sum,i});
    }

    for (int i = idx_lewo+1; i <= idx_prawo; ++i)
        min_val = min(min_val,sumy_sufixowe[i]);

    for (int i = idx_lewo; i >= 0; --i)
    {
        min_val = min(min_val, sumy_sufixowe[i]);
        ll szukana = 0;
        if (idx_prawo == n-1)
            szukana = min_val;
        else
            szukana = min_val - sumy_sufixowe[idx_prawo+1];
        if (i != 0)
            szukana += sumy_prefiksowe[i-1];
        if (szukana >= 0)
        {
            min_lewo = i, min_prawo = idx_prawo;
            continue;
        }
        szukana *= -1;
        int poczatek = -1, koniec = elementy.size(), srodek = 0;
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (elementy[srodek].val >= szukana)
                koniec = srodek;
            else
                poczatek = srodek;
        }
        if (koniec != elementy.size())
        {
            min_lewo = i, min_prawo = elementy[koniec].idx;
        }
    }

    if (min_lewo == -1)
        cout << "NIE" << '\n';
    else
        cout << min_lewo+1 << ' ' << min_prawo+1 << '\n';

    return 0;
}
