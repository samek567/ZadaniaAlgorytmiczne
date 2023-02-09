#include <iostream>

using namespace std;
typedef long long ll;

int t = 0, n = 0, q = 0;
ll max_wyn_dod = 0, max_wyn_odj = 0, wczytana_liczba = 0;

int main()
{
    // Programowanie dynamiczne. O(N), gdzie N, to suma wszystkich n z wejscia.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        max_wyn_dod = -1e9, max_wyn_odj = -1e9;
        for (int i = 0; i < n; ++i)
        {
            cin >> wczytana_liczba;
            ll max_wyn_odj_wczesniej = max_wyn_odj;
            max_wyn_odj = max(max_wyn_odj,max_wyn_dod - wczytana_liczba);
            max_wyn_dod = max(max_wyn_dod,max((ll)wczytana_liczba,max_wyn_odj_wczesniej + wczytana_liczba));
        }
        cout << max(max_wyn_dod,max_wyn_odj) << '\n';
    }
    return 0;
}