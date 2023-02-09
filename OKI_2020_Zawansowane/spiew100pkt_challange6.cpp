#include <iostream>

using namespace std;

int n = 0, wyn = 0, ile_powtorzen = 0;
string ciag;

inline void przetwarzaj()
{
    if (ile_powtorzen != 0)
    {
        wyn += ile_powtorzen / 3;
        if (ile_powtorzen % 3 != 0)
            wyn++;
        ile_powtorzen = 0;
    }
}

int main()
{
    // O(N)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;
    for (int i = 0; i < n; ++i)
    {
        if (ciag[i] == 'Z')
            ile_powtorzen++;
        else
            przetwarzaj();
    }
    przetwarzaj();
    cout << wyn << '\n';

    return 0;
}