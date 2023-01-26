#include <iostream>

using namespace std;

int n = 0;

int licz_dzielniki(int x)
{
    int wyn = 0;
    for (int i = 1; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            wyn += i;
            if (x % i != x / i)
                wyn += x / i;
        }
    }
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    printf("%d",licz_dzielniki(n));

    return 0;
}