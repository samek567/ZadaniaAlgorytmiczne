#include <iostream>
#include <vector>

using namespace std;

int n = 0, q = 0, wczytana_liczba = 0, a_i = 0, b_i = 0;
vector<int> sumy_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    sumy_prefiksowe.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        sumy_prefiksowe.push_back(sumy_prefiksowe[i] + wczytana_liczba);
    }
    for (int i = 0; i < q; ++i)
    {
        cin >> a_i >> b_i;
        printf("%d\n",sumy_prefiksowe[b_i] - sumy_prefiksowe[a_i-1]);
    }
    return 0;
}