#include <iostream>
#include <stack>

using namespace std;

int n = 0;
bool czy_dobry = true;
string nawias;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        stack<char> S;
        czy_dobry = true;

        cin >> nawias;
        for (int j = 0; j < nawias.size(); ++j)
        {
            if (nawias[j] == '(' || nawias[j] == '[' || nawias[j] == '{')
                S.push(nawias[j]);
            else if (S.empty())
            {
                czy_dobry = false;
                break;
            }
            else if (nawias[j] == ')')
            {
                if (S.top() != '(')
                {
                    czy_dobry = false;
                    break;
                }
                S.pop();
            }
            else if (nawias[j] == ']')
            {
                if (S.top() != '[')
                {
                    czy_dobry = false;
                    break;
                }
                S.pop();
            }
            else if (nawias[j] == '}')
            {
                if (S.top() != '{')
                {
                    czy_dobry = false;
                    break;
                }
                S.pop();
            }
        }
        if (!S.empty())
            czy_dobry = false;

        if (czy_dobry == true)
            printf("TAK\n");
        else
            printf("NIE\n");
    }
    return 0;
}
