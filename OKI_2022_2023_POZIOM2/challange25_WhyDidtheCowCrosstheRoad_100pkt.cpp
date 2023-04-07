#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;

struct Pole
{
    int y;
    int x;
};

struct Element_seta
{
    int y;
    int x;
    ll cena;
    bool operator < (const Element_seta &element_seta) const
    {
        if (cena == element_seta.cena)
        {
            if (y == element_seta.y)
                return x < element_seta.x;
            return y < element_seta.y;
        }
        return cena < element_seta.cena;
    }
};

int n = 0, t = 0, delta_SIZE = 4, akt = 0;
ll wyn = 1e18, INF = 1e18;
vector<vector<int>> liczby;
vector<vector<ll>> dp;
vector<vector<int>> dojscie[4];
vector<vector<int>> idx_poprzedniej[4];
vector<vector<int>> inicjalizacja;
vector<int> delta_X = {-1,1,0,0};
vector<int> delta_Y = {0,0,1,-1};
set<Element_seta> S;
queue<Element_seta> Q;
vector<Pole> gdzie_mozna_dojsc;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;

    liczby.assign(n,{});
    for (int i = 0; i < n; ++i)
        liczby[i].assign(n,0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> liczby[i][j];

    dp.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp[i].assign(n,INF);

    inicjalizacja.assign(n,{});
    for (int i = 0; i < n; ++i)
        inicjalizacja[i].assign(n,0);
    dojscie[0] = inicjalizacja;
    dojscie[1] = inicjalizacja;
    dojscie[2] = inicjalizacja;
    dojscie[3] = inicjalizacja;
    idx_poprzedniej[0] = inicjalizacja;
    idx_poprzedniej[1] = inicjalizacja;
    idx_poprzedniej[2] = inicjalizacja;
    idx_poprzedniej[3] = inicjalizacja;

    S.insert({0,0,0});
    dp[0][0] = 0;
    while(!S.empty())
    {
        Element_seta spr = *S.begin();
        S.erase(spr);

        gdzie_mozna_dojsc.clear();
        while(!Q.empty())
            Q.pop();

        Q.push({spr.y,spr.x,0});
        while(!Q.empty())
        {
            Element_seta spr_Q = Q.front();
            Q.pop();
            if (spr_Q.y == n-1 and spr_Q.x == n-1)
            {
                if (spr_Q.cena == 3)
                    wyn = min(wyn, spr.cena + spr_Q.cena * (ll)t + (ll)liczby[n-1][n-1]);
                else
                    wyn = min(wyn, spr.cena + spr_Q.cena * (ll)t);
            }
            if (spr_Q.cena == 3)
                gdzie_mozna_dojsc.push_back({spr_Q.y, spr_Q.x});
            else
            {
                for (int i = 0; i < delta_SIZE; ++i)
                {
                    int y = spr_Q.y + delta_Y[i], x = spr_Q.x + delta_X[i];
                    if (y >= 0 and y < n and x >= 0 and x < n)
                    {
                        if (idx_poprzedniej[spr_Q.cena+1][y][x] != akt)
                        {
                            idx_poprzedniej[spr_Q.cena+1][y][x] = akt;
                            dojscie[spr_Q.cena+1][y][x] = 0;
                        }
                        if (dojscie[spr_Q.cena+1][y][x] == 0)
                        {
                            dojscie[spr_Q.cena+1][y][x] = 1;
                            Q.push({y,x,spr_Q.cena+1});
                        }
                    }
                }
            }
        }
        akt++;

        for (int i = 0; i < gdzie_mozna_dojsc.size(); ++i)
        {
            int y = gdzie_mozna_dojsc[i].y, x = gdzie_mozna_dojsc[i].x, koszt = spr.cena + 3 * t + liczby[y][x];
            if (koszt < dp[y][x])
            {
                auto it = S.find({y,x,dp[y][x]});
                if (it != S.end())
                    S.erase(*it);
                dp[y][x] = koszt;
                S.insert({y,x,koszt});
            }
        }
    }

    cout << wyn << '\n';

    return 0;
}