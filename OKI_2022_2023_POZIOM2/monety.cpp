#include <iostream>
#include <map>

using namespace std;

struct Element
{
    long long l;
    long long p;
};

long long n = 0, k = 0, s = 0, wynik = 0;
char wczytany_znak;
map<long long, Element> statystyki;

int main()
{
    // Zadanie Monety z potyczek algorytmicznych. Pomysl opiera sie na zauwazeniu, ze pasujacy przedzial jest taki, gdzie sumy prefiksowe w poczatku i koncu sa rowne x
    // Wtedy pasujacy przedzial to p+1,k.
    // O(n log n) ze wzgledu na mapa.
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    statystyki.insert({0,{0,0}});
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'O')
        {
            s += 1;
        }
        else
        {
            s -= k;
        }
        if (auto it = statystyki.find(s) != statystyki.end()) // Znalezlismy
        {
            statystyki[s].p = i;
        }
        else
        {
            statystyki.insert({s,{i,i}});
        }
    }

    for (auto i : statystyki)
    {
        wynik = max(wynik,i.second.p - i.second.l);
    }

    cout << wynik << "\n";

    return 0;
}
