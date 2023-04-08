#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n = 0, m = 0, b = 0, wczytana_liczba = 0, wyn = 0, cnt = 0;
char znak;
ll a = 0, maxx = 0;
vector<ll> liczby;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    liczby.assign(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby[i] = wczytana_liczba;
    }

    while(m--)
    {
        cin >> znak;
        if (znak == 'Z')
        {
            sort(liczby.begin(),liczby.end());
            maxx = -1e18, wyn = 0, cnt = 1;
            for (int i = n-1; i >= 0; --i)
            {
                if (liczby[i] + n >= maxx)
                    wyn++;
                maxx = max(maxx, liczby[i] + cnt);
                cnt++;
            }
            cout << wyn << '\n';
        }
        else if (znak == 'B')
        {
            cin >> a >> b;
            for (int i = 0; i < n; ++i)
                if (liczby[i] >= a)
                    liczby[i] += b;
        }
        else if (znak == 'K')
        {
            cin >> a >> b;
            for (int i = 0; i < n; ++i)
                if (liczby[i] <= a)
                    liczby[i] -= b;
        }
    }
    return 0;
}