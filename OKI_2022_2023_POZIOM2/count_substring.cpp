#include <iostream>

using namespace std;

long long t = 0, n = 0, s = 0, wyn = 0;
char wczytany_znak;

int main()
{
    // Zadanie Count Substrings z platformy Code Chef. Pomysl opiera sie na sumach prefiksowych.
    // O(n)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    for (int z = 0; z < t; ++z)
    {
        cin >> n;

        s = 0;
        wyn = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> wczytany_znak;
            if (wczytany_znak == '1')
            {
                s++;
                wyn += s;
            }
        }

        cout << wyn << "\n";
    }

    return 0;
}
