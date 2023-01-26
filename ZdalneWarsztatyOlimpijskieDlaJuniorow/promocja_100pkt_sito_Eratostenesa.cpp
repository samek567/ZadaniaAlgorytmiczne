#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n = 0, m = 0, wczytana_liczba = 0;
ll cnt = 0, licznik = 0;
vector<bool> czy_bylismy(1e6+1,false);
vector<bool> czy_jest_zabawka(1e6+1,false);
vector<int> stat(1e6+1,0);
vector<ll> wyn_vect;

int main()
{
    // Sito Eratostenesa
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while(n--)
    {
        cin >> wczytana_liczba;
        czy_jest_zabawka[wczytana_liczba] = true;
    }
    for (int i = 1; i <= 1e6; ++i)
        stat[i] = i;
    cin >> m;
    while(m--)
    {
        cin >> wczytana_liczba;
        licznik = 0;
        while(stat[wczytana_liczba] <= 1e6 && licznik < wczytana_liczba)
        {
            if (czy_bylismy[stat[wczytana_liczba]] == false)
            {
                czy_bylismy[stat[wczytana_liczba]] = true;
                if (czy_jest_zabawka[stat[wczytana_liczba]] == true)
                    wyn_vect.push_back(cnt+licznik);
            }
            else
                licznik--;
            stat[wczytana_liczba] += wczytana_liczba;
            licznik++;
        }
        cnt += wczytana_liczba;
    }

    sort(wyn_vect.begin(),wyn_vect.end());
    printf("%d\n",wyn_vect.size());
    for (int i = 0; i < wyn_vect.size(); ++i)
        printf("%lld\n",wyn_vect[i]+1);

    return 0;
}