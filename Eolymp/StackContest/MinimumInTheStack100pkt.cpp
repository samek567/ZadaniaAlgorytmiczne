#include <iostream>
#include <stack>

using namespace std;

int n = 0, a = 0, b = 0;
stack<int> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (a == 3)
            cout << S.top() << '\n';
        else if (a == 1)
        {
            cin >> b;
            if (S.empty())
                S.push(b);
            else
                S.push(min(S.top(),b));
        }
        else
            S.pop();
    }

    return 0;
}
