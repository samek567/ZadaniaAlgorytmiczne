#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int q = 0, a = 0, b = 0, sum = 0, wyn = 0;
bool czy_polpierwsza[1000010] = {false};
int sumy_prefiksowe[1000001] = {0};
vector<int> ile_dzielnikow(1e6+1,0);
bool sito[1000001] = {false};
vector<int> sumy_prefiksowe_jeden(1e6+1,0); // czy jest w przedziale [A,B] jedna pod rzad liczba polpierwsza
vector<int> sumy_prefiksowe_dwa(1e6+1,0); // czy sa w przedziale [A,B] dwie pod rzad liczby polpierwsze
vector<int> sumy_prefiksowe_trzy(1e6+1,0); // czy sa w przedziale [A,B] trzy pod rzad liczby polpierwsze

int main()
{
    // Sito Eratostenesa i sumy prefiksowe
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i <= 1e6; ++i)
    {
        if (sito[i] == false)
        {
            for (int j = i; j <= 1e6; j += i)
            {
                sito[j] = true;
                int val = j;
                while(val > 1 and val % i == 0)
                {
                    ile_dzielnikow[j]++;
                    val /= i;
                }
            }
        }
    }

    for (int i = 2; i <= 1e6; ++i)
        if (ile_dzielnikow[i] == 2)
            czy_polpierwsza[i] = true;

    for (int i = 1; i <= 1e6; ++i)
    {
        if (czy_polpierwsza[i] == true)
            sum++;
        sumy_prefiksowe_jeden[i] = sum;
    }

    sum = 0;
    for (int i = 2; i <= 1e6; ++i)
    {
        if (czy_polpierwsza[i] == true and czy_polpierwsza[i-1] == true)
            sum++;
        sumy_prefiksowe_dwa[i] = sum;
    }

    sum = 0;
    for (int i = 3; i <= 1e6; ++i)
    {
        if (czy_polpierwsza[i] == true and czy_polpierwsza[i-1] == true and czy_polpierwsza[i-2] == true)
            sum++;
        sumy_prefiksowe_trzy[i] = sum;
    }

    cin >> q;
    while(q--)
    {
        cin >> a >> b;
        wyn = 0;
        if (b - a >= 2 and sumy_prefiksowe_trzy[b] - sumy_prefiksowe_trzy[a+1] >= 1)
            wyn = 3;
        else if (b - a >= 1 and sumy_prefiksowe_dwa[b] - sumy_prefiksowe_dwa[a] >= 1)
            wyn = 2;
        else if (sumy_prefiksowe_jeden[b] - sumy_prefiksowe_jeden[a-1] >= 1)
            wyn = 1;
        cout << wyn << '\n';
    }

    return 0;
}