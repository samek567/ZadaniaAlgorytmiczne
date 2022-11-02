#include <iostream>

using namespace std;

int q = 0, wynik = 0;
long long a = 0, b = 0;

int main()
{
    // O(log(a) + log(b))
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        cin >> a >> b;
        wynik = 0;

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
            wynik++;
        }

        cout << wynik << "\n";
    }
    return 0;
}
