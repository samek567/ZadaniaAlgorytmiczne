#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int t = 0, n = 0, m = 0;
ll wyn = 0, sum = 0;
vector<vector<int>> A;
vector<int> liczby;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        wyn = 0;
        A.assign(n,{});
        for (int i = 0; i < n; ++i)
        {
            A[i].assign(m,-1);
            for (int j = 0; j < m; ++j)
                cin >> A[i][j];
        }
        for (int i = 0; i < m; ++i)
        {
            liczby.clear();
            for (int j = 0; j < n; ++j)
                liczby.push_back(A[j][i]);
            sort(liczby.begin(),liczby.end());
            sum = 0;
            for (int j = 0; j < n; ++j)
            {
                wyn += (ll)j * (ll)liczby[j] - sum;
                sum += liczby[j];
            }
        }
        cout << wyn << '\n';
    }

    return 0;
}
