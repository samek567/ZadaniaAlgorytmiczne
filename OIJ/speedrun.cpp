#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll n = 0, wczytana_liczba = 0, cnt = 0, wyn = 0, min_wyn = 1e15+5;
vector<ll> rodzice;
vector<ll> numer_spojnej;

void dfs(ll v)
{
    numer_spojnej[v] = cnt;
    if (numer_spojnej[rodzice[v]] == cnt)
    {
        // Odtwarzamy wynik dla spojnej skladowej. Wauwaz, ze najmniejszy wynik musi zaczynac sie w numer_spojnej[rodzice[v]]
        int wierzcholek_docelowy = rodzice[v];
        int wierzcholek_spr = rodzice[v];
        while (true)
        {
            if (wierzcholek_spr == wierzcholek_docelowy && wyn != 0)
                break;
            wyn += wierzcholek_spr;
            wierzcholek_spr = rodzice[wierzcholek_spr];
        }
    }
    else if (numer_spojnej[rodzice[v]] == -1)
        dfs(rodzice[v]);
    else
    {
        wyn = 1e15+5+5;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    numer_spojnej.assign(n+1,-1);
    rodzice.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        rodzice.push_back(wczytana_liczba);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (numer_spojnej[i] == -1)
        {
            wyn = 0;
            dfs(i);
            min_wyn = min(min_wyn,wyn);
            cnt++;
        }
    }
    printf("%lld",min_wyn);

    return 0;
}
