#include <iostream>
#include <vector>

using namespace std;

int n = 0, wyn = 0;
string ciag;
vector<bool> stat(500,false);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;
    for (int i = 0; i < n; ++i)
    {
        if ((int)ciag[i] >= 97) // jest mala litera.
        {
            if (stat[(int)ciag[i] - 32] == true)
                wyn++;
        }
        else
        {
            if (stat[(int)ciag[i] + 32] == true)
                wyn++;
        }
        stat[(int)ciag[i]] = true;
    }
    printf("%d",wyn);
    return 0;
}