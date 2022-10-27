#include <iostream>
#include <vector>

using namespace std;

struct Przedzial
{
    int l;
    int k;
};

int n = 0, m = 0, wczytana_suma = 0, idx_pierwszej_wanilli = -1, idx_ostatniej_wanilli = -1, poczatek_przedzialu = 1, koniec_przedzialu = 0;
char wczytany_znak;
vector<int> lizak;
Przedzial przedzialy[2000009];

void obcinaj_przedzial()
{
    int p = poczatek_przedzialu;
    int k = koniec_przedzialu;
    int suma = 0;

    for (int i = poczatek_przedzialu; i <= koniec_przedzialu; ++i)
    {
        suma += lizak[i];
    }

    while (p <= k)
    {
        przedzialy[suma] = {p,k};
        if (lizak[p] == 2)
        {
            p++;
        }
        else if (lizak[k] == 2)
        {
            k--;
        }
        else // wiemy ze jak nie ma truskawki na obu to napewno suma jest tez 2 czyli oba sa waniliowe!
        {
            p++;
            k--;
        }
        suma -= 2;
        przedzialy[suma] = {p,k};
    }
}

int main()
{
    // Rozwiazanie w O(n+m) opiera sie na prostej obserwacji, ze z dowolnego fragmentu lizaka mozemy obciac fragment o sumie 2.
    // Wynika to z tego, ze jesli ktores z nich bedzie truskawka, to mamy sume 2, a jak oba nie beda truskawka to beda oba wanilia, czyli mozemy obciac obydwa.
    // Szukamy wiec najblizszego przedzialu o sumie parzystej i niepatrzystej i mamy rozwiazanie skracamy te 2 fragmenty dopoki mozemy
    // Zauwazamy, ze pierwsza spotkana wanilia zmienia znak, wiec szukamy pierwszej wanilli z lewej lub prawej ktora jest blizesz brzegu lewa lewego i prawa prawego.
    // I tak dzielimy na znak o nieparzystej / parzystej sumie zalezy od sytuacji jaka byla poczatkowego fragmentu. Napelniamy statystyki tych przedzialow i potem w O(1) odpowiadamy na kazde zapytanie.
    // O(n+m) , bo mamy n liczb i m zapytan.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 2000009; ++i)
    {
        przedzialy[i] = {-1,-1};
    }

    lizak.push_back(-1);

    cin >> n >> m;

    koniec_przedzialu = n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'T')
        {
            lizak.push_back(2);
        }
        else
        {
            lizak.push_back(1);
        }
    }

    if (lizak.size() == 2 && lizak[1] == 1)
    {
        przedzialy[1] = {1,1};
    }
    else
    {
        obcinaj_przedzial();

        for (int i = 1; i <= n; ++i)
        {
            if (lizak[i] == 1)
            {
                idx_pierwszej_wanilli = i;
                break;
            }
        }

        for (int i = n; i >= 1; --i)
        {
            if (lizak[i] == 1)
            {
                idx_ostatniej_wanilli = i;
                break;
            }
        }

        if (idx_pierwszej_wanilli != -1 && idx_ostatniej_wanilli != -1) // Obcinamy i robimy nieparzysty przedzial.
        {
            if (idx_pierwszej_wanilli < n - idx_ostatniej_wanilli + 1)
            {
                poczatek_przedzialu = idx_pierwszej_wanilli + 1;
            }
            else
            {
                koniec_przedzialu = idx_ostatniej_wanilli - 1;
            }
            obcinaj_przedzial();
        }
    }


    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_suma;
        if (przedzialy[wczytana_suma].l == -1 && przedzialy[wczytana_suma].k == -1)
        {
            cout << "NIE" << "\n";
        }
        else
        {
            cout << przedzialy[wczytana_suma].l << " " << przedzialy[wczytana_suma].k << "\n";
        }
    }
    return 0;
}
