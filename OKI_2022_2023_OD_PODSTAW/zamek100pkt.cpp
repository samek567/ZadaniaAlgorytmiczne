#include <iostream>
#include <vector>

using namespace std;

int n = 0, q = 0, a = 0, b = 0;
long long sum = 0, wczytana_liczba = 0;
vector<long long> sumy_prefiksowe;

int main()
{
    // O(n+q) Sumy prefiksowe.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    sumy_prefiksowe.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        sum += wczytana_liczba;
        sumy_prefiksowe.push_back(sum);
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> a >> b;
        if ((sumy_prefiksowe[n] - sumy_prefiksowe[b-1]) * 2 <= sumy_prefiksowe[n] - sumy_prefiksowe[a-1]) // Trasa bajtka <= trasa potwora * 2.
            printf("TAK\n");
        else
            printf("NIE\n");
    }
    return 0;
}