#include <iostream>

using namespace std;

int n = 0, a = 0, b = 0, wyn = 0;
bool stat[1000001] = {false};

int main()
{
    // O(N) - zaimplementuj counting sorta.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        if (stat[b] == false)
        {
            wyn++;
            stat[b] = true;
        }
    }

    cout << wyn << '\n';

    return 0;
}