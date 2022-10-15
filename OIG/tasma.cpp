#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m = 0;
    int n = 0;
    long long wczytana_liczba = 0;
    long long max_idx = 0;
    long long max_wynik = 0;

    cin >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> n;
        unordered_map<long long,vector<long long>> kolory;
        unordered_set<long long> wszystkie_kolory;
        vector<long long> do_mapa;
        max_idx = 0;
        max_wynik = 0;
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytana_liczba;
            wszystkie_kolory.insert(wczytana_liczba);
            if (auto it = kolory.find(wczytana_liczba) == kolory.end()) // Nie znalezlismy
            {
                kolory.insert({wczytana_liczba,do_mapa});
            }
            kolory[wczytana_liczba].push_back(j);
        }

        for (auto i : wszystkie_kolory)
        {
            max_idx = n-1;
            sort(kolory[i].begin(),kolory[i].end(), greater<long long>());
            for (int k = 0; k < kolory[i].size(); ++k)
            {
                if (kolory[i][k] == max_idx)
                {
                    max_idx--;
                }
                else
                {
                    max_wynik = max(max_wynik,max_idx - kolory[i][kolory[i].size()-1]); // Odwolujemy sie do najmniejszego(najkorzystniej), a do sprawdzania byl nam potrzebny od najwiekszych.
                    break;
                }
            }
        }
        if (max_wynik == 0)
        {
            cout << "BRAK" << endl;
        }
        else
        {
            cout << max_wynik << endl;
        }
    }
    return 0;
}