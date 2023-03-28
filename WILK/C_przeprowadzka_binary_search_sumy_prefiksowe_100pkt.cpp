#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, q = 0, wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0;
ll sum = 0;
vector<int> stat(1e6+1,0);
vector<ll> sumy_prefiksowe;

int main()
{
    // O(N+Q*lg(N)), sumy prefiksowe z binary searchem, zadanie troche podobne do zadan:
    // - Klapki na obcasach OIJ
    // - Praktycznie kopia zadania Prog Kwalifikacyjny z OIJ
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        stat[wczytana_liczba]++;
    }
    for (int i = 1; i <= 1e6; ++i)
    {
        for (int j = 0; j < stat[i]; ++j)
        {
            sum += i;
            sumy_prefiksowe.push_back(sum);
        }
    }
    while(q--)
    {
        cin >> wczytana_liczba;
        poczatek = -1, koniec = n;
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (sumy_prefiksowe[srodek] <= wczytana_liczba)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        cout << poczatek + 1 << '\n';
    }
    return 0;
}