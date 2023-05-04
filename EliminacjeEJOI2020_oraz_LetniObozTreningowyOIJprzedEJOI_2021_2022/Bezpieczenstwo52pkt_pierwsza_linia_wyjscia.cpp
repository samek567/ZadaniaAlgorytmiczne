#include <iostream>
#include <vector>

using namespace std;

int n = 0, a = 0, b = 0;
vector<int> ile_wchodzi;
vector<int> jakie_maja_stopien_jeden;

int main()
{
    // O(N), zawsze wynik to (liczba_lisci + 1) / 2, bo każde dwa laczymy w pary
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n == 1)
    {
        cout << "0" << '\n';
        return 0;
    }
    ile_wchodzi.assign(n+1,0);
    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        ile_wchodzi[a]++;
        ile_wchodzi[b]++;
    }

    for (int i = 1; i <= n; ++i)
        if (ile_wchodzi[i] == 1)
            jakie_maja_stopien_jeden.push_back(i);

    cout << (jakie_maja_stopien_jeden.size() + 1) / 2 << '\n';

    return 0;
}