#include <iostream>
#include <vector>
#include <deque>

using namespace std;

long long n = 0, ile_mamy = 0, decha_size = 0, wczytana_liczba = 0;
vector<long long> doly;
vector<long long> sumy_prefiksowe;

bool czy_pasuje(int x)
{
    if (decha_size >= x)
        return true;
    deque<long long> max_wziecie;
    int wsk_usuniecie = decha_size;
    for (int i = decha_size; i < x; ++i)
    {
        while(!max_wziecie.empty())
        {
            if (max_wziecie.back() < sumy_prefiksowe[i] - sumy_prefiksowe[i-decha_size])
                max_wziecie.pop_back();
            else
                break;
        }
        max_wziecie.push_back(sumy_prefiksowe[i] - sumy_prefiksowe[i-decha_size]);
    }
    for (int i = x; i <= n; ++i)
    {
        while(!max_wziecie.empty())
        {
            if (max_wziecie.back() < sumy_prefiksowe[i] - sumy_prefiksowe[i-decha_size])
                max_wziecie.pop_back();
            else
                break;
        }
        max_wziecie.push_back(sumy_prefiksowe[i] - sumy_prefiksowe[i-decha_size]);
        long long suma_na_przedziale = sumy_prefiksowe[i] - sumy_prefiksowe[i-x];
        if (suma_na_przedziale - max_wziecie.front() <= ile_mamy)
        {
            return true;
        }
        if (max_wziecie.front() == sumy_prefiksowe[wsk_usuniecie] - sumy_prefiksowe[wsk_usuniecie-decha_size])
            max_wziecie.pop_front();
        wsk_usuniecie++;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ile_mamy >> decha_size;

    doly.push_back(0);
    sumy_prefiksowe.push_back(0);

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        doly.push_back(wczytana_liczba);
        sumy_prefiksowe.push_back(sumy_prefiksowe[i]+wczytana_liczba);
    }

    int poczatek = -1;
    int koniec = n+1;
    int srodek = 0;
    while (koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_pasuje(srodek) == true)
        {
            poczatek = srodek;
        }
        else
        {
            koniec = srodek;
        }
    }
    printf("%d",poczatek);


    return 0;
}