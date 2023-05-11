#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

int n = 0, a = 0, b = 0, cnt = 0;
ll bilans = 0;
multiset<int> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        if (a == 0)
        {
            bilans += b;
            while(!S.empty())
            {
                if (bilans >= 0)
                    break;
                int val = *S.rbegin();
                bilans += val;
                S.erase(S.lower_bound(val));
            }
            if (bilans < 0)
            {
                cout << "-1" << '\n';
                return 0;
            }
        }
        else
        {
            if (b <= 0)
            {
                cnt++;
                bilans += abs(b);
            }
            else
            {
                if (bilans >= b)
                {
                    S.insert(b);
                    bilans -= b;
                }
                else if (!S.empty() and *S.rbegin() > b)
                {
                    bilans += *S.rbegin();
                    S.erase(S.lower_bound(*S.rbegin()));
                    S.insert(b);
                    bilans -= b;
                }
            }
        }
    }

    cout << S.size() + cnt << '\n';

    return 0;
}
