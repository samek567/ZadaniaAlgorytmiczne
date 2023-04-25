#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
vector<int> ile;
vector<vector<int>> wystapienia;

int main()
{
    // Zachlan.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    ile.assign(n,0);
    for (int i = 0; i < n; ++i)
        cin >> ile[i];

    wystapienia.assign(n+1,{});

    for (int i = 0; i < n; ++i)
    {
        int max_val = -1, max_idx = -1;
        for (int j = 0; j < n; ++j)
        {
            if (ile[j] > max_val)
            {
                max_val = ile[j], max_idx = j;
            }
        }
        if (max_val == 0)
            break;
        for (int j = 1; j <= n; ++j)
            wystapienia[j].clear();
        for (int j = 0; j < n; ++j)
            if (j != max_idx)
                wystapienia[ile[j]].push_back(j);
        for (int j = n; j > 0 and ile[max_idx] > 0; --j)
        {
            for (int k = 0; k < wystapienia[j].size() and ile[max_idx] > 0; ++k)
            {
                cout << max_idx + 1 << ' ' << wystapienia[j][k] + 1 << '\n';
                ile[wystapienia[j][k]]--;
                ile[max_idx]--;
            }
        }
    }

    return 0;
}