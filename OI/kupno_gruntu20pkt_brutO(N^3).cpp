#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, wczytana_liczba = 0, lewy_wsk = 0, prawy_wsk = 0;
ll k = 0, suma_w_gasienciy = 0;
bool czy_znalezlismy = false;
int wartosci[2001][2001];
ll sumy_prefiksowe[2001][2001];
ll wysokosci[2001];

void przesuwaj_lewy()
{
    suma_w_gasienciy -= wysokosci[lewy_wsk];
    lewy_wsk++;
    if (lewy_wsk > prawy_wsk)
    {
        prawy_wsk = lewy_wsk;
        suma_w_gasienciy = wysokosci[lewy_wsk];
    }
}

int main()
{
    // O(N^3) Bierzemy kazda pare i,j (gora i dol prostokata) i odpalamy gasienice.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> wartosci[i][j];

    for (int i = 0; i < n; ++i)
    {
        ll suma = 0;
        for (int j = 0; j < n; ++j)
        {
            suma += wartosci[j][i];
            sumy_prefiksowe[j][i] = suma;
        }
    }

    for (int i = 0; i < n && czy_znalezlismy == false; ++i)
    {
        for (int j = i; j < n && czy_znalezlismy == false; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                if (i == 0)
                    wysokosci[k] = sumy_prefiksowe[j][k];
                else
                    wysokosci[k] = sumy_prefiksowe[j][k] - sumy_prefiksowe[i-1][k];
            }
            suma_w_gasienciy = wysokosci[0], lewy_wsk = 0, prawy_wsk = 0;
            while(true)
            {
                if (suma_w_gasienciy >= k && suma_w_gasienciy <= 2*k)
                {
                    czy_znalezlismy = true;
                    cout << lewy_wsk+1 << " " << i+1 << " " << prawy_wsk+1 << " " << j+1 << '\n';
                    break;
                }
                if (lewy_wsk == prawy_wsk && prawy_wsk == n-1)
                    break;
                else if (prawy_wsk == n-1)
                    przesuwaj_lewy();
                else if (suma_w_gasienciy + wysokosci[prawy_wsk+1] <= 2*k)
                {
                    suma_w_gasienciy += wysokosci[prawy_wsk+1];
                    prawy_wsk++;
                }
                else
                    przesuwaj_lewy();
            }
        }
    }

    if (czy_znalezlismy == false)
        cout << "NIE" << '\n';

    return 0;
}
