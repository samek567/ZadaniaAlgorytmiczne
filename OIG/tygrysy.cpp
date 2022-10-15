#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Tygrys
{
    long long k;
    long long r;
    bool czy_sprawdzone;

    bool operator < (const Tygrys& tygrys)
    {
        return r < tygrys.r;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    long long k_i = 0;
    long long rozmiar_i = 0;
    long long licznik = 0;
    long long rozmiar_grupy = 0;
    long long g_j = 0;
    vector<Tygrys> tygrysy;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> rozmiar_i >> k_i;
        tygrysy.push_back({k_i,rozmiar_i,false});
    }

    sort(tygrysy.begin(),tygrysy.end());

    /*
    for (auto i : tygrysy)
    {
        cout << i.r << endl;
    }
    */

    for (int i = 0; i < n; ++i)
    {
        if (tygrysy[i].czy_sprawdzone == true)
        {
            continue;
        }
        tygrysy[i].czy_sprawdzone = true;
        licznik++;
        for (int j = i+1; j < n; ++j)
        {
            g_j = tygrysy[j].r / tygrysy[j].k;
            if (g_j < tygrysy[i].r && tygrysy[j].czy_sprawdzone == false)
            {
                tygrysy[j].czy_sprawdzone = true;
            }
        }
    }

    cout << licznik;
    return 0;
}