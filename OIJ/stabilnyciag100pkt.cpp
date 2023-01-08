#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n = 0, wczytana_liczba = 0, sito_SIZE = 10001, max_wyn = 0, idx_pop = 0, wynik = 0, idx_wyn = 0;
vector<bool> sito;
vector<int> P;
vector<int> liczby;
vector<int> dp;
vector<int> idx_poprzedniej;
vector<int> dzielniki_pierwsze_vect;
vector<int> odtw_vect;
unordered_map<int, pair<int,int>> stat; // Dzielnik pierwszy, wynik max, idx wyniku.

vector<int> faktoryzacja(int x)
{
    vector<int> wyn_vect;
    for (int i = 0; i < P.size(); i+=0)
    {
        if (P[i] * P[i] > x)
            break;
        if (x % P[i] == 0)
        {
            wyn_vect.push_back(P[i]);
            x /= P[i];
        }
        else
            i++;
    }
    if (x != 1)
        wyn_vect.push_back(x);
    return wyn_vect;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sito.assign(sito_SIZE,false);
    for (int i = 2; i < sito_SIZE; ++i)
    {
        if (sito[i] == false)
        {
            P.push_back(i);
            for (int j = i * i; j < sito_SIZE; j += i)
                sito[j] = true;
        }
    }

    cin >> n;
    dp.assign(n,1);
    idx_poprzedniej.assign(n,-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    dzielniki_pierwsze_vect = faktoryzacja(liczby[0]);
    for (int i = 0; i < dzielniki_pierwsze_vect.size(); ++i)
        stat[dzielniki_pierwsze_vect[i]] = {1,0};

    for (int i = 1; i < n; ++i)
    {
        idx_pop = -1, max_wyn = 0;
        dzielniki_pierwsze_vect = faktoryzacja(liczby[i]);

        for (int j = 0; j < dzielniki_pierwsze_vect.size(); ++j)
        {
            if (auto it = stat.find(dzielniki_pierwsze_vect[j]) != stat.end())
            {
                if (stat[dzielniki_pierwsze_vect[j]].first > max_wyn)
                {
                    max_wyn = stat[dzielniki_pierwsze_vect[j]].first;
                    idx_pop = stat[dzielniki_pierwsze_vect[j]].second;
                }
            }
        }

        if (idx_pop == -1)
            dp[i] = 1;
        else
        {
            dp[i] = max_wyn + 1;
            idx_poprzedniej[i] = idx_pop;
        }

        for (int j = 0; j < dzielniki_pierwsze_vect.size(); ++j)
        {
            if (auto it = stat.find(dzielniki_pierwsze_vect[j]) == stat.end())
                stat[dzielniki_pierwsze_vect[j]] = {dp[i],i};
            else
            if (dp[i] > stat[dzielniki_pierwsze_vect[j]].first)
                stat[dzielniki_pierwsze_vect[j]] = {dp[i],i};
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (dp[i] > wynik)
        {
            wynik = dp[i];
            idx_wyn = i;
        }
    }

    while (true)
    {
        if (idx_wyn == -1)
            break;
        odtw_vect.push_back(idx_wyn);
        if (idx_poprzedniej[idx_wyn] == -1)
            break;
        idx_wyn = idx_poprzedniej[idx_wyn];
    }

    printf("%d\n",wynik);
    sort(odtw_vect.begin(),odtw_vect.end());
    for (int i = 0; i < odtw_vect.size(); ++i)
        printf("%d ",odtw_vect[i] + 1);

    return 0;
}
