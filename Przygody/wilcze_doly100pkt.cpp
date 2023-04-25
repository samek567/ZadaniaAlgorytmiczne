#include <iostream>
#include <vector>
#include <deque>

using namespace std;

long long n = 0, ile_mamy = 0, decha_size = 0, wczytana_liczba = 0, max_wyn = 0, poczatek = 0, koniec = 0;
vector<long long> doly;
vector<long long> sumy_prefiksowe;
deque<long long> Q;

int main()
{
    // Gasienica z kolejka monotonniczna.
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

    poczatek = decha_size;
    koniec = 1;
    Q.push_front(sumy_prefiksowe[poczatek] - sumy_prefiksowe[koniec-1]);

    while(true)
    {
        if (poczatek == n)
        {
            max_wyn = max(max_wyn,poczatek - koniec + 1);
            break;
        }
        else
        {
            long long suma_na_przedziale = sumy_prefiksowe[poczatek+1] - sumy_prefiksowe[koniec-1];
            long long ile_pokrywa_decha_spr = sumy_prefiksowe[poczatek+1] - sumy_prefiksowe[poczatek + 1 - decha_size];
            if (suma_na_przedziale - max(Q.front(),ile_pokrywa_decha_spr) <= ile_mamy)
            {
                poczatek++;
                while(!Q.empty())
                {
                    if (Q.back() < ile_pokrywa_decha_spr)
                        Q.pop_back();
                    else
                        break;
                }
                Q.push_back(ile_pokrywa_decha_spr);
            }
            else
            {
                if (poczatek - koniec == decha_size - 1)
                {
                    Q.clear();
                    Q.push_front(sumy_prefiksowe[poczatek+1] - sumy_prefiksowe[koniec]);
                    poczatek++;
                }
                else
                {
                    if (Q.front() == sumy_prefiksowe[koniec+decha_size-1] - sumy_prefiksowe[koniec-1])
                        Q.pop_front();
                }
                koniec++;
            }
        }
        max_wyn = max(max_wyn,poczatek - koniec + 1);
    }


    printf("%d",max(decha_size,max_wyn));

    return 0;
}