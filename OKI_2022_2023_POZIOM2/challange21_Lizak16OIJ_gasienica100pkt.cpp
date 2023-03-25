#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n = 0, lewy_wsk = 0, prawy_wsk = 0, ile_jedynek = 0, ile_dwojek = 0, ile_trojek = 0, wyn = 1e9;
vector<int> liczby;
unordered_map<int,int> stat;

inline void przesuwaj_lewy()
{
    if (stat[liczby[lewy_wsk]] == 1)
        ile_jedynek--;
    else if (stat[liczby[lewy_wsk]] == 2)
    {
        ile_dwojek--;
        ile_jedynek++;
    }
    else
    {
        ile_trojek--;
        ile_dwojek++;
    }
    stat[liczby[lewy_wsk]]--;
    lewy_wsk++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    liczby.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];

    ile_jedynek = 1;
    stat[liczby[0]] = 1;
    while(true)
    {
        if (ile_trojek >= 1)
            wyn = min(wyn, prawy_wsk - lewy_wsk + 1);
        if (prawy_wsk == n-1 and lewy_wsk == prawy_wsk)
            break;
        else if (prawy_wsk == n-1)
            przesuwaj_lewy();
        else if (ile_trojek == 0)
        {
            if (auto it = stat.find(liczby[prawy_wsk+1]) == stat.end())
            {
                stat.insert({liczby[prawy_wsk+1],1});
                ile_jedynek++;
            }
            else if (stat[liczby[prawy_wsk+1]] == 0)
            {
                ile_jedynek++;
                stat[liczby[prawy_wsk+1]]++;
            }
            else if (stat[liczby[prawy_wsk+1]] == 1)
            {
                ile_jedynek--;
                ile_dwojek++;
                stat[liczby[prawy_wsk+1]]++;
            }
            else
            {
                ile_dwojek--;
                ile_trojek++;
                stat[liczby[prawy_wsk+1]]++;
            }
            prawy_wsk++;
        }
        else
            przesuwaj_lewy();
    }

    if (wyn == 1e9)
        cout << "NIE" << '\n';
    else
        cout << wyn << '\n';

    return 0;
}