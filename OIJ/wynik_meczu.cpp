#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ciag;
    long long licznik_a = 0;
    long long licznik_b = 0;

    cin >> ciag;

    for (int i = 0; i < ciag.size(); ++i)
    {
        if (ciag[i] == 'A')
        {
            licznik_a++;
        }
        else
        {
            licznik_b++;
        }
    }

    //cout << licznik_a << " : " << licznik_b;
    printf("%lld : %lld",licznik_a,licznik_b);

    return 0;
}