#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Relacja
{
    char kierunek;
    int dziecko;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int z = 0;

    cin >> z;

    for (int f = 0; f < z; ++f)
    {
        int n = 0;
        int r = 0;
        int a = 0;
        int b = 0;
        char kierunek;

        cin >> n >> r;

        char wierzcholki[n+1];
        for (int i = 1; i <= n; ++i)
        {
            wierzcholki[i] = 'Z';
        }


        vector<Relacja> realacje[n+1];
        queue<int> Q;

        for (int i = 0; i < r; ++i)
        {
            cin >> a >> b >> kierunek;
            realacje[a].push_back({kierunek,b});
            realacje[b].push_back({kierunek,a});
        }

        bool praca = true;
        for (int i = 1; praca && i <= n; ++i)
        {
            if (wierzcholki[i] != 'Z')
            {
                continue;
            }
            Q.push(i);
            wierzcholki[i] = 'P';
            while (praca && !Q.empty())
            {
                int rodzic = Q.front();
                for (int j = 0; j < realacje[rodzic].size(); ++j)
                {
                    Relacja rel = realacje[rodzic][j];
                    if (wierzcholki[rel.dziecko] == 'Z')//dziecko nowe
                    {
                        Q.push(rel.dziecko);
                        wierzcholki[rel.dziecko] = rel.kierunek == 'A' ? wierzcholki[rodzic] : wierzcholki[rodzic] == 'P' ? 'L' : 'P';
                    }
                    else//dziecko już przerabialismy
                    {
                        if (rel.kierunek == 'A' && wierzcholki[rodzic] != wierzcholki[rel.dziecko] || rel.kierunek == 'B' && wierzcholki[rodzic] == wierzcholki[rel.dziecko])
                        {
                            praca = false;
                            break;
                        }
                    }
                }
                Q.pop();
            }
        }

        if (praca)
        {
            cout << "TAK" << endl;
        }
        else
        {
            cout << "NIE" << endl;
        }
    }

    return 0;
}