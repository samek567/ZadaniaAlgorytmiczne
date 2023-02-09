#include <iostream>
#include <vector>

using namespace std;

int n = 0;
string ciag, wyn;
vector<vector<vector<int>>> stat;
vector<int> idxy_szukajacych; // Szukamy pierwszej wiekszej
vector<int> idxy_pierwsze;

int main()
{
    // O(N)
    // Mozna bez binary searcha, tylko zachlannie O(ILE_LITER_W_ALFABECIE * N), ale binary search powinien byc troszke szybszy.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    idxy_szukajacych.assign(n,-1);
    idxy_pierwsze.assign(n,-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> ciag;
        stat.push_back({});
        for (int j = 0; j < 26; ++j)
            stat[i].push_back({});
        for (int j = 0; j < ciag.size(); ++j)
        {
            stat[i][(int)ciag[j]-97].push_back(j);
        }
    }

    for (char i = 'z'; i >= 'a'; --i)
    {
        int maks_wystapien = 1e9;
        for (int j = 0; j < n; ++j)
        {
            if (stat[j][(int)i-97].size() == 0)
            {
                maks_wystapien = 0;
                break;
            }
            int poczatek = -1, koniec = stat[j][(int)i-97].size(), srodek = 0;
            if (stat[j][(int)i-97][koniec-1] <= idxy_szukajacych[j])
            {
                maks_wystapien = 0;
                break;
            }
            while(koniec - poczatek > 1)
            {
                srodek = (poczatek + koniec) / 2;
                if (stat[j][(int)i-97][srodek] > idxy_szukajacych[j])
                    koniec = srodek;
                else
                    poczatek = srodek;
            }
            idxy_pierwsze[j] = koniec;
            maks_wystapien = min(maks_wystapien, ((int)stat[j][(int)i-97].size() - 1) - koniec + 1);
        }
        if (maks_wystapien != 0)
        {
            for (int j = 0; j < maks_wystapien; ++j)
                wyn.push_back(i);
            for (int j = 0; j < n; ++j)
                idxy_szukajacych[j] = stat[j][(int)i-97][idxy_pierwsze[j] + maks_wystapien - 1];
        }
    }
    cout << max(wyn,(string)"bitek") <<  '\n';
    return 0;
}