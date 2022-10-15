#include <iostream>
#include <queue>

using namespace std;

struct Reakcja_chemiczna{
    int ile_brakuje;
    vector<int> jakie_otrzymamy;
};

queue<int> Q;
vector<bool> czy_mamy_zwiazek;
vector<Reakcja_chemiczna> reakcje_chemiczne;
vector<vector<int>> gdzie_znajduje_sie_zwiazek;
int ile_mamy_zwiazkow = 0;

void program()
{
    while(!Q.empty())
    {
        int spr = Q.front();
        for (int i = 0; i < gdzie_znajduje_sie_zwiazek[spr].size(); ++i)
        {
            int i_j = gdzie_znajduje_sie_zwiazek[spr][i];
            reakcje_chemiczne[i_j].ile_brakuje--;
            if (reakcje_chemiczne[i_j].ile_brakuje == 0)
            {
                // Rozlanie
                for (int j = 0; j < reakcje_chemiczne[i_j].jakie_otrzymamy.size(); ++j)
                {
                    if (czy_mamy_zwiazek[reakcje_chemiczne[i_j].jakie_otrzymamy[j]] == false)
                    {
                        ile_mamy_zwiazkow++;
                        czy_mamy_zwiazek[reakcje_chemiczne[i_j].jakie_otrzymamy[j]] = true;
                        Q.push(reakcje_chemiczne[i_j].jakie_otrzymamy[j]);
                    }
                }
            }
        }
        Q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0, k = 0, r = 0, wczytany_zwiazek = 0, ile_potrzeba = 0, ile_otrzymamy = 0;

    cin >> n >> k >> r;

    czy_mamy_zwiazek.assign(n+1,false);

    for (int i = 0; i <= n; ++i)
    {
        gdzie_znajduje_sie_zwiazek.push_back({});
    }

    for (int i = 0; i < k; ++i)
    {
        cin >> wczytany_zwiazek;
        czy_mamy_zwiazek[wczytany_zwiazek] = true;
        Q.push(wczytany_zwiazek);
    }

    for (int i = 0; i < r; ++i)
    {
        cin >> ile_potrzeba;
        reakcje_chemiczne.push_back({ile_potrzeba,{}});
        for (int j = 0; j < ile_potrzeba; ++j)
        {
            cin >> wczytany_zwiazek;
            gdzie_znajduje_sie_zwiazek[wczytany_zwiazek].push_back(i);
        }
        cin >> ile_otrzymamy;
        for (int j = 0; j < ile_otrzymamy; ++j)
        {
            cin >> wczytany_zwiazek;
            reakcje_chemiczne[i].jakie_otrzymamy.push_back(wczytany_zwiazek);
        }
    }

    program();

    cout << ile_mamy_zwiazkow;

    return 0;
}