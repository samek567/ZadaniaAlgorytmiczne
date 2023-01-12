#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, t = 0, a_i = 0, b_i = 0;
ll suma_na_przedziale = 0, ile_r_na_przedziale = 0, suma = 0;
char znak;
vector<char> znaki;
vector<ll> ile_n_na_lewo;
vector<ll> sumy_prefiksowe_r;
vector<ll> sumy_prefiksowe;

int main()
{
    // O(n + t)
    /*
    Dla kazdego elementu naliczamy ile mial by kolizji z wszystkimi elementami na przeodzie, potem musimy odjac jeszcze
    dla kazdej takiej liczby ile jest N przed. czyli musimy od sumy odjąć ile_N_przed * ile_r_w_przedziale.
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ile_n_na_lewo.assign(n,0);
    sumy_prefiksowe.assign(n,0);
    sumy_prefiksowe_r.assign(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> znak;
        znaki.push_back(znak);
    }
    for (int i = n-1; i >= 0; --i)
    {
        ile_n_na_lewo[i] = suma;
        if (znaki[i] == 'N')
            suma++;
    }
    suma = 0;
    for (int i = 0; i < n; ++i)
    {
        if (znaki[i] == 'R')
            suma += ile_n_na_lewo[i];
        sumy_prefiksowe[i] = suma;
    }
    suma = 0;
    for (int i = 0; i < n; ++i)
    {
        if (znaki[i] == 'R')
            suma++;
        sumy_prefiksowe_r[i] = suma;
    }
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> a_i >> b_i;
        a_i--;
        b_i--;
        if (a_i == 0)
        {
            suma_na_przedziale = sumy_prefiksowe[b_i];
            ile_r_na_przedziale = sumy_prefiksowe_r[b_i];
        }
        else
        {
            suma_na_przedziale = sumy_prefiksowe[b_i] - sumy_prefiksowe[a_i-1];
            ile_r_na_przedziale = sumy_prefiksowe_r[b_i] - sumy_prefiksowe_r[a_i-1];
        }
        printf("%lld\n",suma_na_przedziale - ile_r_na_przedziale * ile_n_na_lewo[b_i]);
    }
    return 0;
}
