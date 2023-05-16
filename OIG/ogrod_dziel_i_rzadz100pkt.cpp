#include <iostream>
#include <vector>

using namespace std;

struct Punkt
{
    int y;
    int x;
};

struct Zdarzenie
{
    Punkt poczatek;
    Punkt koniec;
    int idx;
};

int n = 0, m = 0, q = 0, x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;
vector<Zdarzenie> pocz_vect;
vector<vector<int>> plansza;
vector<vector<int>> dp;
vector<int> wyn_idx;
vector<Punkt> vect_1;
vector<Punkt> vect_2;
vector<Punkt> vect_3;

inline void podziel_zdarzenia(int &srodek, vector<Zdarzenie> &lewe, vector<Zdarzenie> &prawe, vector<Zdarzenie> &sprawdzane, vector<Zdarzenie> &zdarzenia)
{
    for (int i = 0; i < zdarzenia.size(); ++i)
    {
        if (zdarzenia[i].koniec.x < srodek)
            lewe.push_back(zdarzenia[i]);
        else if (zdarzenia[i].poczatek.x > srodek)
            prawe.push_back(zdarzenia[i]);
        else
            sprawdzane.push_back(zdarzenia[i]);
    }
}

inline void dziel_i_zwyciezaj(int l, int p, vector<Zdarzenie> zdarzenia)
{
    vector<Zdarzenie> lewe, prawe, sprawdzane;
    int srodek = (l + p) / 2;
    podziel_zdarzenia(srodek,lewe,prawe,sprawdzane,zdarzenia);

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j >= 0; --j)
        {
            for (int k = srodek; k >= l; --k)
            {
                dp[j][k] = plansza[j][k];
                if (j == i and k == srodek)
                    continue;
                else if (j == i)
                    dp[j][k] += dp[j][k+1];
                else if (k == srodek)
                    dp[j][k] += dp[j+1][k];
                else
                    dp[j][k] += max(dp[j][k+1],dp[j+1][k]);
            }
        }
        for (int j = i; j < n; ++j)
        {
            for (int k = srodek; k <= p; ++k)
            {
                dp[j][k] = plansza[j][k];
                if (j == i and k == srodek)
                    continue;
                else if (j == i)
                    dp[j][k] += dp[j][k-1];
                else if (k == srodek)
                    dp[j][k] += dp[j-1][k];
                else
                    dp[j][k] += max(dp[j][k-1],dp[j-1][k]);
            }
        }

        for (int j = 0; j < sprawdzane.size(); ++j)
        {
            if (sprawdzane[j].poczatek.x == srodek and sprawdzane[j].koniec.x == srodek and sprawdzane[j].poczatek.y != i)
                continue;
            if (sprawdzane[j].poczatek.y > i or sprawdzane[j].koniec.y < i)
                continue;
            int val = dp[sprawdzane[j].poczatek.y][sprawdzane[j].poczatek.x] + dp[sprawdzane[j].koniec.y][sprawdzane[j].koniec.x] - plansza[i][srodek];
            wyn_idx[sprawdzane[j].idx] = max(wyn_idx[sprawdzane[j].idx], val);
        }
    }

    if (l == p)
        return;
    if (lewe.size() != 0)
        dziel_i_zwyciezaj(l,srodek-1,lewe);
    if (prawe.size() != 0)
        dziel_i_zwyciezaj(srodek+1,p,prawe);
}

inline void napelniaj()
{
    dp.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp[i].assign(m,-1);
    dziel_i_zwyciezaj(0,m-1,pocz_vect);
}

inline bool czy_w_prostokacie(Punkt p1, Punkt p2, Punkt spr)
{
    if (spr.x >= p1.x and spr.x <= p2.x and spr.y >= p1.y and spr.y <= p2.y)
        return true;
    return false;
}

int main()
{
    // O(lg M * (N^2 * M + Q)), dziel i rzadz!
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    plansza.assign(n,{});
    for (int i = 0; i < n; ++i)
        plansza[i].assign(m,-1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> plansza[i][j];

    cin >> q;
    vect_1.assign(q,{});
    vect_2.assign(q,{});
    vect_3.assign(q,{});
    for (int i = 0; i < q; ++i)
    {
        cin >> y1 >> x1 >> y2 >> x2 >> y3 >> x3;
        x1--,x2--,x3--,y1--,y2--,y3--;
        vect_1[i] = {y1,x1}, vect_2[i] = {y2,x2}, vect_3[i] = {y3,x3};
        if (czy_w_prostokacie(vect_1[i],vect_2[i],vect_3[i]) == true)
        {
            pocz_vect.push_back({{y1,x1},{y2,x2},wyn_idx.size()});
            wyn_idx.push_back(-1);
            pocz_vect.push_back({{y1,x1},{y3,x3},wyn_idx.size()});
            wyn_idx.push_back(-1);
            pocz_vect.push_back({{y3,x3},{y2,x2},wyn_idx.size()});
            wyn_idx.push_back(-1);
        }
        else
        {
            wyn_idx.push_back(-1);
            wyn_idx.push_back(-1);
            wyn_idx.push_back(-1);
        }
    }

    napelniaj();

    int ile = 0;

    for (int i = 0; i < q; ++i)
    {
        if (czy_w_prostokacie(vect_1[i],vect_2[i],vect_3[i]) == false)
        {
            cout << "NIE" << '\n';
            continue;
        }
        int val = wyn_idx[pocz_vect[ile*3+1].idx] + wyn_idx[pocz_vect[ile*3+2].idx] - plansza[pocz_vect[ile*3+1].koniec.y][pocz_vect[ile*3+1].koniec.x];
        if (val >= wyn_idx[pocz_vect[ile*3].idx])
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
        ile++;
    }

    return 0;
}
