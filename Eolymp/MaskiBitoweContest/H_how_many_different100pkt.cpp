#include <iostream>
#include <vector>

using namespace std;

int n = 0, dod = 3e7, sum = 0, wyn = 0;
vector<int> liczby;
vector<bool> stat(2*dod,false);

int main()
{
    // O(2^N * N + 6*10^7) Zaimplementuj maski bitowe.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    liczby.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];

    for (int i = 1; i < (1 << n); ++i)
    {
        sum = 0;
        for (int j = 0; j < n; ++j)
        {
            auto b = (1 << j) & i;
            if (b)
                sum += liczby[j];
        }
        if (stat[sum + dod] == false)
            wyn++;
        stat[sum + dod] = true;
    }

    cout << wyn << '\n';

    return 0;
}