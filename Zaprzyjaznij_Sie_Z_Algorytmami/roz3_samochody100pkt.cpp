#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba, suma_naliczanie = 0;
long long wyn = 0;
vector<int> liczby;
vector<int> sumy_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    sumy_prefiksowe.assign(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    for (int i = n-1; i >= 0; --i)
    {
        if (liczby[i] == 1)
            suma_naliczanie++;
        sumy_prefiksowe[i] = suma_naliczanie;
    }

    for (int i = 0; i < n; ++i)
    {
        if (liczby[i] == 0)
        {
            wyn += sumy_prefiksowe[i];
        }
    }

    printf("%lld",wyn);

    return 0;
}
