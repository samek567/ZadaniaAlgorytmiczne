#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

int n = 0, wyn = 0, suma = 0, base = 0, rozmiar_drzewa = 0;
char wczytany_znak;
vector<int> salatka;
vector<int> drzewo_przedzialowe_minow;
vector<int> drzewo_przedzialowe_maxow;
unordered_map<int,vector<int>> najdalsze_idx;

int querry_min(int p, int k)
{
    int poczatek = p + base - 1;
    int koniec = k + base + 1;
    int wynik_zapytanie = 1e9;

    while(poczatek / 2 != koniec / 2)
    {
        if (poczatek % 2 == 0)
            wynik_zapytanie = min(wynik_zapytanie,drzewo_przedzialowe_minow[poczatek+1]);
        if (koniec % 2 == 1)
            wynik_zapytanie = min(wynik_zapytanie,drzewo_przedzialowe_minow[koniec-1]);
        poczatek /= 2;
        koniec /= 2;
    }

    return wynik_zapytanie;
}

int querry_max(int p, int k)
{
    int poczatek = p + base - 1;
    int koniec = k + base + 1;
    int wynik_zapytanie = -1e9;

    while(poczatek / 2 != koniec / 2)
    {
        if (poczatek % 2 == 0)
            wynik_zapytanie = max(wynik_zapytanie,drzewo_przedzialowe_maxow[poczatek+1]);
        if (koniec % 2 == 1)
            wynik_zapytanie = max(wynik_zapytanie,drzewo_przedzialowe_maxow[koniec-1]);
        poczatek /= 2;
        koniec /= 2;
    }

    return wynik_zapytanie;
}

int main()
{
    // Korzystam z obserwacji, ze najdalszy max na przedziale musi byc wynikiem.
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n;

    base = pow(2,ceil((double)log2(n+1)));
    rozmiar_drzewa = base * 2;
    drzewo_przedzialowe_minow.assign(rozmiar_drzewa,0);
    drzewo_przedzialowe_maxow.assign(rozmiar_drzewa,0);

    salatka.push_back(0);
    najdalsze_idx[0].push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'p')
            suma++;
        else
            suma--;
        salatka.push_back(suma);
        najdalsze_idx[suma].push_back(i);
    }

    for (int i = 0; i <= n; ++i)
    {
        drzewo_przedzialowe_minow[base+i] = salatka[i];
        drzewo_przedzialowe_maxow[base+i] = salatka[i];
    }

    for (int i = base-1; i >= 1; --i)
    {
        drzewo_przedzialowe_minow[i] = min(drzewo_przedzialowe_minow[i*2],drzewo_przedzialowe_minow[i*2+1]);
        drzewo_przedzialowe_maxow[i] = max(drzewo_przedzialowe_maxow[i*2],drzewo_przedzialowe_maxow[i*2+1]);
    }

    for (int i = 0; i < n+1; ++i)
    {
        int idx_ostatniej_pasuajcej = i;
        int pocz = i-1;
        int kon = n+1;
        int srod = 0;

        while (kon - pocz != 1)
        {
            srod = (pocz + kon) / 2;
            if (querry_min(pocz,srod) < salatka[i])
            {
                kon = srod;
            }
            else
            {
                pocz = srod;
            }
        }
        idx_ostatniej_pasuajcej = pocz;

        int max_na_przedziale = querry_max(i,idx_ostatniej_pasuajcej);
        int poczatek_binary = -1;
        int koniec_binary = najdalsze_idx[max_na_przedziale].size();
        int srodek_binary = 0;

        while (koniec_binary - poczatek_binary != 1)
        {
            srodek_binary = (poczatek_binary + koniec_binary) / 2;
            if (najdalsze_idx[max_na_przedziale][srodek_binary] > idx_ostatniej_pasuajcej)
            {
                koniec_binary = srodek_binary;
            }
            else
            {
                poczatek_binary = srodek_binary;
            }
        }


        if (poczatek_binary != -1)
        {
            wyn = max(wyn,najdalsze_idx[max_na_przedziale][poczatek_binary]-i);
        }
    }

    printf("%d",wyn);

    return 0;
}