#include <iostream>

using namespace std;

long long q = 0, a = 0, b = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> a >> b;
        int wyn = 0;

        while (a != b)
        {
            if (a > b)
                a /= 2;
            else
                b /= 2;
            wyn++;
        }

        printf("%d\n",wyn);
    }
    return 0;
}