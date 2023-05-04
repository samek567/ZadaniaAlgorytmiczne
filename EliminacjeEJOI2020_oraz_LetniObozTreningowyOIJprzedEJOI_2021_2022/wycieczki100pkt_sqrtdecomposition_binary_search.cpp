#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    int val;
    int idx;
    bool operator < (const Element &element) const
    {
        if (val == element.val)
            return idx < element.idx;
        return val < element.val;
    }
};

int n = 0, q = 0, wczytana_liczba = 0, k = 447, ile_przedzialow = 0, l = 0, p = 0, x = 0;
string decyzja;
vector<int> liczby;
vector<int> przedzialy_max;
vector<vector<Element>> przedzialy_liczby;

inline int query_najszybciej(int a, int b)
{
    a--, b--;
    int w_jakim_przedziale_a = a / k, w_jakim_przedziale_b = b / k;
    for (int i = a; i <= min(b,w_jakim_przedziale_a*k+k-1); ++i)
        if (liczby[i] > x)
            return i;
    for (int i = w_jakim_przedziale_a + 1; i < w_jakim_przedziale_b; ++i)
        if (przedzialy_max[i] > x)
            for (int j = i * k; j < i * k + k; ++j)
                if (liczby[j] > x)
                    return j;
    if (w_jakim_przedziale_a != w_jakim_przedziale_b)
        for (int i = w_jakim_przedziale_b*k; i <= b; ++i)
            if (liczby[i] > x)
                return i;

    return -1;
}

inline int querry_najtaniej(int a, int b)
{
    a--, b--;
    int w_jakim_przedziale_a = a / k, w_jakim_przedziale_b = b / k, min_wyn = 1e9+105, min_idx = -1;

    for (int i = a; i <= min(b, w_jakim_przedziale_a*k+k-1); ++i)
    {
        if (liczby[i] > x and liczby[i] < min_wyn)
        {
            min_wyn = liczby[i];
            min_idx = i;
        }
    }

    for (int i = w_jakim_przedziale_a + 1; i < w_jakim_przedziale_b; ++i)
    {
        int poczatek = -1, koniec = przedzialy_liczby[i].size(), srodek = 0;
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (przedzialy_liczby[i][srodek].val > x)
                koniec = srodek;
            else
                poczatek = srodek;
        }
        if (koniec != przedzialy_liczby[i].size())
        {
            if (przedzialy_liczby[i][koniec].val < min_wyn)
            {
                min_wyn = przedzialy_liczby[i][koniec].val;
                min_idx = przedzialy_liczby[i][koniec].idx;
            }
        }
    }

    if (w_jakim_przedziale_a != w_jakim_przedziale_b)
    {
        for (int i = w_jakim_przedziale_b*k; i <= b; ++i)
        {
            if (liczby[i] > x and liczby[i] < min_wyn)
            {
                min_wyn = liczby[i];
                min_idx = i;
            }
        }
    }

    return min_idx;
}

int main()
{
    // O((N+Q) * sqrt(N) * lg(sqrt(N))), sqrt decomposition + binary search.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    ile_przedzialow = n / k;
    if (n % k != 0)
        ile_przedzialow++;
    przedzialy_max.assign(ile_przedzialow,0);
    przedzialy_liczby.assign(ile_przedzialow,{});

    liczby.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];

    for (int i = 0; i < n; ++i)
        przedzialy_max[i / k] = max(przedzialy_max[i / k], liczby[i]);

    for (int i = 0; i < n; ++i)
        przedzialy_liczby[i / k].push_back({liczby[i],i});

    for (int i = 0; i < ile_przedzialow; ++i)
        sort(przedzialy_liczby[i].begin(), przedzialy_liczby[i].end());

    while(q--)
    {
        cin >> decyzja;
        if (decyzja == "najszybciej")
        {
            cin >> l >> p >> x;
            if (query_najszybciej(l,p) == -1)
                cout << "NIE" << '\n';
            else
                cout << query_najszybciej(l,p) + 1 << '\n';
        }
        else if (decyzja == "najtaniej")
        {
            cin >> l >> p >> x;
            if (querry_najtaniej(l,p) == -1)
                cout << "NIE" << '\n';
            else
                cout << querry_najtaniej(l,p) + 1 << '\n';
        }
        else
        {
            cin >> l >> x;
            l--;

            liczby[l] = x;
            int maxx = 0, w_jakim_przedziale = l / k;

            przedzialy_liczby[w_jakim_przedziale].clear();
            for (int i = w_jakim_przedziale*k; i < w_jakim_przedziale*k+k; ++i)
                przedzialy_liczby[w_jakim_przedziale].push_back({liczby[i],i});
            sort(przedzialy_liczby[w_jakim_przedziale].begin(), przedzialy_liczby[w_jakim_przedziale].end());

            for (int i = w_jakim_przedziale * k; i < w_jakim_przedziale * k + k; ++i)
                maxx = max(maxx, liczby[i]);
            przedzialy_max[w_jakim_przedziale] = maxx;
        }
    }

    return 0;
}