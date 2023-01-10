#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Pole
{
    int y;
    int x;
};

struct Element_seta
{
    int czas_do_maskowania;
    int y;
    int x;
    bool operator < (const Element_seta &element_seta) const
    {
        return czas_do_maskowania < element_seta.czas_do_maskowania;
    }
};

int a = 0, b = 0, m = 0, dlugosc_weza = 0, wczytana_liczba = 0, cnt = 0, czas = 1;
char wczytany_znak;
vector<vector<int>> plansza;
Pole glowa_weza = {0,0};
multiset<Element_seta> maskowania;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    for (int i = 0; i < a; ++i)
    {
        plansza.push_back({});
        for (int j = 0; j < b; ++j)
        {
            cin >> wczytana_liczba;
            plansza[i].push_back(wczytana_liczba);
        }
    }
    cin >> m >> dlugosc_weza;
    if (plansza[0][0] <= dlugosc_weza && plansza[0][0] > 1)
        maskowania.insert({plansza[0][0],0,0});

    for (int i = 0; i < m; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'N')
            glowa_weza.y--;
        else if (wczytany_znak == 'S')
            glowa_weza.y++;
        else if (wczytany_znak == 'E')
            glowa_weza.x++;
        else
            glowa_weza.x--;
        czas++;

        // Dodajemy w jakim czasie bedzie sie maskowac element o wspolrzednych i,j.
        if(plansza[glowa_weza.y][glowa_weza.x] <= dlugosc_weza)
            maskowania.insert({czas+plansza[glowa_weza.y][glowa_weza.x]-1,glowa_weza.y,glowa_weza.x});

        // Ile sie maskuje obecnie
        cnt = 0;
        while (!maskowania.empty())
        {
            if (maskowania.begin()->czas_do_maskowania == czas)
            {
                cnt++;
                maskowania.erase(maskowania.lower_bound(*maskowania.begin()));
            }
            else
                break;
        }

        printf("%d ",cnt);
    }
    return 0;
}
