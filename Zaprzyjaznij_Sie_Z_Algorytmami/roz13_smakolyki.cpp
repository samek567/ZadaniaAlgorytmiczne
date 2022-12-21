#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0;
long long wyn = 0;
vector<int> liczby;
vector<bool> czy_mamy;

int main()
{
    /*
    Zlozonnosc sie amortyzuje do O(n+m), petla i oraz j wykonaja maksymalnie 2*n operacji, petla k maksymalnie n operacji.
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    czy_mamy.assign(m+1, false);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (czy_mamy[liczby[j]] == true)
            {
                wyn += (j-i) * (j-i+1) / 2;
                i += (j-i-1);
                for (int k = j; k >= i; --k)
                {
                    czy_mamy[liczby[k]] = false;
                }
            }
            else
                czy_mamy[liczby[j]] = true;
        }
    }

    printf("%lld",wyn);

    return 0;
}
