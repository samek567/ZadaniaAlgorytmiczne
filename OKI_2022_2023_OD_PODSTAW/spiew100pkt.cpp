#include <iostream>

using namespace std;

int n = 0, ile_zajetych = 0, wyn;
char wczytany_znak;

int main()
{
    // O(n) Dzielimy klase na grupy sasiadow i dla kazdej grupy wynik to ile_elementow / 3, jesli ile_elementow % 3 != 0 -> wyn++.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'Z')
            ile_zajetych++;
        else
        {
            if (ile_zajetych != 0)
            {
                wyn += ile_zajetych / 3;
                if (ile_zajetych % 3 != 0)
                    wyn++;
                ile_zajetych = 0;
            }
            ile_zajetych = 0;
        }
    }
    if (ile_zajetych != 0)
    {
        wyn += ile_zajetych / 3;
        if (ile_zajetych % 3 != 0)
            wyn++;
    }
    printf("%d",wyn);

    return 0;
}