#include <iostream>

using namespace std;

int n = 0, h = 0, wynik = 0, zagniezdzenia = 0, s = 0;
char wczytany_nawias;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_nawias;
        if (wczytany_nawias == '(')
        {
            if (s + 1 > h)
            {
                s--;
                wynik++;
            }
            else
            {
                s++;
            }
        }
        else
        {
            if (s - 1 < 0)
            {
                s++;
                wynik++;
            }
            else
            {
                s--;
            }
        }
    }


    cout << wynik << "\n";

    return 0;
}