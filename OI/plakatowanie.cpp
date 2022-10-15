#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    long long wczytana_wysokosc = 0;
    long long wczytana_dlugosc = 0;
    long long licznik = 0;
    stack<long long> segmenty;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_dlugosc >> wczytana_wysokosc;
        while (true)
        {
            if (segmenty.empty())
            {
                segmenty.push(wczytana_wysokosc);
                continue;
            }
            if (wczytana_wysokosc == segmenty.top())
            {
                break;
            }
            else if (wczytana_wysokosc > segmenty.top())
            {
                segmenty.push(wczytana_wysokosc);
                break;
            }
            else
            {
                licznik++;
                segmenty.pop();
            }
        }
    }

    cout << licznik + segmenty.size();
    return 0;
}