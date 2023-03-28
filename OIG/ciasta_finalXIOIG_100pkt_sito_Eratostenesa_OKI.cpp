#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, wyn = 1, ile = 0, mod = 1e9+33, iloczyn = 0;
vector<bool> sito;

int main()
{
    // O(N lg N), sito Eratostenesa
    // Tresc zadania i sprawdzarka: https://szkopul.edu.pl/problemset/problem/ciasta/site/?key=statement
    // Omowienie OKI: https://www.youtube.com/watch?v=Rz17jmhgoMM&t=6102s
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    sito.assign(n+1,false);
    for (int i = 2; i <= n; ++i)
    {
        if (sito[i] == false)
        {
            ile = 1, iloczyn = i;
            while(true)
            {
                if ((ll)iloczyn * (ll)i > (ll)n)
                    break;
                iloczyn *= i;
                ile++;
            }
            wyn = ((ll)wyn * (ll)ile) % (ll)mod;
            if (i <= 1e3)
                for (int j = i * i; j <= n; j += i)
                    sito[j] = true;
        }
    }

    cout << wyn << '\n';

    return 0;
}