#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n = 0, wczytana_liczba = 0, min_idx = -1, min_dp = -1, wyn = 0, wyn_idx = 0;
vector<bool> sito(1e6+1,false);
vector<int> P;
vector<int> liczby;
vector<vector<int>> faktoryzowane;

int odleglosc(int x, int y)
{
    int L_x = liczby[x], L_y = liczby[y], wyn = 0, wsk_y = 0;
    if (L_x == 1 && L_y == 1)
        return 0;
    else if (L_x == 1)
        return faktoryzowane[y].size();
    else if (L_y == 1)
        return faktoryzowane[x].size();
    for (int i = 0; i < faktoryzowane[x].size(); ++i)
    {
        if (wsk_y == faktoryzowane[y].size())
        {
            wyn += faktoryzowane[x].size() - i;
            break;
        }
        if (faktoryzowane[x][i] == faktoryzowane[y][wsk_y])
            wsk_y++;
        else if (faktoryzowane[x][i] < faktoryzowane[y][wsk_y])
            wyn++;
        else if (faktoryzowane[x][i] > faktoryzowane[y][wsk_y])
        {
            wyn++;
            wsk_y++;
            i--;
        }
    }

    return wyn + (faktoryzowane[y].size() - wsk_y);
}

int main()
{
    // O(N^2 * lg N + 168 * N), 168 * N, to koszt faktoryzacji
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (ll i = 2; i <= (ll)1e6; ++i)
    {
        if (sito[i] == false)
        {
            P.push_back(i);
            for (ll j = i * i; j <= 1e6; j += i)
                sito[j] = true;
        }
    }

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        faktoryzowane.push_back({});
        for (int j = 0; j < P.size(); j+=0)
        {
            if (P[j] * P[j] > wczytana_liczba)
                break;
            if (wczytana_liczba % P[j] == 0)
            {
                faktoryzowane[i].push_back(P[j]);
                wczytana_liczba /= P[j];
            }
            else
                j++;
        }
        if (wczytana_liczba != 1)
            faktoryzowane[i].push_back(wczytana_liczba);
        sort(faktoryzowane[i].begin(),faktoryzowane[i].end());
    }
    for (int i = 0; i < n; ++i)
    {
        wyn = 1e9, wyn_idx = 1e9;
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;
            int odl = odleglosc(i,j);
            if (odl != -1)
            {
                if (odl < wyn)
                {
                    wyn = odl;
                    wyn_idx = j;
                }
            }
        }
        cout << wyn_idx+1 << '\n';
    }

    return 0;
}