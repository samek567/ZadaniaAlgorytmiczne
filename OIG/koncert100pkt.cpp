#include <iostream>

using namespace std;

int n = 0;
string ciag;

int main()
{
    // O(n)
    // Korzystamy z operacji, ze zawsze oplaca nam sie zamienic jak najwczesniej, jesli to poprawi wynik.
    // Inne rozwiazanie w O(n^2) to robimy kazde mozliwe usuniecie i sortujemy po najlepszych.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;
    for (int i = 0; i < n-1; ++i)
    {
        if (ciag[i] > ciag[i+1])
        {
            for (int j = 0; j < n; ++j)
                if (j != i)
                    printf("%c",ciag[j]);
            return 0;
        }
    }

    for (int i = 0; i < n-1; ++i)
        printf("%c",ciag[i]);

    return 0;
}
