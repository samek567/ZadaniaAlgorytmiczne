#include <iostream>

using namespace std;

long long a = 0, b = 0, z = 0;
int wyn = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    while (a != b)
    {
        if (a > b)
            a /= 2;
        else
            b /= 2;
        wyn++;
    }
    printf("%d",wyn);

    return 0;
}
