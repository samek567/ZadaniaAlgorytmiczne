#include <iostream>
#include <vector>

using namespace std;

int a = 0, b = 0, sito_size = 10001;
vector<bool> sito(sito_size,false);
vector<int> P;

int faktoryzacja_ile(int x)
{
    int wynn = 0;
    for (int i = 0; i < P.size(); i += 0)
    {
        if (P[i] * P[i] > x)
            break;
        if (x % P[i] == 0)
        {
            x /= P[i];
            wynn++;
        }
        else
            i++;
    }
    if (x != 1)
        wynn++;
    return wynn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < sito_size; ++i)
    {
        if (sito[i] == false)
        {
            P.push_back(i);
            for (int j = i * i; j < sito_size; j += i)
                sito[j] = true;
        }
    }

    cin >> a >> b;
    for (int i = a; i <= b; ++i)
    {
        printf("%d ", faktoryzacja_ile(i));
    }

    return 0;
}