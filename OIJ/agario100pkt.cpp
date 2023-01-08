#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n = 0, wsk_sprawdzane = 0, wyn = 0;
long long masa_bajtka = 2, wczytana_liczba = 0;
vector<long long> masy;
multiset<long long> do_zjedzenia;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        masy.push_back(wczytana_liczba);
    }
    sort(masy.begin(),masy.end());

    if (masa_bajtka >= masy[n-1])
    {
        printf("0");
        return 0;
    }

    while (true)
    {
        for (int i = wsk_sprawdzane; i < n; ++i)
        {
            if (masa_bajtka > masy[i])
            {
                wsk_sprawdzane++;
                do_zjedzenia.insert(masy[i]);
            }
            else
                break;
        }
        if (do_zjedzenia.empty())
            break;
        masa_bajtka += *do_zjedzenia.rbegin();
        wyn++;
        if (masa_bajtka >= masy[n-1])
            break;
        do_zjedzenia.erase(do_zjedzenia.lower_bound(*do_zjedzenia.rbegin()));
    }

    if (masa_bajtka >= masy[n-1])
        printf("%d",wyn);
    else
        printf("NIE");

    return 0;
}