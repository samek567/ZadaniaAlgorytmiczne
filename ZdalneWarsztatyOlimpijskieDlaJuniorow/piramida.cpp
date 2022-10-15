#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n = 0;
    unsigned long long k = 0;
    char wczytany_znak;
    vector<bool> czy_pulapka;

    cin >> n >> k;

    unsigned long long kombinacje[n] {0};
    kombinacje[0] = 1;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == '1')
        {
            czy_pulapka.push_back(false);
        }
        else
        {
            czy_pulapka.push_back(true);
        }
    }

    for (int i = 1; i < n; ++i)
    {
        if (czy_pulapka[i] == true)
        {
            continue;
        }
        for (int j = 1; j <= 6; ++j)
        {
            if (i-j < 0)
            {
                break;
            }
            kombinacje[i] = (kombinacje[i] + kombinacje[i-j]) % k;
        }
    }

    cout << (kombinacje[n-1] % k);
    return 0;
}