#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int n = 0, przesuniecie = 65, k = 0, suma = 0, minn = 0, mod = 1e9+7, wyn = 0;
string ciag;
vector<int> stat_vect[200];
vector<bool> stat_czy_jest(200,false);
vector<int> spr_vect;
map<vector<int>,int> S;
vector<int> vect;

int main()
{
    // O(N*K*lg(N)), da sie w O(N*K + N*lg(N)) usuwajac vectora mapy, dajac hashe zamist vectora(patrz na moj komentarz pod omowieniem OKI)
    // https://www.youtube.com/watch?v=qJwaW1CFNCA&t=3051s link dodany dnia 16.03.2023
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;

    for (int i = 0; i < n; ++i)
        stat_czy_jest[(int)ciag[i]-przesuniecie] = true;
    for (int i = 0; i < 200; ++i)
        if (stat_czy_jest[i] == true)
            spr_vect.push_back(i);

    k = spr_vect.size();
    vect.assign(k,-1);
    for (int i = 0; i < spr_vect.size(); ++i)
    {
        suma = 0;
        for (int j = 0; j < n; ++j)
        {
            if ((int)ciag[j] - przesuniecie == spr_vect[i])
                suma++;
            stat_vect[spr_vect[i]].push_back(suma);
        }
    }

    for (int i = n-1; i >= 0; --i)
    {
        minn = 1e9;
        for (int j = 0; j < k; ++j)
            minn = min(minn, stat_vect[spr_vect[j]][i]);
        for (int j = 0; j < k; ++j)
            vect[j] = stat_vect[spr_vect[j]][i] - minn;
        auto it = S.find(vect);
        if (it == S.end())
            S.insert({vect,1});
        else
            S[vect]++;

        minn = 1e9;
        if (i == 0)
        {
            for (int j = 0; j < k; ++j)
                vect[j] = 0;
        }
        else
        {
            for (int j = 0; j < k; ++j)
                minn = min(minn, stat_vect[spr_vect[j]][i-1]);
            for (int j = 0; j < k; ++j)
                vect[j] = stat_vect[spr_vect[j]][i-1] - minn;
        }
        it = S.find(vect);
        if (it != S.end())
            wyn = ((ll)wyn + (ll)S[vect]) % (ll)mod;
    }

    cout << wyn << '\n';

    return 0;
}