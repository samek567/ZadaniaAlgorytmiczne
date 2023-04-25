#include <iostream>

using namespace std;

int n = 0;
int dystans[200][200];
bool czy_pasuje = true;

int main()
{
    // Zachlan.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dystans[i][j];

    for (int i = 0; i < n; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            czy_pasuje = true;
            for (int k = 0; k < n; ++k)
            {
                if (k != i && k != j)
                {
                    if (dystans[i][k] + dystans[k][j] == dystans[i][j])
                    {
                        czy_pasuje = false;
                        break;
                    }
                }
            }
            if (czy_pasuje == true)
                printf("%d %d\n",i+1,j+1);
        }
    }

    return 0;
}