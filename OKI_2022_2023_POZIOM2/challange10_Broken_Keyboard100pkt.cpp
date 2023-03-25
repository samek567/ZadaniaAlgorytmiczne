#include <iostream>

using namespace std;

int t = 0, n = 0;
string ciag;
bool czy_jeden_znak = true;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> ciag;
        czy_jeden_znak = true;
        bool czy_tak = true;
        for (int j = 0; j < n; ++j)
        {
            if (czy_jeden_znak == false)
            {
                if (j == n-1)
                {
                    czy_tak = false;
                    break;
                }
                else if (ciag[j] != ciag[j+1])
                {
                    czy_tak = false;
                    break;
                }
                j++;
            }
            czy_jeden_znak = !czy_jeden_znak;
        }
        if (czy_tak == true)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}