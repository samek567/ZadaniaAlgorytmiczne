#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n = 0, wczytana_liczba = 0, MOD = 1e4, ile_powtorzen = 1;
ll wyn = 0;
bool czy_jest_wieksze = false;
vector<int> grupy;
vector<int> liczby;

int main()
{
    // Sortowanie, zliczanie, kombinatoryka. O(N lg N)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    sort(liczby.begin(),liczby.end());

    for (int i = 1; i < n; ++i)
    {
        if (liczby[i] == liczby[i-1])
            ile_powtorzen++;
        else
        {
            grupy.push_back(ile_powtorzen);
            ile_powtorzen = 1;
        }
    }
    grupy.push_back(ile_powtorzen);

    if (grupy.size() == 1)
        wyn = 1;
    else
        wyn = 2;

    for (int i = 0; i < grupy.size() && czy_jest_wieksze == false; ++i)
    {
        for (int j = 1; j <= grupy[i] && czy_jest_wieksze == false; ++j)
        {
            wyn *= (ll)j;
            if (wyn >= 1000)
            {
                czy_jest_wieksze = true;
                break;
            }
        }
    }

    if (grupy.size() == 1)
        wyn = 1;
    else
        wyn = 2;

    if (czy_jest_wieksze == true)
    {
        for (int i = 0; i < grupy.size(); ++i)
            for (int j = 1; j <= grupy[i]; ++j)
                wyn = (wyn * (ll)j) % MOD;
        string ciag_string = to_string(wyn);
        for (int i = ciag_string.size(); i < 4; ++i)
            cout << "0";
        cout << wyn << '\n';
    }
    else
    {
        for (int i = 0; i < grupy.size(); ++i)
            for (int j = 1; j <= grupy[i]; ++j)
                wyn *= j;
        cout << wyn << '\n';
    }

    return 0;
}