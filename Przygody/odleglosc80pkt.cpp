#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

struct Element_kolejki
{
    int wierzcholek;
    int jaki_poczatek;
};

int n = 0, wczytana_liczba = 0, wierzcholki_SIZE = 0;
vector<int> zapytania;
vector<int>sito;
vector<pair<int,int>> dp; // Wartosc dp i jaki numer tam jest
vector<vector<int>> krawedzie;
vector<pair<int,int>> wyniki; // Wynik, numer wierzcholka
queue<Element_kolejki> Q;
vector<pair<int,int>> stat;
vector<int> faktoryzowane;

int main()
{
    // O(N*lg(N) + N) Faktoryzacja z sitem + BFS. Mamy graf o 10^6 wierzcholkach i maksymalnie 16*10^6 wierzcholkach.
    // Kod na szkopule wchodzi na 80pkt, ale limity sa tak dobrane, ze jedna z wzorcowek na stronie OI, tez wchodzi na 80pkt,
    // ktos musial kiepskie limity ustawic. Czas sie juz przekracza, na etapie faktoryzacji i dodania krawedzi.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        wierzcholki_SIZE = max(wierzcholki_SIZE,wczytana_liczba);
        zapytania.push_back(wczytana_liczba);
    }

    stat.assign(wierzcholki_SIZE+1,{-1,-1});
    for (int i = 0; i < n; ++i)
    {
        if (stat[zapytania[i]].first == -1)
            stat[zapytania[i]].first = i+1;
        else if (stat[zapytania[i]].second == -1)
            stat[zapytania[i]].second = i+1;
    }

    krawedzie.assign(wierzcholki_SIZE+1,{});
    sito.assign(wierzcholki_SIZE+1,0);
    for (int i = 2; i * i <= wierzcholki_SIZE; ++i)
    {
        if (sito[i] == 0)
            for (int j = i * i; j <= wierzcholki_SIZE; j += i)
                if (sito[j] == 0)
                    sito[j] = i;
    }
    int spr = 0;
    for (int i = 1; i <= wierzcholki_SIZE; ++i)
    {
        spr = i;
        faktoryzowane.clear();
        while (sito[spr] > 0)
        {
            if (faktoryzowane.size() == 0)
                faktoryzowane.push_back(sito[spr]);
            else if (faktoryzowane[faktoryzowane.size()-1] != sito[spr])
                faktoryzowane.push_back(sito[spr]);
            spr /= sito[spr];
        }
        for (int j = 0; j < faktoryzowane.size(); ++j)
        {
            krawedzie[i].push_back(i/faktoryzowane[j]);
            krawedzie[i/faktoryzowane[j]].push_back(i);
        }
        if (faktoryzowane.size() == 0)
        {
            krawedzie[i].push_back(i/spr);
            krawedzie[i/spr].push_back(i);
        }
        else if (faktoryzowane[faktoryzowane.size()-1] != spr)
        {
            krawedzie[i].push_back(i/spr);
            krawedzie[i/spr].push_back(i);
        }
    }
    dp.assign(wierzcholki_SIZE+1,{-1,-1});
    wyniki.assign(wierzcholki_SIZE+1,{1e9,-1});
    for (int i = 0; i < zapytania.size(); ++i)
    {
        if (dp[zapytania[i]].first == -1)
        {
            Q.push({zapytania[i],i});
            dp[zapytania[i]] = {0,i};
        }
    }

    while(!Q.empty())
    {
        Element_kolejki spr = Q.front();
        for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
        {
            int v = krawedzie[spr.wierzcholek][i];
            if (dp[v].first == -1)
            {
                dp[v] = {dp[spr.wierzcholek].first + 1,spr.jaki_poczatek};
                Q.push({v,spr.jaki_poczatek});
            }
            else
            {
                if (dp[spr.wierzcholek].second != dp[v].second)
                {
                    if (wyniki[zapytania[spr.jaki_poczatek]].first > dp[spr.wierzcholek].first + dp[v].first + 1)
                        wyniki[zapytania[spr.jaki_poczatek]] = {dp[spr.wierzcholek].first + dp[v].first + 1,dp[v].second};
                    else if (wyniki[zapytania[spr.jaki_poczatek]].first == dp[spr.wierzcholek].first + dp[v].first + 1)
                        wyniki[zapytania[spr.jaki_poczatek]].second = min(wyniki[zapytania[spr.jaki_poczatek]].second,dp[v].second);
                }
            }
        }
        Q.pop();
    }

    for (int i = 0; i < n; ++i)
    {
        if (stat[zapytania[i]].second != -1)
        {
            if (stat[zapytania[i]].first == i+1)
                cout << stat[zapytania[i]].second << '\n';
            else
                cout << stat[zapytania[i]].first << '\n';
        }
        else
            cout << wyniki[zapytania[i]].second + 1 << '\n';
    }

    return 0;
}