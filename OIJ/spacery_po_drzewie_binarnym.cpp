#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    long long a = 0;
    long long b = 0;
    long long licznik = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        licznik = 0;
        cin >> a >> b;

        while (a != b)
        {
            if (a > b)
            {
                a /= 2;
            }
            else
            {
                b /= 2;
            }
            licznik++;
        }
        printf("%lld \n",licznik);
    }



    return 0;
}