#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int k = 0, n = 0;
bool czy_mamy = false;
string res;
vector<int> dp;
vector<int> idx_poprzedniej;
queue<int> Q;

int main()
{
    // O(N*K), ten sam kod co zadanie zera i jedynki 2
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;

    while(k--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << '1' << '\n';
            continue;
        }
        czy_mamy = false;
        dp.assign(n,-1);
        idx_poprzedniej.assign(n,-1);
        Q = queue<int>();
        dp[1] = 1;
        Q.push(1);
        while(!Q.empty())
        {
            int v = Q.front(), val = (v * 10) % n;
            Q.pop();

            if (dp[val] == -1)
            {
                dp[val] = dp[v] + 1;
                idx_poprzedniej[val] = v;
                Q.push(val);
            }
            if (val == 0)
            {
                czy_mamy = true;
                break;
            }

            val = (v * 10 + 1) % n;
            if (dp[val] == -1)
            {
                dp[val] = dp[v] + 1;
                idx_poprzedniej[val] = v;
                Q.push(val);
            }
            if (val == 0)
            {
                czy_mamy = true;
                break;
            }
        }
        if (czy_mamy == false)
            cout << "BRAK" << '\n';
        else
        {
            res.clear();
            int v = 0;
            while(idx_poprzedniej[v] != -1)
            {
                int wierz = idx_poprzedniej[v];
                if ((wierz * 10) % n == v)
                    res.push_back('0');
                else
                    res.push_back('1');
                v = wierz;
            }
            res.push_back('1');
            for (int i = res.size()-1; i >= 0; --i)
                cout << res[i];
            cout << '\n';
        }
    }

    return 0;
}
