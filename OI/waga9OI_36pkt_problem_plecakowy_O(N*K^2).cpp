#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n = 0, wczytana_liczba = 0;
int MAX_DP_SIZE = 0;
vector<int> liczby;
vector<int> wyn1;
vector<int> wyn2;
set<int> idxy_dp;
vector<int> dod;

int main()
{
    // O(N * K^2), problem plecakowy, dla kazdej sumy jaka mozemy ulozyc wywalamy elementy, ktorymi mozna ja ulozyc i znowu odpalamy dynamika, plecak
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        MAX_DP_SIZE += wczytana_liczba;
    }

    MAX_DP_SIZE++;
    bool dp1[MAX_DP_SIZE] = {false};
    int idx_poprzedniego[MAX_DP_SIZE] = {-1};

    dp1[0] = true;
    idxy_dp.insert(0);

    for (int i = 0; i < n; ++i)
    {
        for (auto it = idxy_dp.rbegin(); it != idxy_dp.rend(); ++it)
        {
            if (*it + liczby[i] <= MAX_DP_SIZE)
            {
                if (dp1[*it+liczby[i]] == false)
                {
                    dp1[*it+liczby[i]] = true;
                    idx_poprzedniego[*it+liczby[i]] = *it;
                    dod.push_back(*it+liczby[i]);
                }
            }
        }
        if (*idxy_dp.begin() + liczby[i] <= MAX_DP_SIZE)
        {
            if (dp1[*idxy_dp.begin()+liczby[i]] == false)
            {
                dp1[*idxy_dp.begin()+liczby[i]] = true;
                idx_poprzedniego[*idxy_dp.begin()+liczby[i]] = *idxy_dp.begin();
                dod.push_back(*idxy_dp.begin()+liczby[i]);
            }
        }
        while(!dod.empty())
        {
            idxy_dp.insert(dod.back());
            dod.pop_back();
        }
    }

    for (int i = MAX_DP_SIZE / 2; i >= 1; --i)
    {
        if (dp1[i] == true)
        {
            wyn1.clear();
            wyn2.clear();
            int wsk = i;
            while(true)
            {
                if (idx_poprzedniego[wsk] == -1)
                    break;
                wyn1.push_back(wsk - idx_poprzedniego[wsk]);
                wsk = idx_poprzedniego[wsk];
            }

            bool dp2[MAX_DP_SIZE] = {false};
            int idx_poprzedniego2[MAX_DP_SIZE] = {-1};
            dp2[0] = true;

            int wystapienia[MAX_DP_SIZE] = {0};
            for (int j = 0; j < wyn1.size(); ++j)
                wystapienia[wyn1[j]]++;

            idxy_dp.clear();
            idxy_dp.insert(0);

            for (int j = 0; j < n; ++j)
            {
                if (wystapienia[liczby[j]] > 0)
                    wystapienia[liczby[j]]--;
                else
                {
                    for (auto it = idxy_dp.rbegin(); it != idxy_dp.rend(); ++it)
                    {
                        if (*it + liczby[i] <= MAX_DP_SIZE)
                        {
                            if (dp2[*it+liczby[i]] == false)
                            {
                                dp2[*it+liczby[i]] = true;
                                idx_poprzedniego[*it+liczby[i]] = *it;
                                dod.push_back(*it+liczby[i]);
                            }
                        }
                    }
                    if (*idxy_dp.begin() + liczby[i] <= MAX_DP_SIZE)
                    {
                        if (dp2[*idxy_dp.begin()+liczby[i]] == false)
                        {
                            dp2[*idxy_dp.begin()+liczby[i]] = true;
                            idx_poprzedniego[*idxy_dp.begin()+liczby[i]] = *idxy_dp.begin();
                            dod.push_back(*idxy_dp.begin()+liczby[i]);
                        }
                    }
                    while(!dod.empty())
                    {
                        idxy_dp.insert(dod.back());
                        dod.pop_back();
                    }
                }
            }

            if (dp2[i] == true)
            {
                int wsk = i;
                while(true)
                {
                    if (idx_poprzedniego2[wsk] == -1)
                        break;
                    wyn2.push_back(wsk - idx_poprzedniego2[wsk]);
                    wsk = idx_poprzedniego2[wsk];
                }
                cout << wyn1.size() << " " << wyn2.size() << '\n';
                for (int j = 0; j < wyn1.size(); ++j)
                    cout << wyn1[j] << " ";
                cout << endl;
                for (int j = 0; j < wyn2.size(); ++j)
                    cout << wyn2[j] << " ";
                return 0;
            }
        }
    }

    cout << "0" << '\n';

    return 0;
}