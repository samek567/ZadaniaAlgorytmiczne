#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytany_sasiad = 0, ktory_kolor = 1;
vector<int> sasiedzi, cykle;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    cykle.assign(n+1,0);

    sasiedzi.push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> wczytany_sasiad;
        sasiedzi.push_back(wczytany_sasiad);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (cykle[i] != 0)
        {
            continue;
        }
        int sprawdzany_idx = i;
        while(cykle[sprawdzany_idx] == 0)
        {
            cykle[sprawdzany_idx] = ktory_kolor;
            sprawdzany_idx = sasiedzi[sprawdzany_idx];
        }
        ktory_kolor++;
    }

    cout << ktory_kolor - 1;

    return 0;
}