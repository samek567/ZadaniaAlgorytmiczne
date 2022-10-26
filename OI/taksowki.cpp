#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long CONST_KONCZACA = LLONG_MAX;
long long d = 0, m = 0, wczytana_liczba = 0, pozycja_Bajtazara = 0, min_ciezarowka_konczaca = CONST_KONCZACA;
int n = 0, ktory_idx_usun = 0;
vector<long long> ciezarowki;

void aktualizuj_pozycje_Bajtazara(long long v_ciezarowki)
{
    if (pozycja_Bajtazara < m)
    {
        pozycja_Bajtazara = max(pozycja_Bajtazara, pozycja_Bajtazara + v_ciezarowki - (m - pozycja_Bajtazara));
    }
    else if (pozycja_Bajtazara == m)
    {
        pozycja_Bajtazara += v_ciezarowki;
    }
    else
    {
        pozycja_Bajtazara = max(pozycja_Bajtazara, m + v_ciezarowki);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> d >> m >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba >= d - m)
        {
            min_ciezarowka_konczaca = min(min_ciezarowka_konczaca,wczytana_liczba);
        }
        ciezarowki.push_back(wczytana_liczba);
    }

    if (min_ciezarowka_konczaca == CONST_KONCZACA)
    {
        cout << "0" << "\n";
        return 0;
    }

    if (min_ciezarowka_konczaca >= m + d)
    {
        cout << "1" << "\n";
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        if (ciezarowki[i] == min_ciezarowka_konczaca)
        {
            ktory_idx_usun = i;
            break;
        }
    }
    ciezarowki.erase(ciezarowki.begin() + ktory_idx_usun);

    sort(ciezarowki.begin(),ciezarowki.end(),greater<long long>());

    for (int i = 0; i < n; ++i)
    {
        aktualizuj_pozycje_Bajtazara(ciezarowki[i]);
        if (pozycja_Bajtazara >= d)
        {
            cout << i+1 << "\n";
            return 0;
        }
        if (pozycja_Bajtazara >= m - (min_ciezarowka_konczaca - (d - m)) / 2)
        {
            cout << i+2 << "\n";
            return 0;
        }
    }

    cout << "0" << "\n";

    return 0;
}
