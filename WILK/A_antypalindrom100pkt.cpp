#include <iostream>

using namespace std;

int n = 0, m = 0;
string wczytany_ciag;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_ciag;
        m = wczytany_ciag.size();
        if (m == 1)
        {
            cout << wczytany_ciag << ' ';
            continue;
        }
        if (wczytany_ciag[0] == wczytany_ciag[m-1])
        {
            if (wczytany_ciag[0] == '1')
                wczytany_ciag[m-1] = '0';
            else
                wczytany_ciag[0] = '1';
        }
        for (int j = 1; j < m / 2; ++j)
        {
            if (wczytany_ciag[j] == wczytany_ciag[m-1-j])
            {
                if (wczytany_ciag[j] == '0')
                    wczytany_ciag[m-1-j] = '1';
                else
                    wczytany_ciag[j] = '0';
            }
        }
        cout << wczytany_ciag << ' ';
    }

    return 0;
}