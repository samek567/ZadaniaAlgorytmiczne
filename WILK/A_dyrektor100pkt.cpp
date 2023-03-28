#include <iostream>
#include <vector>

using namespace std;

int n = 0, idx_najmniejszej = 0, idx_najwiekszej = 0, min_val = 1e9, max_val = -1e9, wyn = 0;
vector<int> liczby;

int main()
{
    // O(N), symulacja
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    liczby.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];

    for (int i = 0; i < n; ++i)
    {
        min_val = min(min_val, liczby[i]);
        max_val = max(max_val, liczby[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        if (liczby[i] == max_val)
        {
            idx_najwiekszej = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; --i)
    {
        if (liczby[i] == min_val)
        {
            idx_najmniejszej = i;
            break;
        }
    }

    wyn = n - idx_najmniejszej - 1 + idx_najwiekszej;
    if (idx_najmniejszej < idx_najwiekszej)
        wyn--;

    cout << wyn << '\n';

    return 0;
}
