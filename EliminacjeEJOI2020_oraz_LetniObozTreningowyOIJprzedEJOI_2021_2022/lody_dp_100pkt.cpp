#include <iostream>
#include <vector>

using namespace std;

int n = 0;
string ciag;
vector<int> dp_W;
vector<int> dp_C;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;

    dp_W.assign(n,1e9);
    dp_C.assign(n,1e9);

    if (ciag[0] == 'V')
    {
        dp_W[0] = 1;
        dp_C[0] = 2;
    }
    else
    {
        dp_W[0] = 3;
        dp_C[0] = 2;
    }

    for (int i = 1; i < n; ++i)
    {
        if (ciag[i] == 'V')
        {
            dp_W[i] = dp_W[i-1] + 1;
            dp_W[i] = min(dp_W[i], dp_C[i-1] + 1 + 1);
            dp_C[i] = dp_C[i-1] + 2;
            dp_C[i] = min(dp_C[i], dp_W[i-1] + 2);
        }
        else
        {
            dp_C[i] = dp_C[i-1] + 2;
            dp_C[i] = min(dp_C[i], dp_W[i-1] + 1 + 2);
            dp_W[i] = dp_W[i-1] + 4;
            dp_W[i] = min(dp_W[i], dp_C[i-1] + 3);
        }
    }

    cout << min(dp_C[n-1],dp_W[n-1]) << '\n';

    return 0;
}
