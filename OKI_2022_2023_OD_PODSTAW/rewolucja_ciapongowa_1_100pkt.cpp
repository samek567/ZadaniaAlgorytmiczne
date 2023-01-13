#include <iostream>
#include <vector>

using namespace std;

int n = 0, q = 0, a = 0, b = 0, wczytana_liczba = 0, poczatek_zap = 0, koniec_zap = 0;
vector<long long> sumy_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    sumy_prefiksowe.push_back(0);
    sumy_prefiksowe.push_back(0);
    for (int i = 0; i < n-1; ++i)
    {
        cin >> wczytana_liczba;
        sumy_prefiksowe.push_back(sumy_prefiksowe[i+1] + wczytana_liczba);
    }
    for (int i = 0; i < q; ++i)
    {
        cin >> a >> b;
        poczatek_zap = min(a,b);
        koniec_zap = max(a,b);
        printf("%lld\n",sumy_prefiksowe[koniec_zap] - sumy_prefiksowe[poczatek_zap]);
    }
    return 0;
}