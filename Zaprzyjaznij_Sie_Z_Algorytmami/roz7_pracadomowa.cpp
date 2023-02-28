#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, wczytana_liczba = 0;
vector<int> liczby;
vector<ll> dp_prefix;
vector<ll> dp_sufix;
ll wyn = 0;

int main()
{
    // O(N), programowanie dynamiczne. Szukamy od lewej i prawej spojnego podciagu o maksymalnej sumie dynamicznie. W odtwarzaniu,
    // dla kazdego punktu zakladamy, ze jest on srodkowym i bierzemy max wynik.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    dp_prefix.assign(n,0);
    dp_sufix.assign(n,0);

    for (int i = 1; i < n; ++i)
        dp_prefix[i] = max((ll)liczby[i], max(liczby[i] + dp_prefix[i-1], (ll)0));

    for (int i = n-2; i >= 0; --i)
        dp_sufix[i] = max((ll)liczby[i], max(liczby[i] + dp_sufix[i+1], (ll)0));

    for (int i = 1; i < n-1; ++i)
        wyn = max(wyn, dp_prefix[i-1] + dp_sufix[i+1]);

    cout << wyn << '\n';

    return 0;
}