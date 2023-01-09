#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, wczytana_liczba = 0, size_SITO = 1e6, max_wyn = 0, wyn_idx1 = 0, wyn_idx2 = 0, idx1 = 0, idx2 = 0;
vector<int> sito;

int main()
{
    // Sito Eratostenesa O(max(a_i) * log(max(a_i)))
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    sito.assign(size_SITO+1,-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (sito[wczytana_liczba] != -1)
        {
            if (wczytana_liczba > max_wyn)
            {
                max_wyn = wczytana_liczba;
                wyn_idx1 = sito[wczytana_liczba];
                wyn_idx2 = i+1;
            }
        }
        else
            sito[wczytana_liczba] = i+1;
    }

    for (int i = size_SITO; i >= 1; --i)
    {
        idx1 = -1, idx2 = -1;
        for (int j = i; j <= size_SITO; j+=i)
        {
            if (sito[j] != -1)
            {
                if (idx1 == -1)
                    idx1 = sito[j];
                else if (idx2 == -1)
                {
                    if (sito[j] < idx1)
                    {
                        idx2 = idx1;
                        idx1 = sito[j];
                    }
                    else
                        idx2 = sito[j];
                }
                else
                {
                    if (sito[j] > idx2)
                        idx2 = idx2; // Olewamy
                    else if (sito[j] < idx1)
                    {
                        idx2 = idx1;
                        idx1 = sito[j];
                    }
                    else
                    {
                        idx2 = sito[j];
                    }
                }
            }
        }
        if (idx2 != -1)
        {
            if (max_wyn > i)
                printf("%d\n%d %d",max_wyn,wyn_idx1,wyn_idx2);
            else
                printf("%d\n%d %d",i,idx1,idx2);
            return 0;
        }
    }

    return 0;
}