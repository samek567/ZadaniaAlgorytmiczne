#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, s = 0, wynik = 0;
vector<int> rzuty;
char wczytany_znak;

int main()
{
    // Zadanie z potyczek algorytmicznych. Podejscie silowe.
    // O(n^2)
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'O')
        {
            rzuty.push_back(1);
        }
        else
        {
            rzuty.push_back(-k);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        s = 0;
        for (int j = i; j < n; ++j)
        {
            s += rzuty[j];
            if (s == 0)
            {
                wynik = max(wynik,j - i + 1);
            }
        }
    }

    cout << wynik << "\n";

    return 0;
}