#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int q = 0, n = 0, m = 0, wczytana_liczba = 0;
ll suma = 0;
bool czy_ulozylismy = false, czy_mamy_parzysta_tekst = false, czy_mamy_nieparzysta_tekst = false, czy_mamy_parzysta_wzorzec = false, czy_mamy_nieparzysta_wzorzec = false;
vector<ll> sumy_prefiksowe_tekst;
vector<ll> sumy_prefiksowe_wzorzec;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--)
    {
        cin >> n >> m;
        sumy_prefiksowe_tekst.clear();
        sumy_prefiksowe_wzorzec.clear();
        suma = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> wczytana_liczba;
            suma += wczytana_liczba;
            sumy_prefiksowe_tekst.push_back(suma);
        }
        suma = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> wczytana_liczba;
            suma += wczytana_liczba;
            sumy_prefiksowe_wzorzec.push_back(suma);
        }
        for (int i = m; i >= 1; --i)
        {
            czy_ulozylismy = false;
            czy_mamy_nieparzysta_tekst = false;
            czy_mamy_nieparzysta_wzorzec = false;
            czy_mamy_parzysta_tekst = false;
            czy_mamy_parzysta_wzorzec = false;

            for (int j = 0; j <= n - i; ++j)
            {
                if (j == 0)
                    suma = sumy_prefiksowe_tekst[j+i-1];
                else
                    suma = sumy_prefiksowe_tekst[j+i-1] - sumy_prefiksowe_tekst[j-1];
                if (suma % 2 == 0)
                    czy_mamy_parzysta_tekst = true;
                else
                    czy_mamy_nieparzysta_tekst = true;
                if (czy_mamy_parzysta_tekst == true && czy_mamy_nieparzysta_tekst == true)
                    break;
            }
            for (int j = 0; j <= m - i; ++j)
            {
                if (j == 0)
                    suma = sumy_prefiksowe_wzorzec[j+i-1];
                else
                    suma = sumy_prefiksowe_wzorzec[j+i-1] - sumy_prefiksowe_wzorzec[j-1];
                if (suma % 2 == 0)
                    czy_mamy_parzysta_wzorzec = true;
                else
                    czy_mamy_nieparzysta_wzorzec = true;
                if (czy_mamy_parzysta_wzorzec == true && czy_mamy_nieparzysta_wzorzec == true)
                    break;
            }

            if (czy_mamy_parzysta_wzorzec == true && czy_mamy_parzysta_tekst == true)
            {
                printf("%d\n",i);
                czy_ulozylismy = true;
                break;
            }
            if (czy_mamy_nieparzysta_wzorzec == true && czy_mamy_nieparzysta_tekst == true)
            {
                printf("%d\n",i);
                czy_ulozylismy = true;
                break;
            }
        }
        if (czy_ulozylismy == false)
        {
            printf("0\n");
        }
    }
    return 0;
}
