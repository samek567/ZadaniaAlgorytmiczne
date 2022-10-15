#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int m = 0;
    int ile_liczb = 0;
    int aktualna_liczba = 0;
    int liczba_usunietych = 0;
    int liczba_usunietych_patrzacych_smok = 0;
    set<int> osiagalne_numery;

    cin >> n >> m;

    for(int i = 2; i <= n; ++i)
    {
        osiagalne_numery.insert(i);
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> ile_liczb;
        liczba_usunietych_patrzacych_smok = 0;
        set<int> skrzaty_obserwowane;
        vector<int> do_usuniecia;
        for (int j = 0; j < ile_liczb; ++j)
        {
            cin >> aktualna_liczba;
            skrzaty_obserwowane.insert(aktualna_liczba);
            if (auto it = osiagalne_numery.find(aktualna_liczba) == osiagalne_numery.end()) // Nie znalezlismy
            {
                liczba_usunietych_patrzacych_smok++;
            }
        }
        liczba_usunietych = n - osiagalne_numery.size();

        if (liczba_usunietych > liczba_usunietych_patrzacych_smok) // Sprawdzamy czy nastapilo rozlanie
        {
            // Nastapilo rozlanie
            for (auto k : osiagalne_numery)
            {
                if (auto it = skrzaty_obserwowane.find(k) == skrzaty_obserwowane.end()) // Nie znalezlismy
                {
                    if (k == n)
                    {
                        cout << i;
                        return 0;
                    }
                    do_usuniecia.push_back(k);
                }
            }

            for (int m = 0; m < do_usuniecia.size(); ++m)
            {
                osiagalne_numery.erase(do_usuniecia[m]);
            }
        }
    }
    cout << m;
    return 0;
}