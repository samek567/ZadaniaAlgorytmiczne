#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, p = 43, mod = 1e9+7, hash_wzorzec = 0, hash_tekst = 0, ile_przemnozyc = 0, POW = 1, POW_przod = 1, POW_tyl = 1;
string wczytany_ciag;
vector<char> ciag1;
vector<char> ciag2;

int main()
{
    // O(N), Symulujemy kolejne przestawiania z hashami. Ominelismy szybkie potegowanie,
    // ale mozna tez probowac w O(N lg N), szybkim potegowaniem(nie wiem czy wejdzie i jest to troche na sile).
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> wczytany_ciag;
    ciag1.assign(wczytany_ciag.size(),' ');
    for (int i = 0; i < wczytany_ciag.size(); ++i)
        ciag1[i] = wczytany_ciag[i];

    cin >> wczytany_ciag;
    ciag2.assign(wczytany_ciag.size(),' ');
    for (int i = 0; i < wczytany_ciag.size(); ++i)
        ciag2[i] = wczytany_ciag[i];

    wczytany_ciag.clear();

    if (ciag1.size() != ciag2.size())
    {
        cout << "NIE" << '\n';
        return 0;
    }

    n = ciag1.size();

    for (int i = 0; i < n; ++i)
        POW_tyl = ((ll)POW_tyl * (ll)p + (ll)mod) % mod;

    hash_tekst = (ll)ciag1[0];
    for (int i = 1; i < n; ++i)
    {
        POW = ((ll)POW * (ll)p + (ll)mod) % mod;
        hash_tekst = ((ll)hash_tekst + (ll)ciag1[i] * (ll)POW + (ll)mod) % mod;
    }

    POW = 1;
    hash_wzorzec = (ll)ciag2[0];
    for (int i = 1; i < n; ++i)
    {
        POW = ((ll)POW * (ll)p + (ll)mod) % mod;
        hash_wzorzec = ((ll)hash_wzorzec + (ll)ciag2[i] * (ll)POW + (ll)mod) % mod;
    }

    if (hash_tekst == hash_wzorzec)
    {
        cout << "TAK" << '\n';
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        hash_tekst = ((ll)hash_tekst - (ll)ciag1[i] * (ll)POW_przod + (ll)mod) % (ll)mod;
        hash_tekst = ((ll)hash_tekst + (ll)ciag1[i] * (ll)POW_tyl + (ll)mod) % (ll)mod;
        POW_przod = ((ll)POW_przod * (ll)p + (ll)mod) % mod;
        POW_tyl = ((ll)POW_tyl * (ll)p + (ll)mod) % mod;
        if (hash_tekst == ((ll)POW_przod * (ll)hash_wzorzec + (ll)mod) % mod)
        {
            cout << "TAK" << '\n';
            return 0;
        }
    }

    cout << "NIE" << '\n';

    return 0;
}
