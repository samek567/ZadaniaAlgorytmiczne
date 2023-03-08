#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;

int n = 0;
ll wyn = 0;
vector<int> liczby;
stack<int> S;

int main()
{
    // O(N), stos monotonniczny, zadanie ala plakatowanie z OI / dzialka z OI
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    liczby.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];

    S.push(liczby[0]);

    for (int i = 1; i < n; ++i)
    {
        while(!S.empty())
        {
            wyn++;
            if (liczby[i] > S.top())
                S.pop();
            else if (liczby[i] == S.top())
            {
                S.pop();
                break;
            }
            else
                break;
        }
        S.push(liczby[i]);
    }

    cout << wyn << '\n';

    return 0;
}
