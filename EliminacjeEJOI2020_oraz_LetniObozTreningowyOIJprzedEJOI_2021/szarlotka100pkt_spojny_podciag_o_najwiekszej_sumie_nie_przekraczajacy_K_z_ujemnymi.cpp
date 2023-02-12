#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

int n = 0;
ll k = 0, wczytana_liczba = 0, suma = 0, wyn = 1e18;
vector<ll> liczby;
vector<ll> sumy_prefiksowe;
set<ll> S;

int main()
{
    // O(N lg N), praktycznie to zadanie, to szukanie spojnego podciagu o najwieszej sumie nie przekraczajacego K.
    // Posortowanie sum prefiksowych i robienie binary searcha dla ujemnych nie dziala, bo dla idx-u i, mozemy trafic na sume prefiksowa z np. idx-u i-5,
    // idac z setem nie ma tego problemu
    // Sumy prefiksowe z binary searchem (dla A_i >= 0 ograniczenie) wchodzi na 70pkt.
    // Dla kazdego elementu i, szukamy spojnego podciagu o najwiekszej sumie, zaczynajacego sie i, majacego jak najwieksza sume nie przekraczajaca k, i sprawdzamy min_wyn,
    // potem spojnego podciagu o najmniejszej sumie, >= k, i tak samo sprawdzamy min_wyn.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        suma += wczytana_liczba;
        sumy_prefiksowe.push_back(suma);
    }

    // Dla kazdej liczby szukamy
    for (int i = n-1; i >= 0; --i)
    {
        S.insert(sumy_prefiksowe[i]);
        ll suma_zapytanie = 0;
        if (i == 0)
            suma_zapytanie = k;
        else
            suma_zapytanie = sumy_prefiksowe[i-1] + k;
        auto it = S.upper_bound(suma_zapytanie);

        if (it != S.end())
        {
            if (i == 0)
                wyn = min(wyn, abs(*it - k));
            else
                wyn = min(wyn, abs((*it - sumy_prefiksowe[i-1]) - k));
        }

        if (it != S.begin())
        {
            --it;
            if (i == 0)
                wyn = min(wyn, abs(*it - k));
            else
                wyn = min(wyn, abs((*it - sumy_prefiksowe[i-1]) - k));
        }
    }

    cout << wyn << '\n';

    return 0;
}
