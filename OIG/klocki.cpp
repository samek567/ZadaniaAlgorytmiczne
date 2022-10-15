#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int k = 0;
    int m = 0;
    int wczytany_klocek = 0;
    vector<int> klocki;

    cin >> n >> k >> m;

    int statystyki[m+1];
    for(int i = 0; i <= m; ++i)
    {
        statystyki[i] = -1;
    }
    statystyki[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_klocek;
        if (wczytany_klocek > m)
        {
            continue;
        }
        klocki.push_back(wczytany_klocek);
    }

    for (int i = 0; i < klocki.size(); ++i)
    {
        for (int j = m-klocki[i]; j >= 0; --j)
        {
            if (statystyki[j] != -1)
            {
                if (statystyki[j+klocki[i]] == -1)
                {
                    statystyki[j+klocki[i]] = statystyki[j]+1;
                    continue;
                }
                if (statystyki[j+klocki[i]] > statystyki[j])
                {
                    statystyki[j+klocki[i]] = statystyki[j]+1;
                }
            }
        }
    }


    for (int i = m; i >= 0; --i)
    {
        if (statystyki[i] <= k && statystyki[i] > 0)
        {
            cout << i;
            return 0;
        }
    }

    cout << "0";
    return 0;
}