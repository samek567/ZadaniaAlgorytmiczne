#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    int max1;
    int max2;
};

int n = 0, m = 0, a = 0, b = 0, max_wyn = 0, base = (1 << 18), rozmiar_drzewa = base * 2, max_val = 0;
bool czy_wszystkie_potegi_dwojki = true;
vector<int> liczby;
vector<bool> czy_potega_dwojki(1e6+1,false);
vector<Element> drzewo_przedzialowe;
vector<vector<int>> sumy_prefiksowe;
vector<vector<int>> gcd_stat;
vector<vector<int>> dp;

Element polacz (Element &el1, Element &el2)
{
    vector<int> el = {el1.max1, el1.max2, el2.max1, el2.max2};
    sort(el.begin(),el.end(),greater<int>());
    return {el[0], el[1]};
}

inline Element querry(int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    Element res = {-1,-1};
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res = polacz(res,drzewo_przedzialowe[l+1]);
        if (p % 2 == 1)
            res = polacz(res, drzewo_przedzialowe[p-1]);
        l /= 2;
        p /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n;

    liczby.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];
    for (int i = 1; i <= 1e6; i *= 2)
        czy_potega_dwojki[i] = true;

    for (int i = 0; i < n; ++i)
    {
        if (czy_potega_dwojki[liczby[i]] == false)
        {
            czy_wszystkie_potegi_dwojki = false;
            break;
        }
    }

    if (czy_wszystkie_potegi_dwojki == true)
    {
        drzewo_przedzialowe.assign(rozmiar_drzewa,{-1,-1});
        for (int i = 0; i < n; ++i)
        {
            if (czy_potega_dwojki[liczby[i]] == true)
                drzewo_przedzialowe[i+base] = {liczby[i],-1};
            else
                drzewo_przedzialowe[i+base] = {-1,-1};
        }
        for (int i = base-1; i >= 1; --i)
            drzewo_przedzialowe[i] = polacz(drzewo_przedzialowe[i*2],drzewo_przedzialowe[i*2+1]);
        cin >> m;
        while(m--)
        {
            cin >> a >> b;
            a--, b--;
            cout << querry(a,b).max2 << '\n';
        }
        return 0;
    }

    for (int i = 0; i < n; ++i)
        max_val = max(max_val, liczby[i]);

    if (max_val <= 50)
    {
        gcd_stat.assign(max_val+1,{});
        for (int i = 1; i <= max_val; ++i)
        {
            gcd_stat[i].assign(max_val+1,0);
            for (int j = 1; j <= max_val; ++j)
                gcd_stat[i][j] = __gcd(i,j);
        }

        sumy_prefiksowe.assign(max_val+1,{});
        for (int i = 1; i <= max_val; ++i)
        {
            int sum = 0;
            sumy_prefiksowe[i].assign(n,0);
            for (int j = 0; j < n; ++j)
            {
                if (liczby[j] == i)
                    sum++;
                sumy_prefiksowe[i][j] = sum;
            }
        }

        cin >> m;
        while(m--)
        {
            cin >> a >> b;
            a--,b--;
            max_wyn = 0;
            for (int i = 1; i <= max_val; ++i)
            {
                for (int j = i; j <= max_val; ++j)
                {
                    int ile_i = 0, ile_j = 0;
                    if (a == 0)
                        ile_i = sumy_prefiksowe[i][b];
                    else
                        ile_i = sumy_prefiksowe[i][b] - sumy_prefiksowe[i][a-1];
                    if (a == 0)
                        ile_j = sumy_prefiksowe[j][b];
                    else
                        ile_j = sumy_prefiksowe[j][b] - sumy_prefiksowe[j][a-1];
                    if (i == j)
                    {
                        if (ile_i > 1)
                            max_wyn = max(max_wyn, gcd_stat[i][j]);
                    }
                    else
                    {
                        if (ile_i > 0 and ile_j > 0)
                            max_wyn = max(max_wyn, gcd_stat[i][j]);
                    }
                }
            }
            cout << max_wyn << '\n';
        }
        return 0;
    }

    dp.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp[i].assign(n,0);

    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            dp[i][j] = max(dp[i][j-1],__gcd(liczby[i],liczby[j]));
    cin >> m;
    while(m--)
    {
        cin >> a >> b;
        a--,b--;
        max_wyn = 0;
        for (int i = a; i < b; ++i)
            max_wyn = max(max_wyn,dp[i][b]);
        cout << max_wyn << '\n';
    }

    return 0;
}