#include <iostream>

using namespace std;

long long t = 0, n = 0, ile_jedynek = 0;
string ciag;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        ile_jedynek = 0;
        cin >> n >> ciag;
        for (int j = 0; j < ciag.size(); ++j)
            if (ciag[j] == '1')
                ile_jedynek++;
        printf("%lld\n",ile_jedynek * (ile_jedynek+1) / 2); // Lecimy z sumy ciagu. Mozna zastosowac ogolny wzor ((pierszy + ostatni) / 2 * n),
        // Ale dla ciagu 1,2,3...n dziala ten wzor.
    }
    return 0;
}
