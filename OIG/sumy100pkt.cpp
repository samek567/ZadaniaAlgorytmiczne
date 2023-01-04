#include <iostream>

using namespace std;

unsigned long long n = 0, liczba = 0, ile = 0, do_dodania = 0,wsk_dod = 0;
const int wyn_SIZE = 30;
int wyn[wyn_SIZE];

int main()
{
    // O(n)
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    for (int i = 0; i < wyn_SIZE; ++i)
        wyn[i] = 0;
    cin >> n;
    for (unsigned long long i = 0; i < n; ++i)
    {
        cin >> liczba;
        ile += n-i;
        do_dodania = (ile - (i * (i+1) / 2)) * liczba;
        wsk_dod = wyn_SIZE-1;
        while (do_dodania > 0)
        {
            wyn[wsk_dod] += do_dodania % 10;
            do_dodania /= 10;
            wsk_dod--;
        }
    }
    for (int i = wyn_SIZE-1; i >= 0; --i)
    {
        wyn[i-1] += wyn[i] / 10;
        wyn[i] = wyn[i] % 10;
    }
    bool czy_bylo_rozne_od_zera = false;
    for (int i = 0; i < wyn_SIZE; ++i)
    {
        if (wyn[i] != 0)
            czy_bylo_rozne_od_zera = true;
        if (czy_bylo_rozne_od_zera == true)
            printf("%d",wyn[i]);
    }
    return 0;
}