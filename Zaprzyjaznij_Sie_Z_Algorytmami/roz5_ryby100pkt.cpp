#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n = 0, wczytana_liczba = 0, wyn = 0;
vector<int> wysokosci;
stack<int> S;

int main()
{
    /*
     O(n), bo kazdy element maksymalnie raz dodamy i raz zdejmniemy.
     1 - na wschod
     0 - na zachod
     */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        wysokosci.push_back(wczytana_liczba);
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (S.empty())
        {
            if (wczytana_liczba == 0)
                wyn++;
            else
                S.push(wysokosci[i]);
        }
        else
        {
            if (wczytana_liczba == 1)
                S.push(wysokosci[i]);
            else
            {
                while (!S.empty())
                {
                    if (S.top() > wysokosci[i])
                        break;
                    else
                        S.pop();
                }
                if (S.empty())
                    wyn++;
            }
        }
    }

    printf("%d",wyn+S.size());
    return 0;
}
