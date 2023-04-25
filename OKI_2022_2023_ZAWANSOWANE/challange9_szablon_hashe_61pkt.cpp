#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, p = 43, mod = 1e9+7, hash_prefix = 0, hash_sufix = 0, hash_spr = 0, do_kod_mamy = 0;
string tekst;
vector<int> prefikso_sufixy;
vector<int> POW;
vector<int> hashe_prefixowe;

inline bool czy_pasuje(int &x)
{
    do_kod_mamy = x-1;
    hash_prefix = hashe_prefixowe[x-1];
    for (int i = 1; i <= n-x; ++i)
    {
        if (i > do_kod_mamy + 1)
            return false;
        if (i == 0)
            hash_spr = hashe_prefixowe[i+x-1];
        else
            hash_spr = ((ll)hashe_prefixowe[i+x-1] - (ll)hashe_prefixowe[i-1] + (ll)mod) % (ll)mod;
        if (((ll)hash_prefix * (ll)POW[i] + (ll)mod) % (ll)mod == hash_spr)
            do_kod_mamy = i + x - 1;
    }
    if (do_kod_mamy >= n-1)
        return true;
    return false;
}

int main()
{
    // Zeby dobic do 100pkt, pewnie trzeba KMP zaimplementowac. O(N lg N), zauwazamy, ze szablon musi byc prefixo-sufixem,
    // spostrzrzenie, ze prefixo-sufix mojego prefixo-sufixu jest moim prefixo-sufixem, dzieki czemu ograniczamy kandydatów do lg N.
    // Jesli mamy posortowane od najmniejszych dlugosci prefixo sufixow, to jesli nie da sie ulozyc z prefixo-sufixu o dlugosci X,
    // to nie da sie tez z dlugosci[X,2*X], bo one w calosci pokryja ten przedzial. wiec sprawdzamy tylko dwa razy wieksze, a ich bedzie co najwyzej logarytm.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tekst;
    n = tekst.size();

    POW.push_back(1);
    for (int i = 1; i < n; ++i)
        POW.push_back(((ll)POW[i-1] * (ll)p) % (ll)mod);

    hashe_prefixowe.push_back((int)tekst[0]);
    for (int i = 1; i < n; ++i)
        hashe_prefixowe.push_back(((ll)hashe_prefixowe[i-1] + (ll)tekst[i] * (ll)POW[i]) % (ll)mod);

    for (int i = 0; i < n; ++i)
    {
        hash_prefix = hashe_prefixowe[i];
        if (i == n-1)
            hash_sufix = hashe_prefixowe[n-1];
        else
            hash_sufix = ((ll)hashe_prefixowe[n-1] - (ll)hashe_prefixowe[n-2-i] + (ll)mod) % (ll)mod;
        hash_prefix = ((ll)hash_prefix * (ll)POW[n-1-i] + (ll)mod) % (ll)mod;
        if (hash_prefix == hash_sufix)
            prefikso_sufixy.push_back(i+1);
    }

    for (int i = 0; i < prefikso_sufixy.size(); ++i)
    {
        if (i == 0 or prefikso_sufixy[i] > prefikso_sufixy[i-1] * 2)
        {
            if (czy_pasuje(prefikso_sufixy[i]) == true)
            {
                cout << prefikso_sufixy[i] << '\n';
                return 0;
            }
        }
    }

    return 0;
}