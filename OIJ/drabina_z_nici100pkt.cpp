#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element_kolejki
{
    int wierzcholek;
    int kolor;
};

int n = 0, m = 0, a_i = 0, b_i = 0, ile_w_spojnej = 0, do_ilu_wchodzi_jeden = 0, do_ilu_wchodza_trzy = 0, w1 = 0, w2 = 0, ile_odwiedzilismy = 2;
vector<vector<int>> krawedzie;
vector<int> ile_wchodzi;
vector<bool> czy_bylismy;
vector<int> wierzcholki_startowe;
queue<Element_kolejki> Q;
vector<int> wyniki[5];

void DFS_ile_spojnych(int v)
{
    ile_w_spojnej++;
    czy_bylismy[v] = true;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i];
        if (czy_bylismy[wierz] == false)
            DFS_ile_spojnych(wierz);
    }
}

bool czy_mozna(int wierzcholek1, int wierzcholek2)
{
    int syn1 = krawedzie[wierzcholek1][0], syn2 = krawedzie[wierzcholek2][0];
    for (int i = 0; i < krawedzie[syn1].size(); ++i)
        if (krawedzie[syn1][i] == syn2)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    ile_wchodzi.assign(n+1,0);
    czy_bylismy.assign(n+1,false);
    krawedzie.assign(n+1,{});

    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        ile_wchodzi[a_i]++;
        ile_wchodzi[b_i]++;
        krawedzie[a_i].push_back(b_i);
        krawedzie[b_i].push_back(a_i);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (ile_wchodzi[i] == 1)
        {
            do_ilu_wchodzi_jeden++;
            wierzcholki_startowe.push_back(i);
        }
        else if (ile_wchodzi[i] == 3)
            do_ilu_wchodza_trzy++;
    }

    DFS_ile_spojnych(1);

    if (do_ilu_wchodzi_jeden == 4 and do_ilu_wchodza_trzy == n - 4 and n % 2 == 0 and ile_w_spojnej == n)
    {

    }
    else
    {
        cout << "NIE" << '\n';
        return 0;
    }

    for (int i = 0; i < wierzcholki_startowe.size(); ++i)
    {
        for (int j = i+1; j < wierzcholki_startowe.size(); ++j)
        {
            if (czy_mozna(wierzcholki_startowe[i],wierzcholki_startowe[j]) == true)
            {
                w1 = wierzcholki_startowe[i];
                w2 = wierzcholki_startowe[j];
            }
        }
    }

    fill(czy_bylismy.begin(), czy_bylismy.end(), false);
    Q.push({w1,0});
    Q.push({w2,1});
    wyniki[0].push_back(w1);
    wyniki[1].push_back(w2);
    czy_bylismy[w1] = true;
    czy_bylismy[w2] = true;

    while(!Q.empty())
    {
        Element_kolejki spr = Q.front();
        Q.pop();
        int ile_znaczylismy = 0;
        for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
        {
            int wierz = krawedzie[spr.wierzcholek][i];
            if (czy_bylismy[wierz] == false)
            {
                ile_znaczylismy++;
                wyniki[spr.kolor].push_back(wierz);
                Q.push({wierz, spr.kolor});
                czy_bylismy[wierz] = true;
            }
        }
        if (wierzcholki_startowe[0] == spr.wierzcholek or wierzcholki_startowe[1] == spr.wierzcholek or wierzcholki_startowe[2] == spr.wierzcholek or wierzcholki_startowe[3] == spr.wierzcholek)
            continue;
        if (ile_znaczylismy != 1)
        {
            cout << "NIE";
            return 0;
        }
    }

    cout << "TAK" << endl;
    for (int i = 0; i < n / 2; ++i)
        cout << wyniki[1][i] << ' ' << wyniki[0][i] << '\n';

    return 0;
}