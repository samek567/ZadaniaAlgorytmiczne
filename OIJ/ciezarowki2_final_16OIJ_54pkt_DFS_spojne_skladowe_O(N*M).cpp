#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Krawedz_wejscie
{
    int w1;
    int w2;
    int cena;
    bool operator < (const Krawedz_wejscie &krawedz_wejscie) const
    {
        return cena < krawedz_wejscie.cena;
    }
};

int n = 0, m = 0, k = 0, a = 0, b = 0, c = 0, ile_ciezarowek = 0, ile_miast = 0, ile_dajemy = 0, ile_dalismy_ciezarowek = 0, ile_dalismy_miast = 0;
ll wyn = 0;
vector<vector<int>> krawedzie;
vector<Krawedz_wejscie> krawedzie_wejscie;
vector<bool> czy_jest_ciezarowka;
vector<bool> czy_jest_cel;
vector<bool> czy_bylismy;
vector<int> droga;

void DFS_ile (int v)
{
    droga.push_back(v);
    czy_bylismy[v] = true;
    if (czy_jest_ciezarowka[v] == true)
        ile_ciezarowek++;
    else if (czy_jest_cel[v] == true)
        ile_miast++;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i];
        if (czy_bylismy[wierz] == false)
            DFS_ile(wierz);
    }
}

int main()
{
    // Brut O(N*M), DFS, spojne skladowe
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    krawedzie.assign(n+1,{});
    czy_jest_ciezarowka.assign(n+1,false);
    czy_jest_cel.assign(n+1,false);
    czy_bylismy.assign(n+1,false);

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        krawedzie_wejscie.push_back({a,b,c});
    }
    sort(krawedzie_wejscie.begin(), krawedzie_wejscie.end());

    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> a;
        czy_jest_ciezarowka[a] = true;
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> a;
        czy_jest_cel[a] = true;
    }

    for (int i = 0; i < m; ++i)
    {
        fill(czy_bylismy.begin(), czy_bylismy.end(), false);
        krawedzie[krawedzie_wejscie[i].w1].push_back(krawedzie_wejscie[i].w2);
        krawedzie[krawedzie_wejscie[i].w2].push_back(krawedzie_wejscie[i].w1);
        for (int j = 1; j <= n; ++j)
        {
            if (czy_bylismy[j] == false)
            {
                droga.clear();
                ile_ciezarowek = 0, ile_miast = 0;
                DFS_ile(j);
                ile_dajemy = min(ile_ciezarowek, ile_miast), ile_dalismy_ciezarowek = 0, ile_dalismy_miast = 0;
                wyn += (ll)ile_dajemy * (ll)krawedzie_wejscie[i].cena;
                for (int k = 0; k < droga.size(); ++k)
                {
                    int wierz = droga[k];
                    if (czy_jest_ciezarowka[wierz] == true)
                    {
                        if (ile_dalismy_ciezarowek < ile_dajemy)
                        {
                            ile_dalismy_ciezarowek++;
                            czy_jest_ciezarowka[wierz] = false;
                        }
                    }
                    if (czy_jest_cel[wierz] == true)
                    {
                        if (ile_dalismy_miast < ile_dajemy)
                        {
                            ile_dalismy_miast++;
                            czy_jest_cel[wierz] = false;
                        }
                    }
                }
            }
        }
    }

    cout << wyn << '\n';

    return 0;
}