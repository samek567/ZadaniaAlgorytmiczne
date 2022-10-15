#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    int liczba_powtorzen;
    int idx_ostatniej;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int k = 0;
    int wynik = 0;
    int max_wynik = 0;
    int s = 1;

    cin >> n >> k;
    vector<Element> stat;
    int gwozdzie[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> gwozdzie[i];
    }
    sort(gwozdzie,gwozdzie+n);

    for (int i = 0; i < n-1; ++i)
    {
        if (gwozdzie[i] != gwozdzie[i+1])
        {
            stat.push_back({s,i});
            s = 1;
        }
        else
        {
            s++;
        }
    }
    stat.push_back({s,n-1});
/*
    for (auto i : stat)
    {
        cout << i.liczba_powtorzen << " " << i.idx_ostatniej << endl;
    }
    */

    for (int i = 0; i < stat.size(); ++i)
    {
        stat[i].idx_ostatniej + k > n-1 ? wynik = stat[i].liczba_powtorzen + n-1 - stat[i].idx_ostatniej : wynik = stat[i].liczba_powtorzen + k;
        max_wynik = max(max_wynik,wynik);
    }

    cout << max_wynik;
    return 0;
}