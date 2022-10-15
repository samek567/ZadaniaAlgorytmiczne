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
    int k = 0;
    int wczytana_liczba = 0;
    int wynik = 0;
    vector<int> wystapienia;

    cin >> n >> k;
    int statystyki[7] {0};

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        statystyki[wczytana_liczba]++;
    }
    for (int i = 1; i <= 6; ++i)
    {
        if (statystyki[i] != 0)
        {
            wystapienia.push_back(statystyki[i]);
        }
    }

    if (wystapienia.size() == k)
    {
        cout << "0";
        return 0;
    }
    else if (wystapienia.size() < k)
    {
        cout << k-wystapienia.size();
    }
    else
    {
        sort(wystapienia.begin(),wystapienia.end());
        for (int i = 0; i < wystapienia.size()-k; ++i)
        {
            wynik += wystapienia[i];
        }
        cout << wynik;
    }

    return 0;
}