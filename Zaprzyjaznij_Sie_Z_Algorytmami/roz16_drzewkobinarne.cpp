#include <iostream>
#include <vector>

using namespace std;

int n = 0, rozmiar_drzewa = 0;
long long wczytana_liczba = 0, min_wyn = 1e9;
vector<long long> liczby;
vector<long long> wyn;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    rozmiar_drzewa = (1 << n);
    wyn.assign(rozmiar_drzewa,0);
    liczby.assign(rozmiar_drzewa,0);
    for (int i = 1; i < rozmiar_drzewa; ++i)
    {
        cin >> wczytana_liczba;
        liczby[i] = wczytana_liczba;
    }

    wyn[1] = liczby[1];
    for (int i = 2; i < rozmiar_drzewa; ++i)
        wyn[i] = wyn[i/2] + liczby[i];

    for (int i = rozmiar_drzewa / 2; i < rozmiar_drzewa; ++i)
        min_wyn = min(min_wyn,wyn[i]);
    printf("%lld",min_wyn);

    return 0;
}
