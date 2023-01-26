#include <iostream>
#include <vector>

using namespace std;

int z = 0, a = 0, b = 0, SIZE = 1e7, ile_dlugosc = 1, kiedy_przeskok = 10;
vector<int> stat(1e7+1,1);
vector<int> sumy_prefiksowe(1e7+1,0);

int main()
{
    // O(N log N) - sito Eratostenesa
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i <= SIZE; ++i)
        for (int j = i; j <= SIZE; j += i)
            stat[j]++;

    for (int i = 1; i <= SIZE; ++i)
    {
        if (i == kiedy_przeskok)
        {
            kiedy_przeskok *= 10;
            ile_dlugosc++;
        }
        if (stat[i] == ile_dlugosc)
            sumy_prefiksowe[i] = sumy_prefiksowe[i-1] + 1;
        else
            sumy_prefiksowe[i] = sumy_prefiksowe[i-1];
    }

    cin >> z;
    while(z--)
    {
        cin >> a >> b;
        printf("%d\n",sumy_prefiksowe[b] - sumy_prefiksowe[a-1]);
    }

    return 0;
}
