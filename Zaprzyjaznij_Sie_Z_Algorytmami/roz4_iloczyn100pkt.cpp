#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int z = 0, n = 0, wczytana_liczba = 0;

int main()
{
    // Mozna tez counting sorta i wtedy O(z * n) zamiast O(z * n log n)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> z;
    for (int i = 0; i < z; ++i)
    {
        vector<int> liczby;
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytana_liczba;
            liczby.push_back(wczytana_liczba);
        }
        sort(liczby.begin(),liczby.end(),greater<int>());
        printf("%d \n",max(liczby[0]*liczby[1]*liczby[2],liczby[0] * liczby[n-1] * liczby[n-2]));
    }

    return 0;
}
