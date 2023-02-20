#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, wczytana_liczba = 0, wyn = 0;
int stat[7] = {0};
vector<int> powtorzenia;

int main()
{
    // O(N)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        stat[wczytana_liczba]++;
    }

    for (int i = 0; i < 6; ++i)
    {
        int minn = 1e9;
        for (int j = 1; j <= 6; ++j)
            minn = min(minn,stat[j]);
        for (int j = 1; j <= 6; ++j)
        {
            if (stat[j] == minn)
            {
                stat[j] = 1e9;
                break;
            }
        }
        if (minn != 0 && minn != 1e9)
            powtorzenia.push_back(minn);
    }

    if (powtorzenia.size() <= k)
        cout << k - powtorzenia.size();
    else
    {
        for (int i = 0; i < powtorzenia.size() - k; ++i)
            wyn += powtorzenia[i];
        cout << wyn << '\n';
    }

    return 0;
}