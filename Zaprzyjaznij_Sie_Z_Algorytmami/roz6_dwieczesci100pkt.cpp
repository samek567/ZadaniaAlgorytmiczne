#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int n = 0, wczytana_liczba = 0, wyn = 0, max_wystapienia = 0, max_val = 0;
vector<int> liczby;
vector<int> lider_prefix;
vector<int> lider_sufix;
unordered_map<int,int> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    lider_prefix.assign(n,-1);
    lider_sufix.assign(n,-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    max_wystapienia = 0;
    max_val = 0;
    for (int i = 0; i < n; ++i)
    {
        if (auto it = stat.find(liczby[i]) != stat.end())
            stat[liczby[i]]++;
        else
            stat.insert({liczby[i],1});
        if (stat[liczby[i]] > max_wystapienia)
        {
            max_wystapienia = stat[liczby[i]];
            max_val = liczby[i];
        }
        if (max_wystapienia > (i+1) / 2)
            lider_prefix[i] = max_val;
    }

    max_wystapienia = 0;
    max_val = 0;
    stat.clear();
    for (int i = n-1; i >= 0; --i)
    {
        if (auto it = stat.find(liczby[i]) != stat.end())
            stat[liczby[i]]++;
        else
            stat.insert({liczby[i],1});
        if (stat[liczby[i]] > max_wystapienia)
        {
            max_wystapienia = stat[liczby[i]];
            max_val = liczby[i];
        }
        if (max_wystapienia > (n-i) / 2)
            lider_sufix[i] = max_val;
    }

    for (int i = 0; i < n-1; ++i)
        if (lider_prefix[i] == lider_sufix[i+1] && lider_prefix[i] != -1)
            wyn++;

    printf("%d",wyn);

    return 0;
}
