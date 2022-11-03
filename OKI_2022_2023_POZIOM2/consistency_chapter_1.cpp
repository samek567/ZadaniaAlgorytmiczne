#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long t = 0, ile_samoglosek = 0, ile_wspolglosek = 0, ile_wszystkich = 0, wynik = 10e10;
string ciag;

int main()
{
    // Zadanie opiera sie na prostych statystykach.
    // O(n * log 26)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    for (int z = 0; z < t; ++z)
    {
        map<char,int> wystapienia;
        ile_wszystkich = 0;
        ile_samoglosek = 0;
        ile_wspolglosek = 0;
        wynik = 10e10;

        for (char i = 'A'; i <= 'Z'; ++i)
        {
            wystapienia.insert({i,0});
        }

        cin >> ciag;

        for (int i = 0; i < ciag.size(); ++i)
        {
            wystapienia[ciag[i]]++;
        }

        for (char i = 'A'; i <= 'Z'; ++i)
        {
            ile_wszystkich += wystapienia[i];
        }
        ile_samoglosek = wystapienia['A'] + wystapienia['E'] + wystapienia['I'] + wystapienia['O'] + wystapienia['U'];
        ile_wspolglosek = ile_wszystkich - ile_samoglosek;

        for (char i = 'A'; i <= 'Z'; ++i)
        {
            long long wyn = 0;

            if (i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
            {
                wyn = ile_wspolglosek + (ile_samoglosek - wystapienia[i]) * 2;
            }
            else
            {
                wyn = ile_samoglosek + (ile_wspolglosek - wystapienia[i]) * 2;
            }

            wynik = min(wynik,wyn);
        }
        cout << "Case #" << z+1 << ": " << wynik << "\n";
    }
    return 0;
}
