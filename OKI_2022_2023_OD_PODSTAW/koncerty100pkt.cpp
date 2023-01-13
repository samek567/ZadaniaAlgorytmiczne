#include <iostream>
#include <vector>

using namespace std;

int n = 0, p = 0, a = 0, b = 0, wczytana_liczba = 0;
vector<int> sumy_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    sumy_prefiksowe.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        sumy_prefiksowe.push_back(sumy_prefiksowe[i] + wczytana_liczba);
    }
    cin >> p;
    for (int i = 0; i < p; ++i)
    {
        cin >> a >> b;
        printf("%d\n",sumy_prefiksowe[b] - sumy_prefiksowe[a-1]);
    }
    return 0;
}