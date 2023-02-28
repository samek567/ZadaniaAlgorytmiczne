#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element
{
    int y;
    int x;
};

int n = 0, wczytana_liczba = 0, delta_SIZE = 8, wyn_gora = 0, wyn_dolek = 0;
bool czy_mozna_wieksze = true, czy_mozna_mniejsce = true;
vector<vector<int>> liczby;
vector<vector<bool>> czy_bylismy;
vector<int> delta_Y = {-1,-1,-1,1,1,1,0,0};
vector<int> delta_X = {0,-1,1,0,-1,1,1,-1};
queue<Element> Q;

int main()
{
    // O(N^2), dzielimy graf na spojne skladowe DFS-em(DFS rekurencyjny na szkopule przechodzi na 80pkt(przekroczono limit pamieci)),
    // wiec zamienilem na iteracyjnego BFS-a(mozna tez na stosie). Dla kazdej spojnej skladowej sprawdzamy, czy moze byc ona dolkiem / dolina.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        liczby.push_back({});
        czy_bylismy.push_back({});
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytana_liczba;
            liczby[i].push_back(wczytana_liczba);
            czy_bylismy[i].push_back(false);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (czy_bylismy[i][j] == false)
            {
                czy_mozna_mniejsce = true;
                czy_mozna_wieksze = true;
                Q.push({i,j});
                czy_bylismy[i][j] = true;
                while(!Q.empty())
                {
                    int y = Q.front().y;
                    int x = Q.front().x;
                    Q.pop();
                    for (int i = 0; i < delta_SIZE; ++i)
                    {
                        if (y + delta_Y[i] >= 0 and y + delta_Y[i] < n and x + delta_X[i] >= 0 and x + delta_X[i] < n)
                        {
                            if (liczby[y + delta_Y[i]][x + delta_X[i]] == liczby[y][x] && czy_bylismy[y + delta_Y[i]][x + delta_X[i]] == false)
                            {
                                czy_bylismy[y + delta_Y[i]][x + delta_X[i]] = true;
                                Q.push({y + delta_Y[i], x + delta_X[i]});
                            }
                            if (liczby[y + delta_Y[i]][x + delta_X[i]] > liczby[y][x])
                                czy_mozna_wieksze = false;
                            if (liczby[y + delta_Y[i]][x + delta_X[i]] < liczby[y][x])
                                czy_mozna_mniejsce = false;
                        }
                    }
                }
                if (czy_mozna_wieksze == true)
                    wyn_gora++;
                if (czy_mozna_mniejsce == true)
                    wyn_dolek++;
            }
        }
    }


    cout << wyn_gora << ' ' << wyn_dolek << '\n';

    return 0;
}