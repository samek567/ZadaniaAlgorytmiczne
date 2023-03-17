#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int odtw = 0, mod = 1e9+7, p = 43, hash_przod = 0, hash_tyl = 0, hash_akt = 0;
string ciag, spr;
vector<int> dp_min;
vector<int> dp_max;
vector<int> idx_poprzedniej_min;
vector<int> idx_poprzedniej_max;
vector<int> POW;
vector<int> hashe_prefiksowe;
vector<int> hashe_sufixowe;
vector<string> wyn_min;
vector<string> wyn_max;

inline bool czy_palindrom(int p, int k)
{
    if (p == 0)
        hash_przod = ((ll)hashe_prefiksowe[k] + (ll)mod) % (ll)mod;
    else
        hash_przod = ((ll)hashe_prefiksowe[k] - (ll)hashe_prefiksowe[p-1] + (ll)mod) % (ll)mod;
    if (k == ciag.size()-1)
        hash_tyl = ((ll)hashe_sufixowe[p] + (ll)mod) % (ll)mod;
    else
        hash_tyl = ((ll)hashe_sufixowe[p] - (ll)hashe_sufixowe[k+1] + (ll)mod) % (ll)mod;
    int p_poz = p, k_poz = ciag.size() - k - 1;
    int roznica = abs(p_poz - k_poz);
    if (p_poz > k_poz)
        hash_tyl = ((ll)hash_tyl * (ll)POW[roznica] + (ll)mod) % (ll)mod;
    else
        hash_przod = ((ll)hash_przod * (ll)POW[roznica] + (ll)mod) % (ll)mod;
    if (hash_przod == hash_tyl)
        return true;
    return false;
}

int main()
{
    // Programowanie dynamiczne, O(N^2). Sprawdzamy czy ciag jest palindormem w O(1), za pomca hashy.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag;

    POW.push_back(1);
    for (int i = 0; i < ciag.size()+5; ++i)
        POW.push_back(((ll)POW[i] * (ll)p) % (ll)mod);

    hashe_prefiksowe.push_back((ll)ciag[0]);
    for (int i = 1; i < ciag.size(); ++i)
        hashe_prefiksowe.push_back(((ll)hashe_prefiksowe[i-1] + (ll)ciag[i] * (ll)POW[i] + (ll)mod) % (ll)mod);

    hashe_sufixowe.assign(ciag.size(),0);
    hashe_sufixowe[ciag.size()-1] = (ll)ciag[ciag.size()-1];
    for (int i = ciag.size()-2; i >= 0; --i)
        hashe_sufixowe[i] = ((ll)hashe_sufixowe[i+1] + (ll)ciag[i] * (ll)POW[ciag.size() - i - 1] + (ll)mod) % (ll)mod;

    dp_min.assign(ciag.size()+1,-1);
    dp_max.assign(ciag.size()+1,-1);
    idx_poprzedniej_min.assign(ciag.size()+1,-1);
    idx_poprzedniej_max.assign(ciag.size()+1,-1);

    dp_min[0] = 0;
    dp_max[0] = 0;

    for (int i = 0; i < ciag.size(); ++i)
    {
        hash_akt = 0;
        for (int j = i; j < ciag.size(); ++j)
        {
            hash_akt = ((ll)hash_akt + (ll)ciag[j] * POW[j]) % mod;
            if ((j-i) % 2 == 1 and czy_palindrom(i,j) == true)
            {
                if (dp_min[j+1] == -1 or dp_min[i] + 1 < dp_min[j+1])
                {
                    dp_min[j+1] = dp_min[i] + 1;
                    idx_poprzedniej_min[j+1] = i;
                }
                if (dp_max[j+1] == -1 or dp_max[i] + 1 > dp_max[j+1])
                {
                    dp_max[j+1] = dp_max[i] + 1;
                    idx_poprzedniej_max[j+1] = i;
                }
            }
        }
    }

    if (idx_poprzedniej_min[ciag.size()] == -1)
    {
        cout << "NIE" << '\n';
        return 0;
    }

    odtw = ciag.size();
    while(true)
    {
        if (idx_poprzedniej_min[odtw] == -1)
            break;
        spr.clear();
        for (int i = idx_poprzedniej_min[odtw]; i < odtw; ++i)
            spr.push_back(ciag[i]);
        wyn_min.push_back(spr);
        odtw = idx_poprzedniej_min[odtw];
    }

    odtw = ciag.size();
    while(true)
    {
        if (idx_poprzedniej_max[odtw] == -1)
            break;
        spr.clear();
        for (int i = idx_poprzedniej_max[odtw]; i < odtw; ++i)
            spr.push_back(ciag[i]);
        wyn_max.push_back(spr);
        odtw = idx_poprzedniej_max[odtw];
    }

    for (int i = wyn_min.size()-1; i >= 0; --i)
        cout << wyn_min[i] << ' ';
    cout << '\n';
    for (int i = wyn_max.size()-1; i >= 0; --i)
        cout << wyn_max[i] << ' ';
    cout << '\n';

    return 0;
}