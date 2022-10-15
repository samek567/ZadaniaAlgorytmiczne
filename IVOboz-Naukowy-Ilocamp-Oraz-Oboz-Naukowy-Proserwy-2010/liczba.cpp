#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    vector<int> dzielniki;

    cin >> n;

    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            dzielniki.push_back(i);
            if (i != n / i)
            {
                dzielniki.push_back(n / i);
            }
        }
    }
    sort(dzielniki.begin(),dzielniki.end());

    int wskaznik = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (i == dzielniki[wskaznik])
        {
            wskaznik++;
        }
        else
        {
            cout << i << " ";
            break;
        }
    }

    wskaznik = dzielniki.size()-1;

    for (int i = n; i >= 1; --i)
    {
        if (i == dzielniki[wskaznik])
        {
            wskaznik--;
        }
        else
        {
            cout << i << " ";
            break;
        }
    }
    return 0;
}