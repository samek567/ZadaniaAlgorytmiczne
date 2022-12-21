#include <iostream>
#include <vector>

using namespace std;

int n = 0, wyn = 0;
long long suma = 0, wczytana_liczba = 0, ile_musi_byc_w_szklance = 0;
vector<long long> szklanki;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        suma += wczytana_liczba;
        szklanki.push_back(wczytana_liczba);
    }
    ile_musi_byc_w_szklance = suma / n;

    for (int i = 0; i < n-1; ++i)
    {
        if (szklanki[i] > ile_musi_byc_w_szklance)
        {
            szklanki[i+1] += szklanki[i] - ile_musi_byc_w_szklance;
            wyn++;
        }
        else if (szklanki[i] < ile_musi_byc_w_szklance)
        {
            szklanki[i+1] -= ile_musi_byc_w_szklance - szklanki[i];
            wyn++;
        }
    }

    printf("%d",wyn);

    return 0;
}
