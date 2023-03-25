#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, wyn = 1e9+20;
vector<int> dziury;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    dziury.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> dziury[i];
    sort(dziury.begin(), dziury.end());

    if (n == 0 or n == 1)
    {
        cout << "0" << '\n';
        return 0;
    }

    for (int i = 0; i < n-1; ++i)
        wyn = min(wyn, (dziury[i] - dziury[0]) + (dziury[n-1] - dziury[i+1]));

    cout << wyn << '\n';

    return 0;
}
