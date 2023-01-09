#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int n = 0, m = 0, z = 0, wczytana_liczba = 0, d_i = 0, m_i = 0, poczatek = 0, koniec = 0, srodek = 0;
char kierunek_zamiany;
ll suma = 0;
vector<ll> sumy_prefiksowe_arbuzanow;
vector<ll> sumy_prefiksowe_bananitow;

int main()
{
    // O(z * max(n,m))
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    sumy_prefiksowe_arbuzanow.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        sumy_prefiksowe_arbuzanow.push_back(sumy_prefiksowe_arbuzanow[i] + wczytana_liczba);
    }
    sumy_prefiksowe_bananitow.push_back(0);
    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        sumy_prefiksowe_bananitow.push_back(sumy_prefiksowe_bananitow[i] + wczytana_liczba);
    }
    cin >> z;
    for (int i = 0; i < z; ++i)
    {
        cin >> d_i >> m_i >> kierunek_zamiany;
        if (kierunek_zamiany == 'A')
        {
            suma = sumy_prefiksowe_arbuzanow[m_i-1] + d_i;
            poczatek = -1;
            koniec = m;
            while(koniec - poczatek > 1)
            {
                srodek = (poczatek + koniec) / 2;
                if (sumy_prefiksowe_bananitow[srodek] < suma)
                    poczatek = srodek;
                else
                    koniec = srodek;
            }
            printf("%lld %d\n",suma - sumy_prefiksowe_bananitow[poczatek],poczatek+1);
        }
        else
        {
            suma = sumy_prefiksowe_bananitow[m_i-1] + d_i;
            poczatek = -1;
            koniec = n;
            while(koniec - poczatek > 1)
            {
                srodek = (poczatek + koniec) / 2;
                if (sumy_prefiksowe_arbuzanow[srodek] < suma)
                    poczatek = srodek;
                else
                    koniec = srodek;
            }
            printf("%lld %d\n",suma - sumy_prefiksowe_arbuzanow[poczatek],poczatek+1);
        }
    }
    return 0;
}